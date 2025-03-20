/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:04:06 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/20 22:46:47 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	c_pipex px;

	if (argc != 5)
		error_exit("Usage is: ./pipex infile \"cmd1\" \"cmd2\" outfile");
		
		px.envp = envp;		
		handle_processes(&px, argv, envp);		
		return (0);
}
