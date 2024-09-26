#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_stack_instruction(char *opcode, stack_t **stack,
		unsigned int line_num)
{
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
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
