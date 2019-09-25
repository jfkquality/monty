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
		printf("L%d: can't pop an empty stack\n", n);
		free(s);
		exit(EXIT_FAILURE);
	}
	if (!temp->next)
	{
		free(temp);
		free(s);
		exit(EXIT_SUCCESS);
	}
	else
	{
		(*s)->next->prev = NULL;
		*s = (*s)->next;
	}
	free(temp);
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
/**
 * pint - prints top of stack
 * @s: pointer to stack
 * @n: line number
 */
/**
 * pint  - prints top of stack
 * @s: pointer to stack
 * @n: line number
 */
void pint(stack_t **s, unsigned int n)
{
	(void) s;
	(void) n;

	if (!*s)
	{
		printf("LLL: can't pint, stack empty\n"); /* , n); */
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
		printf("L%d: can't pchar, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	if (head->n < 0 || head->n > 127)
	{
		printf("L%d: can't pchar, value out of range\n", n);
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

	while (head->next && head->n > 0 && head->n <= 127)
	{
		putchar(head->n);
		head = head->next;
	}
	putchar('\n');
}
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
	/**
	 * store head.
	 * - temp = head
	 * - tail = head
	 * iterate to bottom/tail of stack.
	 * - tail = tail.next
	 * make head the new tail
	 * - tail.next = head
	 * - head.prev = tail
	 * make head.next the new head
	 * - head.next.prev = null
	 * - *s = head.next
	 * - head.next = null
	 */

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
	tail->next = head->next;
	tail->prev->next = NULL;
	tail->prev = NULL;
	head->prev = tail;
	*s = tail;

	/* head->next = NULL; */
}
/**
 * stack - change data to a stack (LIFO, default)
 * @s: pointer to stack
 * @n: line number
 *
 */
void stack(stack_t **s, unsigned int n)
{
	stacktoq = 0;

	(void) s;
	(void) n;
	/* (void) stacktoq; */

}
/**
 * queue - change data to a queue (FIFO)
 * @s: pointer to stack
 * @n: line number
 *
 */
void queue(stack_t **s, unsigned int n)
{
	stacktoq = 1;

	(void) s;
	(void) n;
	/* (void) stacktoq; */
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
