#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: vector of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd; /* , line = 1, value,* i; */
	char temp[1000] = {0}, *split[1000] = {0}; /* , *split2[100]; */
	stack_t **stack;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	read(fd, temp, 1000);
	close(fd);
	parse(temp, split);
	stack = create_stack();
	find_function(stack, split); /* , line); */
	free_list(stack);
	return (0);
}
