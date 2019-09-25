#include "monty.h"
/**
 * push - adds new node to the stack
 * @s: pointer to stack
 * @n: line number
 * @value: value of new node
 */
void push(stack_t **s, unsigned int n, int value)
{
	stack_t *new;

	(void) n;

	if (*s == NULL)
	{
		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		new->n = value;
		new->next = NULL;
		new->prev = NULL;
		*s = new;
	}
	else
	{
		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		new->n = value;
		new->next = *s;
		(*s)->prev = new;
		*s = new;
	}
}
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
 * swap - swaps the first and second nodes
 * @s: pointer to stack
 * @n: line number
 */
void swap(stack_t **s, unsigned int n)
{
	int len = 0;

	stack_t *temp = *s, *a, *b;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", n);
		exit(EXIT_FAILURE);
	}

	a = *s;
	b = (*s)->next;
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	b->next = a;
	a->prev = b;
	b->prev = NULL;
	*s = b;
}
