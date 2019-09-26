#include "monty.h"
/**
 * mod - modulo b by a
 * @s: pointer to stack
 * @n: line number
 */
void mod(stack_t **s, unsigned int n)
{
	int len = 0, total;

	stack_t *temp = *s, *a, *b;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", n);
		free_list(s);
		exit(EXIT_FAILURE);
	}
	if ((*s)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", n);
		free_list(s);
		exit(EXIT_FAILURE);
	}
	a = *s;
	b = (*s)->next;
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	total = (b->n) % (a->n);
	a->n = total;
	free(b);
}
/**
 * mul - multiply a by b
 * @s: pointer to stack
 * @n: line number
 */
void mul(stack_t **s, unsigned int n)
{
	int len = 0, total;

	stack_t *temp = *s, *a, *b;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", n);
		free_list(s);
		exit(EXIT_FAILURE);
	}

	a = *s;
	b = (*s)->next;
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	total = (a->n) * (b->n);
	a->n = total;
	free(b);
}
/**
 * divi - divide b by a
 * @s: pointer to stack
 * @n: line number
 */
void divi(stack_t **s, unsigned int n)
{
	int len = 0, total;

	stack_t *temp = *s, *a, *b;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", n);
		free_list(s);
		exit(EXIT_FAILURE);
	}

	if ((*s)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", n);
		free_list(s);
		exit(EXIT_FAILURE);
	}
	a = *s;
	b = (*s)->next;
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	total = (b->n) / (a->n);
	a->n = total;
	free(b);
}
/**
 * sub - subtract b from a
 * @s: pointer to stack
 * @n: line number
 */
void sub(stack_t **s, unsigned int n)
{
	int len = 0, total;

	stack_t *temp = *s, *a, *b;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", n);
		free_list(s);
		exit(EXIT_FAILURE);
	}

	a = *s;
	b = (*s)->next;
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	total = (b->n) - (a->n);
	a->n = total;
	free(b);
}
/**
 * add - add a and b
 * @s: pointer to stack
 * @n: line number
 */
void add(stack_t **s, unsigned int n)
{
	int len = 0, total;

	stack_t *temp = *s, *a, *b;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", n);
		free_list(s);
		exit(EXIT_FAILURE);
	}
	a = *s;
	b = (*s)->next;
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	total = (a->n) + (b->n);
	a->n = total;
	free(b);
}
