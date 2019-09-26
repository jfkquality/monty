#include "monty.h"
/**
 * get_function - gets correct function
 * @s: command name
 * Return: void
 */
void (*get_function(char *s)) (stack_t **s, unsigned int n)
{
	instruction_t funcs[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divi},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{"comments", comments},
		{NULL, NULL}
	};

	int i = 0;

	if (s == NULL)
		return (NULL);

	while (funcs[i].opcode)
	{
		if (strcmp(s, funcs[i].opcode) == 0)
			return (funcs[i].f);
		i++;
	}
	return (NULL);
}
/**
 * free_list - frees list
 * @s: pointer to stack
 */
void free_list(stack_t **s)
{
	stack_t *temp;

	while (*s)
	{
		temp = *s;
		*s = (*s)->next;
		free(temp);
	}
	free(s);
}
/**
 * create_stack - creates a stack
 * Return: double pointer to top of stack
 */
stack_t **create_stack(void)
{
	stack_t **stack;

	stack = malloc(sizeof(stack_t *));
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	*stack = NULL;
	return (stack);
}
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: vector of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd, i, line = 1, value, stacktoq = 0;
	char temp[1000] = {0}, *split[1000] = {0}, *split2[100];
	stack_t **stack;

	(void) stacktoq;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	read(fd, temp, 1000);
	close(fd);
	parse(temp, split);
	stack = create_stack();
	for (i = 0; split[i]; i++)
	{
		memset(split2, 0, sizeof(split2));
		parse_space(split[i], split2);
		if (split2[0] == NULL)
			continue;
		if (strcmp(split2[0], "push") == 0)
		{
			if (split2[1] && (isdigit(split2[1][0]) || split2[1][0] == '-'))
			{
				value = atoi(split2[1]);
				push(stack, line, value);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line);
				exit(EXIT_FAILURE);
			}
		}
		else if (get_function(split2[0]))
			get_function(split2[0])(stack, line);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line, split2[0]);
			exit(EXIT_FAILURE);
		}
		line++;
	}
	free_list(stack);
	return (0);
}
