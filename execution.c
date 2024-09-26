#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  * execute_stack_instruction - parse the commands and call the fun
  *
  * @opcode: char array to the operatio code
  * @stack: pointer to the stack
  * @line_num: command line number
  * Return: Always 0 (Success)
  */
void execute_stack_instruction(char *opcode, stack_t **stack,
		unsigned int line_num)
{
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	int i = 0;

	while (instruction[i].opcode != NULL)
	{
		if (strcmp(instruction[i].opcode, opcode) == 0)
		{
			instruction[i].f(stack, line_num);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
	exit(EXIT_FAILURE);
}
