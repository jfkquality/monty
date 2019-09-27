#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct g - global variable structs
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: global variables for Monty project
 */
struct g
{
	int stoc;
} g;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void (*get_function(char *s)) (stack_t **s, unsigned int n);
void find_function(stack_t **s, char *split[], int line);
stack_t **create_stack(void);
int is_digit(char *s);
void free_list(stack_t **s);
void push(stack_t **s, unsigned int n, int value);
void pall(stack_t **s, unsigned int n);
void swap(stack_t **s, unsigned int n);
void mod(stack_t **s, unsigned int n);
void mul(stack_t **s, unsigned int n);
void divi(stack_t **s, unsigned int n);
void sub(stack_t **s, unsigned int n);
void add(stack_t **s, unsigned int n);
char **parse_space(char *s, char *buffer[]);
char **parse(char *s, char *buffer[]);
void pop(stack_t **s, unsigned int n);
void pint(stack_t **s, unsigned int n);
void pchar(stack_t **s, unsigned int n);
void pstr(stack_t **s, unsigned int n);
void rotl(stack_t **s, unsigned int n);
void rotr(stack_t **s, unsigned int n);
void queue(stack_t **s, unsigned int n);
void stack(stack_t **s, unsigned int n);
void comments(stack_t **s, unsigned int n);
void nop(stack_t **s, unsigned int n);

#endif
