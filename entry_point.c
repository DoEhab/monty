#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
/**
  * main - Entry point
  *
  * @argc: arguments count
  * @argv: arguments value
  * Return: Always 0 (Success)
  */

int main(int argc, char **argv)
{
	FILE *fptr;
	char str[BUFFER_SIZE];

	size_t line_num = 0;
	stack_t *stack = NULL;
	char *opcode = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);

	}
	while (fgets(str, BUFFER_SIZE, fptr) != NULL)
	{
		line_num++;
		opcode = strtok(str, " \t\n$");
		if (opcode != NULL && opcode[0] != '#')
			execute_stack_instruction(opcode, &stack, line_num);
	}

	fclose(fptr);
	while (stack)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
	return (0);
}
