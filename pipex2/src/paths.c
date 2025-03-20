#include "pipex.h"

char *get_command_path(char *cmd, char **envp)
{
    int i = 0;
    char **paths;
    char *full_path;
    while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
        i++;
    if (!envp[i])
        return (NULL);
    paths = ft_split(envp[i] + 5, ':'); // Implementar ft_split si usas libft
    for (int j = 0; paths[j]; j++)
    {
        full_path = ft_strjoin(paths[j], "/");
        full_path = ft_strjoin(full_path, cmd);
        if (access(full_path, X_OK) == 0)
            return (full_path);
        free(full_path);
    }
    return (NULL);
}
