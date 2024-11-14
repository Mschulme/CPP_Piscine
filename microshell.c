#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>

void error_message(char *string)
{
	int i = 0;

	while(string[i] != 0)
	{
		write(STDERR_FILENO, &string[i], 1);
		i++;
	}
}


void set_pipe(int fd[], int end)
{	if (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
	{
		error_message("error: fatal\n");
		exit(EXIT_FAILURE);
	}
}


int cd(char **argv, int i)
{
	if (i != 2)
	{
		error_message("Wrong number of arguments\n");
		return (EXIT_FAILURE);
	}
	if (chdir(argv[1]) == -1)
	{
		error_message(argv[1]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}


int execute_command(int i, char **argv, char **envp)
{
	int pid;
	int status;
	int fd[2];
	bool contains_pipe = false;

	if (argv[i]  && strcmp(argv[i], "|") == 0)
		contains_pipe = true;

	if (contains_pipe = false && strcmp(argv[0], "cd"))
		exit(cd(argv, i));

	if (contains_pipe = true && pipe(fd) == -1)
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
		if (contains_pipe == true)
			set_pipe(fd, STDOUT_FILENO);
		if (strcmp(argv[0], "cd") == 0)
			exit(cd(argv, i));
	
		status = execve(argv[0], argv, envp);
		error_message("command not exectured");
		exit(EXIT_FAILURE);
	}
	waitpid(pid, &status, 0);
	if (contains_pipe == true)
		set_pipe(fd, STDIN_FILENO);
	return WIFEXITED(status) && WEXITSTATUS(status);
}


int main(int argc, char **argv, char **envp)
{
	(void) argc;
	int i = 0;
	int status = 0;

	while(argv[i] != NULL)
	{
		argv += i + 1;
		i = 0;

		while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
			i++;
		
		if (i > 0)
			status = execute_command(i, argv, envp);
	}
	return status;
}
