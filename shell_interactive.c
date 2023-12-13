#include "shell.h"

/**
 * shell_interactive - Unix command line interpreter
 *
 * Return: void
 */

void shell_interactive(void)
{
	char *cmd;
	char **args;

	do {
		printf("simple_prompt$ ");
		cmd = read_line();
		if (!cmd)
		{
			exit(EXIT_SUCCESS);
		}
		if (cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
		{
			continue;
		}
		if (strcmp(cmd, "exit\n") == 0)
		{
			break;
		}
		args = split_line(cmd);
		exec_arg(args);
	} while (1);
}
