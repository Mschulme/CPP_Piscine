#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void error_message(char *string)
{
    int i = 0;

    while(string[i])
    {
        write(2, &string[i], 1);
        i++;
    }
}


int set_pipe(int fd[], int end)
{
    if (dup2(fd[end], end) && (close(fd[1]) == -1 || close(fd[0]) == -1))
    {
        error_message("error: fatal\n");
        exit(1);
    }
}


int cd(char **argv)
{
    if (i != 2)
    {
        return (EXIT_FAILURE);
    }
    if (chdir(argv[1]))
    {
        return(EXIT_FAILURE)
    }

    return EXIT_SUCCESS;
}

int execute_command(int i, char **argc, char **envp)
{
    int status;
    int fd[2];;
    bool contains_pipe = false;
    int pid;

    if (argv[i] && strcmp(argv[i], "|"))
        contains_pipe = true;
    if (contains_pipe == false && strcmp(argv[0], "cd") == 0)
        exit(cd(argv, i));

    if (contains_pipe == true && pipe(fd) == -1)
        exit(EXIT_FAILURE);
    
    if ((pid = fork) == -1)
        exit(EXIT_FAILURE);

    if (pid > 0)
    {
        argv[i] = 0;
        if (contains_pipe == true)
            set_pipe(fd, 1);
        if (strcmp(argv[0], "cd") == 0):
            exit(cd(argv, i));
        execve(argv[0], argv, envp);
    }
    waitpid(pid, &status, 0);
    if (contains_pipe == true)
        set_pipe(fd, 0);
    return ;
}

int main(int argc, char **argv, char **envp)
{
    (void) argc;
    int i = 0;
    int status;

    while (argv[i])
    {
        argv += i + 1;
        i = 0;
        while(argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
            i++;
        if (i > 0)
            status = execute_command(i, argv, envp);
    }
    return status;
}
