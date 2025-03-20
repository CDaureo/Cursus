/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:04:15 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/20 22:47:10 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(c_pipex *px, char *cmd, char **envp)
{
	px->cmd_args = ft_split(cmd, ' ');
	px->cmd = get_command_path(px->cmd_args[0], envp);
	if (!px->cmd)
	{
		free_pipex(px);
		error_exit("Command not found");
		exit(EXIT_FAILURE);
	}
	execve(px->cmd, px->cmd_args, envp);
	free_pipex(px);
	error_exit("Execve failed");
}
