/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:28:18 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/17 17:03:29 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

static void fork2(int pipe_fd[2], int *file, char **envelope, char *argv)
{
	int infile;
	int outfile;
	infile = file[0];
	outfile = file[1];
	close(infile);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1 || dup2(outfile, STDOUT_FILENO) == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(outfile);
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (outfile >= 0)
		close(outfile);
	executer(argv, envelope);
}


static void fork1(int pipe_fd[2], int *file, char **envelope, char *argv)
{
	int infile;
	int outfile;
	infile = file[0];
	outfile = file[1];
	close(outfile);
	if (dup2(infile, STDIN_FILENO) == -1 || dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(infile);
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (infile >= 0)
		close(infile);
	executer(argv, envelope);
}

static int pipex(int infile, int outfile, char **envelope, char **argv)
{
	int pipe_fd[2];
	int	file[2];
	pid_t pid1;
	pid_t pid2;
	
	file[0] = infile;
	file[1] = outfile;
	if (pipe(pipe_fd) == -1)
		return(EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == -1)
		return(EXIT_FAILURE);
	if (pid1 == 0)
		fork1(pipe_fd, file, envelope , argv[2]);
	pid2 = fork();
	if (pid2 == -1)
		return(EXIT_FAILURE);
	if (pid2 == 0)
		fork2(pipe_fd, file, envelope,argv[2]);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
	
}
int main (int argc, char  **argv, char **envelope)
{
	int infile;
	int outfile;
	int	return_code;
	if (argc != 5)
		return EXIT_FAILURE;
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		perror(argv[1]);
	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (outfile < 0)
	{
		perror(argv[4]);
		pipex(infile,outfile,envelope, argv);
		close(infile);
		exit(EXIT_FAILURE);
	}
	return_code = pipex(infile,outfile, envelope, argv);
	if (infile > 0)
		close(infile);
	if (outfile > 0)
		close(outfile);
	return (return_code);
	
	
}