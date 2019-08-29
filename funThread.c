#include "prototype.h"

/**
 * createfork - Function that creates a new child process to execute a command.
 *
 * @argv: Number of argument
 *
 * @buffer: Text input
 *
 * Return: 1. -1 to Error, 0 to Succeful
 */
int createfork(char **argv, char *buffer)
{
	int status = 0;

	pid_t my_pid;

	my_pid = fork();

	if (my_pid == -1)
	{
		perror("Error:");
		free(buffer);
		free(argv);
		return (1);
	}
	else if (my_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
			free(buffer);
			free(argv);
			_exit(EXIT_FAILURE);
		}
	}
	else if (my_pid < 0)
	{
		perror("Error");
		free(buffer);
		free(argv);
		return (-1);
	}
	else
	{
		wait(&status);
	}
	return (0);
}

/**
 * _atoi - Convert a string to an integer
 *
 * @s: String that will be converted.
 *
 * Return: The integer value of the parsed string.
 */

int _atoi(char *s)

{

	int i, sign, num, brk;

	num = 0;
	brk = 0;
	i = 0;
	sign = -1;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 - (s[i] - '0');
			brk = 1;
		}
		else if (brk == 1)
		{
			break;
		}
		i++;
	}

	num *= sign;

	return (num);
}

/**
 *ctrl_C_handler - Handler function to manage Ctrl+C in the input of the shell.
 *
 *@signal_num: Numeric indicator of the SIGINT signal.
 *
 *Return: Always nothing (void).
 */

void ctrl_C_handler(int signal_num)
{
	signal_num *= 1;
	write(1, "", 1);
}

/**
 * check_comments - Check if there is a comment in the string
 *					and deletes that part of the command input string.
 *
 * @string: The command input string that will be processed.
 *
 * Return: Always nothing (void).
 */

void check_comments(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '#')
		{
			string[i] = '\0';
			break;
		}
	}
}
