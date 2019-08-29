#include "prototype.h"

/**
 * _getenv - returns value variable
 * @name: variable name
 * Return: string with value
 **/
char *_getenv(char *name)
{
	char **env, **path, *copia;

	for (env = environ; *env != NULL; env++)
	{
		copia = _strdup(*env);
		path = getstrtok(copia, "=");

		if (_strcmp(path[0], name) == 0)
		{
			break;
		}
	}
	return (path[1]);
}

/**
 * _printenv - Prints the current enviroment variables.
 *
 * Return: Always nothing (void).
 **/
void _printenv(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		_strWrite(*env);
		_strWrite("\n");
	}
}
