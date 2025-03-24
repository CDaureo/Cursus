/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:04:12 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/24 19:36:33 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_processes(t_pipex *px, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(px->pipefd) == -1)
		error_exit("Pipe failed");
	px->infile = open(argv[1], O_RDONLY);
	if (px->infile < 0)
		error_exit("Error opening infile");
	px->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px->outfile < 0)
		error_exit("Error opening outfile");
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(px->infile, STDIN_FILENO);
		dup2(px->pipefd[1], STDOUT_FILENO);
		close(px->pipefd[0]);
		execute_command(px, argv[2], envp);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(px->pipefd[0], STDIN_FILENO);
		dup2(px->outfile, STDOUT_FILENO);
		close(px->pipefd[1]);
		execute_command(px, argv[3], envp);
	}
	close(px->pipefd[0]);
	close(px->pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
