#include "prototype.h"

/**
 * _strlen - Compute the length of a string.
 *
 * @s: The string that will be processed.
 *
 * Return: the length of the string.
 **/
int _strlen(char *s)
{
	int i = 0, tamano = 0;

	while (i != -1)
	{
		if (*(s + i) != '\0')
		tamano = tamano + 1;
		else
		{
			i = -1;
			break;
		}
		i = i + 1;
	}
	return (tamano);
}

/**
 * _strcmp - Compares two strings.
 *
 * @s1: First string.
 *
 * @s2: Second string.
 *
 * Return: Number of diferent characters.
 **/
int _strcmp(char *s1, char *s2)
{
	int i = 0, diferencia = 0;

	if (s1[0] == '\0' || s2[0] == '\0')
	{
		return (-1);
	}

	if ((_strlen(s1) > _strlen(s2)) || (_strlen(s2) > _strlen(s1)))
	{
		return (-1);
	}

	for (i = 0; s2[i] != '\0' && s1[i] != '\0' ; i++)
	{
		if ((s1[i]) - (s2[i]) != 0)
		{
			diferencia = (s1[i]) - (s2[i]);
			break;
		}
	}
	return (diferencia);
}

/**
 * _strconcat - Concatenates two strings.
 *
 * @s1: First string.
 *
 * @s2: Second string.
 *
 * Return: A pointer to the new string
 */
char *_strconcat(char *s1, char *s2)
{
	char *s;

	int size1 = 0, size2 = 0, i;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[size1])
		size1++;
	while (s2[size2])
		size2++;

	s = malloc(sizeof(char) * (size1 + size2 + 1));

	if (s == NULL)
		return (NULL);

	for (i = 0; i < size1; i++)
		s[i] = s1[i];
	for (i = 0; i < size2; i++)
		s[size1 + i] = s2[i];

	s[size1 + size2] = 0;
	return (s);
}

/**
 * *_strdup - Creates a duplicate of a string in a new space of memory.
 *
 * @str: The string that will be duplicated.
 *
 * Return: a char * to the new duplicate of @str, otherwise NULL.
 */
char *_strdup(char *str)
{
	char *p;
	unsigned int i = 0, tamano = 0;

	if (str == NULL)
		return (NULL);

	while (str[tamano] != '\0')
		tamano = tamano + 1;

	p = malloc(sizeof(char) * tamano + 1);

	if (p == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		*(p + i) = *(str + i);
		i = i + 1;
	}
	*(p + tamano) = '\0';
	return (p);
}

/**
 * _strWrite - Print a string.
 *
 * @str: Text to print.
 *
 * Return: Always nothing (void).
 */
void _strWrite(char *str)
{
	write(1, str, _strlen(str));
}
