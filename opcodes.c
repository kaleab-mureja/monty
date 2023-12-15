#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
	* is_valid_op - checks if op_code is valid
	* @op_type: op_type string
	* Description: checks if op_code is valid
	* Return: int
*/
int is_valid_op(char *op_type)
{
	char *valid_op_codes[] = {"push", "pall", "pint", "pop",
		"swap", "add", "nop"};
	int i = 0;
	int size = 7;

	for (; i < size; i++)
	{
		if (strcmp(op_type, valid_op_codes[i]) == 0)
			return (1);
	}
	return (0);
}

/**
	* get_op_func - returns the function for the given op
	* @line_number: line number where call is
	* Description: returns the function for the given op
	* Return: function
*/
void (*get_op_func(int line_number))(stack_t **stack, unsigned int line_number)
{
	char **sep_cmd = get_tokenized_line();
	instruction_t op_mappers[7] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop}
	};
	int i = 0;

	if (is_valid_op(sep_cmd[0]) == 0)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line_number, sep_cmd[0]);
		exit(EXIT_FAILURE);
	}

	for (; i < 7; i++)
	{
		if (strcmp(sep_cmd[0], op_mappers[i].opcode) == 0)
		{
			free(sep_cmd);
			return (op_mappers[i].f);
		}
	}

	free(sep_cmd);
	return (NULL);
}
