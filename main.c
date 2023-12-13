#include "shell.h"

/**
 * main - Function that checks if our shell is ii interactive
 * mode or non-interactvie mode
 *
 * Return: 0 on success
 */

int main(void)
{
	/* Determine if file descriptor is associated with a terminal*/
	if (isatty(STDIN_FILENO) == 1)
	{
		shell_interactive();
	}
	else
	{
		shell_inactive();
	}
	return (0);
}
