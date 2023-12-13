#include "shell.h"

/**
 * read_line - This function reads user input from stdin
 *
 * Return: Pointer to the str containing input stream
 */

char *read_line(void)
{
	char *line = NULL;
	char buf[1024];

	line = fgets(buf, 1024, stdin);
	if (!line)
	{
		/*Checks if End Of File is encountered*/
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);

			perror("error while reading the line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
