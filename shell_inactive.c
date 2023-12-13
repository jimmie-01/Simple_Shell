#include "shell.h"

/**
 * shell_inactive - The shell in an uninteractive mode
 *
 * Return: void
 */

void shell_inactive(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		line = read_stream();
		args = split_line(line);
		status = exec_arg(args);

		free(line);
		free(args);

		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
