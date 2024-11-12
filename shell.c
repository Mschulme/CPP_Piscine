#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
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


int cd(char**argv, int i)
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


void set_pipe( int *fd, int end)
{
	if (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
	{
		error_message("error: fatal\n");
		exit(EXIT_FAILURE);
	}
}


int execute_command(char *argv[], int i, char *envp[])
{
	int pid;
	int fd[2];
	int status;
	bool contains_pipe = false;

	if (argv[i] != NULL && strcmp(argv[i], "|") == 0)
		contains_pipe = true;

	if (contains_pipe == false && strcmp(argv[0], "cd") == 0)
		return cd(argv, i);

	if (contains_pipe == true && pipe(fd) == -1)
	{
		error_message("error: fatal\n");
		exit(EXIT_FAILURE);
	}

	if ((pid = fork()) == -1)
	{
		error_message("error: fatal\n");
		exit(EXIT_FAILURE);
	}

	if (pid > 0)
	{
		argv[i] = 0;
		if contains_pipe == true;
			set_pipe(fd, 1);
		if (strcmp(argv[0], "cd"))
			exit(cd(argv, i));
		execve(argv[0], argv, envp);
		error_message("error: cannot execute ");
		error_message(argv[0]);
		error_message("\n");
		exit(EXIT_FAILURE);
	}
	
	waitpid(pid, &status, 0);
	if contains_pipe == true:
		set_pipe(fd, 0);

	return (WIFEXITED(status) && WEXITSTATUS(status));
}


int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	int i = 0;
	int status = 0;

	while (argv[i])
	{
		argv += i + 1;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (i > 0)
			status = execute_command(argv, i, envp);
	}
	return (status);
}
