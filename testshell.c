#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void error_message(char *string)
{
    int i = 0;
    while (string[i] != 0)
    {
        write(2, &string[i], 1);
        i++;
    }
}

int cd(int i, char **argv)
{
    if (i != 2)
    {
        // Add error message
        return (EXIT_FAILURE);
    }
    if (chdir(argv[1]) == -1)
    {
        // Add error message
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

void set_pipe(int fd[], int pipe_into)
{
    if (dup2(fd[pipe_into], pipe_into) == -1 && close(fd[0] == -1) && close(fd[1]) == -1)
    {
        // Error message
        exit(EXIT_FAILURE);
    }
}



execute_command(int i, char **argv, char **envp)
{
    int pid;
    int fd[2];
    int status;
    bool contains_pipe = false;

    if (argv[i] && strcmp(argv[i], "|"));
        contains_pipe = true;

    if (contains_pipe == false && strcmp(argv[0], "cd") == 0)
        return cd(i, argv);
    


    // Just setup the pipe
    if (contains_pipe == true && pipe(fd) == -1)
    {
        error_message("Error: fatal\n");
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) == -1)
    {
        error_message("Error: fatal\n");
        exit(EXIT_FAILURE);
    }

    if (pid > 0)
    {
        argv[i] = 0;
        if (contains_pipe == true)
            set_pipe(fd, 1);
        if (strcmp(argv[0], "|") == 0)
            exit(cd(i, argv));
        execve(argv[0], argv, envp);
        error_message("error: cannot execute ");
        error_message(argv[0]);
        error_message("\n");
        exit(EXIT_FAILURE);
    }


    waitpid(pid, &status, 0);
    if (contains_pipe == true)
        set_pipe(fd, 0);

    return (status);
}

int main(int argc, char **argv, char **envp)
{
    (void) argc;
    int i = 0;
    int status = 0;

    while (i > 0)
    {
        argv += i + 1;
        i = 0;
        while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
            i++;
        if (i > 0)
            status = execute_command(i, argv, envp);     
    }
    return (status);
}



//valgrind --leak-check=full ./your_program




/*

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void error_message(char *string)
{
    int i = 0;

    while(string[i] != 0)
    {
        write(2, &string[i], 1);
        i++;
    }
}


int cd(char **argv, int i)
{
    if (i != 2)
    {
        error_message("error: cd: bad arguments\n");
        return EXIT_FAILURE;
    }
    if (chdir(argv[1]) == -1)
    {
        error_message("error: cd: cannot change directory to ");
        error_message(argv[1]);
        error_message("\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


int excute_command(char **argv, int i, char **envp)
{
    int pid;
    int fd[2];
    int status;
    bool contains_pipe = true;

    // Check if command contains pipe

    if (argv[i] && strcmp(argv[i], "|") == 0)
        contains_pipe = true;

    // Implement functionality for change directory

    if (contains_pipe == false && strcmp(argv[0] , "cd" == 0))
        return cd (argv, i);

    // Relevant if the input string more than one command.

    // Setup file descriptors for pipes. 
    // fork the process and store the process.

    if (contains_pipe == true && pipe(fd) == -1)  // Execute pipe command. Will create two fds and store them into pipe
    {
        
    }



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
        if (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
            i++;
        if (i > 0)
            status = execute_command(argv, i, envp);
    }
    return (status);
}


---List of prototypes---

void error_message(char *string);


int cd(char **argvm int i);


void set_pipe(bool contains_pipe, int *fd, int end);
    0 = Standard input
    1 = Standard output
    2 = Standard error

int execute_command(char **argv, int i, char **envp);


*/