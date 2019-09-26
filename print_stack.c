#include "monty.h"

/**
 * pall - print all nodes in stack
 * @s: pointer to stack
 * @n: line numnber
 */
void pall(stack_t **s, unsigned int n)
{
	stack_t *temp;
	(void) n;

	temp = *s;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - prints top of stack
 * @s: pointer to stack
 * @n: line number
 */
void pint(stack_t **s, unsigned int n)
{
	(void) s;
	(void) n;

	if (!*s)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", n);
		free_list(s);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*s)->n);
}
/**
 * pchar - print char of ascii code pushed to stack
 * @s: pointer to stack
 * @n: line number
 *
 */
void pchar(stack_t **s, unsigned int n)
{
	stack_t *head;

	head = *s;

	if (!head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", n);
		free_list(s);
		exit(EXIT_FAILURE);
	}
	if (head->n < 0 || head->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", n);
		free_list(s);
		exit(EXIT_FAILURE);
	}
	putchar((*s)->n);
	putchar('\n');
}
/**
 * pstr - print chars of entire stack, i.e. a string
 * @s: pointer to stack
 * @n: line number
 *
 */
void pstr(stack_t **s, unsigned int n)
{
	stack_t *head;

	(void) s;
	(void) n;

	head = *s;
	if (*s == NULL)
	{
		putchar('\n');
		return;
	}
	while (head && head->n > 0 && head->n <= 127)
	{
		putchar(head->n);
		head = head->next;
	}
	putchar('\n');
}
