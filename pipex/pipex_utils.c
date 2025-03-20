/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:09:24 by cdaureo-          #+#    #+#             */
/*   Updated: 2025/03/17 17:11:41 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

char	*joiner(const char *path, const char *cmd)
{
	char	*joined;
	size_t	len;
	char	*slash;
	char	*f_path;

	slash = "";
	if (!path || !cmd)
		return (NULL);
	len = ft_strlen(path);
	if (path[len - 1] != '/')
		slash = "/";
	joined = ft_strjoin(path, slash);
	if (!joined)
		return (NULL);
	f_path = ft_strjoin(joined, cmd);
	free(joined);
	if (!f_path)
		return (NULL);
	return (f_path);
}

char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) == envp[i])
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_cmd(char *cmd, char **envp)
{
	const char	*path_env = get_path(envp);
	char		**path;
	char		*f_path;
	int			i;

	if (!cmd || !*cmd || !envp)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	if (!path_env)
		return (NULL);
	path = ft_split(path_env, ':');
	if (!path)
		return (NULL);
	f_path = NULL;
	i = -1;
	while (path[++i])
	{
		f_path = joiner(path[i], cmd);
		if (!f_path || (access(f_path, X_OK) == 0))
			break ;
		free(f_path);
		f_path = NULL;
	}
	return (free_split(path), f_path);
}

char	**cleaner(char **argv, char **path, char **envp)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		argv[i] = ft_cleaner(argv[i], "\"'");
		if (!argv[i])
			return (NULL);
		i++;
	}
	*path = find_cmd(argv[0], envp);
	if (!*path)
	{
		if (ft_strchr(argv[0], '/'))
			perror(argv[0]);
		free_split(argv);
		exit(127);
	}
	return (argv);
}

void	executer(char *cmd, char **envp)
{
	char	**argv;
	char	*path;

	if (!cmd || !*cmd)
		exit(127);
	argv = ft_split(cmd, ' ');
	if (!argv || !argv[0])
	{
		free_split(argv);
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	argv = cleaner(argv, &path, envp);
	execve(path, argv, envp);
	perror(path);
	free_split(argv);
	free(path);
}