#include "monty.h"

/**
 * rotl - rotate stack to top
 * @s: pointer to stack
 * @n: line number
 *
 */
void rotl(stack_t **s, unsigned int n)
{
	stack_t *head, *tail;

	(void) s;
	(void) n;

	head = *s;
	tail = head;

	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = head;
	head->prev = tail;
	head->next->prev = NULL;
	*s = head->next;
	head->next = NULL;
}
/**
 * rotr - rotate stack to bottom
 * @s: pointer to stack
 * @n: line number
 *
 */
void rotr(stack_t **s, unsigned int n)
{
	stack_t *head, *tail;

	(void) s;
	(void) n;

	head = *s;
	tail = head;

	while (tail->next)
	{
		tail = tail->next;
	}

	tail->next = head;
	tail->prev->next = NULL;
	tail->prev = NULL;
	head->prev = tail;
	*s = tail;
}
/**
 * comments - find comments. do nothing).
 * @s: pointer to stack
 * @n: line number
 *
 */
void comments(stack_t **s, unsigned int n)
{
	/* if 1st non-space char is "#": is comment; do nothing" */
	(void) s;
	(void) n;
	/* (void) str; */
}
