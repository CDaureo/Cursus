/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:28:18 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/11 16:42:54 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"
int	main(int argc, char **argv)
{
		
	if (argc != 5)
	{
		printf("Uso: %s <archivo>\n", argv[0]);
		return (1);
	}
	char *path_infile = argv [1];
	char *path_outfile = argv [4];
	if(access(path_infile, F_OK) != 0)
	{
		printf("No existe\n");
	}
	if (access(path_outfile, F_OK) != 0)
	{
		printf("Entro\n");
		open(path_outfile, O_CREAT | O_WRONLY, 0644);
	}		
}