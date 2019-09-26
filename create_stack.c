#include "monty.h"

/**
 * find_function - push() or find function
 * @stack: the stack
 * @split: command line tokens
 * @line: line for error statements
 *
 * Return: void.
 */
void find_function(stack_t **stack, char *split[], int line)
{
	int i, value;
	char *split2[100];

	for (i = 0; split[i]; i++)
	{
		memset(split2, 0, sizeof(split2));
		parse_space(split[i], split2);
		if (split2[0] == NULL)
			continue;
		if (split2[0][0] == '#')
			continue;
		if (strcmp(split2[0], "push") == 0)
		{
			if (split2[1] && is_digit(split2[1]))
			{
				value = atoi(split2[1]);
				push(stack, line, value);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n",
					line);
				free_list(stack), exit(EXIT_FAILURE);
			}
		}
		else if (get_function(split2[0]))
			get_function(split2[0])(stack, line);
		else
			fprintf(stderr, "L%d: unknown instruction %s\n", line,
				split2[0]), free_list(stack),
				exit(EXIT_FAILURE);
		line++;
	}

}
