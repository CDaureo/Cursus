#include "pipex.h"

void execute_command(t_pipex *px, char *cmd, char **envp)
{
    px->cmd_args = ft_split(cmd, ' '); // Implementar ft_split si usas libft
    px->cmd = get_command_path(px->cmd_args[0], envp);
    if (!px->cmd)
    {
        free_pipex(px);
        error_exit("Command not found");
    }
    execve(px->cmd, px->cmd_args, envp);
    free_pipex(px);
    error_exit("Execve failed");
}
