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
	stack_t *current;

	(void) n;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->next = NULL;
	new->prev = NULL;
	if (*s == NULL)
		*s = new;
	else if (!g.stoq) /* is stack: add to top */
	{
		new->next = *s;
		(*s)->prev = new;
		*s = new;
	}
	else /* is queue: add to bottom */
	{
		current = *s;
		while (current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
}
/**
 * pop - delets top of stack
 * @s: pointer to stack
 * @n: line number
 */
void pop(stack_t **s, unsigned int n)
{
	stack_t *temp;
	(void) s;
	(void) n;

	temp = *s;

	if (!*s)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", n);
		free(s);
		exit(EXIT_FAILURE);
	}
	if (!temp->next)
	{
		free(*s);
		*s = NULL;
		return;
	}
	else
	{
		(*s)->next->prev = NULL;
		*s = (*s)->next;
	}
	free(temp);
}
/**
 * stack - change data to a stack (LIFO, default)
 * @s: pointer to stack
 * @n: line number
 *
 */
void stack(stack_t **s, unsigned int n)
{
	g.stoq = 0;

	(void) s;
	(void) n;
}
/**
 * queue - change data to a queue (FIFO)
 * @s: pointer to stack
 * @n: line number
 *
 */
void queue(stack_t **s, unsigned int n)
{
	g.stoq = 1;

	(void) s;
	(void) n;
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
		free_list(s);
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
