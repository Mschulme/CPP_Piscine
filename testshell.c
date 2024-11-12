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







/*

---List of prototypes---

void error_message(char *string);


int cd(char **argvm int i);


void set_pipe(bool contains_pipe, int *fd, int end);
    0 = Standard input
    1 = Standard output
    2 = Standard error

int execute_command(char **argv, int i, char **envp);
*/