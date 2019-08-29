#ifndef SHELL
#define SHELL
	#define _GNU_SOURCE
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <string.h>
	#include <sys/types.h>
	#include <sys/wait.h>

	extern char **environ;

	int _strlen(char *s);
	int _strcmp(char *s1, char *s2);
	char *_strconcat(char *s1, char *s2);
	char *_strdup(char *str);
	void _printenv(void);
	char *_getenv(char *name);
	char **getstrtok(char *buffer, const char *separator);
	char *_funValPath(char *comand, char *valuepath);
	void _strWrite(char *str);
	int createfork(char **argv, char *buffer);
	void ctrl_C_handler(int signal_num);
	int _atoi(char *s);
	void check_comments(char *string);
#endif
