/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:47:30 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/24 19:37:08 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

typedef struct t_pipex
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
	char	**envp;
}	t_pipex;

/******************************************************************
*							MAIN								  *
*******************************************************************/
void	execute_command(t_pipex *px, char *cmd, char **envp);
char	*get_command_path(char *cmd, char **envp);
void	handle_processes(t_pipex *px, char **argv, char **envp);

/******************************************************************
*							UTILS								  *
*******************************************************************/
void	free_pipex(t_pipex *px);
void	error_exit(const char *msg);

/******************************************************************
*							FUNCTIONS							  *
*******************************************************************/
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
