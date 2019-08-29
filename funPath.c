#include "prototype.h"

/**

 * getstrtok - Function that separates text in tokens to be passed to execv.
 *
 * @buffer: The input string.
 *
 * @separator: The string that delimitates the tokens of the string.
 *
 * Return: array with text
 */
char **getstrtok(char *buffer, const char *separator)
{
	char *token, **argv;
	int words = 0;

	argv = malloc(sizeof(char *) * 64);

	if (argv == NULL)
	{
		exit(1);
	}
	token = strtok(buffer, separator);
	while (token != NULL)
	{
		*(argv + words) = token;
		token = strtok(NULL, separator);
		words++;
	}
	*(argv + words) = NULL;
	return (argv);
}

/**
 * _funValPath - Function that spltit a path.
 *
 * @comand: The string of the command to evaluate.
 *
 * @valuepath: The string that represent to path.
 *
 * Return: array with path
 */
char *_funValPath(char *comand, char *valuepath)
{
	char **pathexec, *concat, *filename;
	int i = 0;

	pathexec = getstrtok(valuepath, ":");
	while (pathexec[i] != NULL)
	{
		concat = _strconcat(pathexec[i], "/");
		filename = _strconcat(concat, comand);
		if (access(filename, F_OK || X_OK) == 0)
		{
			return (filename);
		}
		i++;
	}
	return (NULL);
}
