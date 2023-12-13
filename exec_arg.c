#include "shell.h"

/**
 * exec_arg - This function executes the command entered by user
 * @args: command and its flags
 * Return: void
 */

int exec_arg(char **args)
{
	pid_t pid;
	int status;
	char *cmd = NULL;
	char *actual_path;

	pid = fork();

	if (pid == 0)
	{
		cmd = args[0];
		actual_path = get_path(cmd);

		if (execve(actual_path, args, NULL) == -1)
		{
			perror("Error in new process: child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error in new process: Forking");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
