#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  * add - add top two element from stack
  *
  * @stack: stack pointer
  * @line_number: the command line number
  * Return: void
  */

void add(stack_t **stack, unsigned int line_number)
{
	int first_elem;
	int second_elem;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	first_elem = (*stack)->n;
	pop(stack, line_number);
	second_elem = first_elem + (*stack)->n;
	(*stack)->n = second_elem;
}

/**
  * nop - remove top element from stack
  *
  * @stack: stack pointer
  * @line_number: the command line number
  * Return: void
  */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
