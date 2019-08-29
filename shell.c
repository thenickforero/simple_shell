#include "prototype.h"
/**
 * funMainNoIntec - Function No Interactuve
 * @buffer: String initial
 * Return: 1 if its goes ok, otherwise return the status exit code.
**/

int funMainNoIntec(char *buffer)
{
	char **argv, *valuepath;
	size_t sizeBuffer = 1024;
	int size = 0;

	signal(SIGINT, ctrl_C_handler);
	size = getline(&buffer, &sizeBuffer, stdin);

	while (size != EOF)
	{
	if (size == EOF)
	{
		_strWrite("\n");
		free(buffer);
		exit(1);
	}
	if (buffer[0] != '\n')
	{
		buffer[size - 1] = '\0';
		argv = getstrtok(buffer, " \r\n\t");
		if ((_strcmp("exit", argv[0]) == 0))
		{
			exit(1);
		}
		if ((_strcmp("env", argv[0]) == 0) || (_strcmp("printenv", argv[0]) == 0))
			_printenv();
		if (*argv[0] != '/')
		{
			valuepath = _getenv("PATH");
			argv[0] = _funValPath(argv[0], valuepath);
			if (argv[0] == NULL)
			{
				return (-1);
			}
		}
		createfork(argv, buffer);
	}
	size = getline(&buffer, &sizeBuffer, stdin);
	}
	return (0);
}


/**
 * funMain - Function initial
 * @buffer: String initial
 * Return: 1 if its goes ok, otherwise return the status exit code.
**/
int funMain(char *buffer)
{
	char **argv, *valuepath;
	size_t sizeBuffer = 1024;
	int size = 0, status = 0;

	signal(SIGINT, ctrl_C_handler);
	size = getline(&buffer, &sizeBuffer, stdin);
	check_comments(buffer);
	if (size == EOF)
	{
		_strWrite("\n");
		free(buffer);
		exit(1);
	}
	if (buffer[0] != '\n')
	{
		buffer[size - 1] = '\0';
		argv = getstrtok(buffer, " \r\n\t");
		if ((_strcmp("exit", argv[0]) == 0))
		{
			if (argv[1] != NULL)
			{
				status = _atoi(argv[1]);
			}
			exit(status);
		}
		if ((_strcmp("env", argv[0]) == 0) || (_strcmp("printenv", argv[0]) == 0))
			_printenv();
		if (*argv[0] != '/')
		{
			valuepath = _getenv("PATH");
			argv[0] = _funValPath(argv[0], valuepath);
			if (argv[0] == NULL)
			{
				return (-1);
			}
		}
		createfork(argv, buffer);
	}
	return (1);
}

/**
 * main - principal function of the program
 *
 * Return: 0
 */
int main(void)
{
	char *buffer;
	size_t sizeBuffer = 1024;
	int status;

	status = 1;
	buffer = malloc(sizeof(char) * sizeBuffer);

	if (isatty(STDIN_FILENO) != 0)
	{
		while (status)
		{
			_strWrite("Cisfun$ ");
			status = funMain(buffer);
		}
	}
	else
	{
		funMainNoIntec(buffer);
	}
	return (status != 1 ? status : 0);
}
