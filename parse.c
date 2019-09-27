#include "monty.h"
/**
 * parse - parse input at newline
 * @s: input
 * @buffer: buffer for output
 * Return: 2d array of parsed input
 */
char **parse(char *s, char *buffer[])
{
	char delim[] = "\n";
	char *token;
	int i = 0;

	token = strtok(s, delim);

	while (token)
	{
		buffer[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	if (buffer[0] == NULL)
		return (NULL);
	return (buffer);
}
/**
 * parse_space - parse input at space
 * @s: input
 * @buffer: buffer for output
 * Return: 2d array of parsed input
 */
char **parse_space(char *s, char *buffer[])
{
	char delim[] = " ";
	char *token;
	int i = 0;

	token = strtok(s, delim);

	while (token)
	{
		buffer[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	if (buffer[0] == NULL)
		return (NULL);
	return (buffer);
}
