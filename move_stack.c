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

	(void) n;

	if (*s == NULL)
		return;

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

	(void) n;

	if (*s == NULL || (*s)->next == NULL)
		return;

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
 * nop - does nothing
 * @s: pointer to stack
 * @n: line number
 */
void nop(stack_t **s, unsigned int n)
{
	(void) s;
	(void) n;
}
