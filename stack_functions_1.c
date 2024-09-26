#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  * push - add items to stack
  *
  * @stack: pointer to stack
  * @line_number: command line number
  * Return: void
  */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	char *arg = strtok(NULL, " \t\n");
	int n;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;

}

/**
  * pall - print all items in stack
  *
  * @stack: stack pointer
  * @line_number: the command line number
  * Return: void
  */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	(void) line_number;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}

}

/**
  * pint - print value at the top of stack
  *
  * @stack: stack pointer
  * @line_number: the command line number
  * Return: void
  */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
  * pop - remove top element from stack
  *
  * @stack: stack pointer
  * @line_number: the command line number
  * Return: void
  */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
  * swap - remove top element from stack
  *
  * @stack: stack pointer
  * @line_number: the command line number
  * Return: void
  */

void swap(stack_t **stack, unsigned int line_number)
{
        stack_t *temp = NULL;

        if (*stack == NULL)
        {
                fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
                exit(EXIT_FAILURE);
        }
        temp = *stack;
        *stack = (*stack)->next;
        if (*stack != NULL)
                (*stack)->prev = NULL;
        free(temp);
}

/**
  * add - remove top element from stack
  *
  * @stack: stack pointer
  * @line_number: the command line number
  * Return: void
  */

void add(stack_t **stack, unsigned int line_number)
{
        stack_t *temp = NULL;

        if (*stack == NULL)
        {
                fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
                exit(EXIT_FAILURE);
        }
        temp = *stack;
        *stack = (*stack)->next;
        if (*stack != NULL)
                (*stack)->prev = NULL;
        free(temp);
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

	exit(EXIT_SUCCESS);
}
