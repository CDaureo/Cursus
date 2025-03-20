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

typedef struct s_pipex
{
    int     infile;
    int     outfile;
    int     pipefd[2];
    char    **cmd_paths;
    char    **cmd_args;
    char    *cmd;
    char    **envp;
}   c_pipex;

void    execute_command(c_pipex *px, char *cmd, char **envp);
void    free_pipex(c_pipex *px);
void    error_exit(const char *msg);
char    *get_command_path(char *cmd, char **envp);
void    handle_processes(c_pipex *px, char **argv, char **envp);
char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
