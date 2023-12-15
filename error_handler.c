#include "monty.h"
#include <stdio.h>
#include <string.h>

/**
	* handle_error - prints appropriate message and exits program
	* @error_type: type of error that happened
	* Description: prints appropriate message and exits program
	* Return: void
*/
void handle_error(char *error_type)
{
	if (strcmp(error_type, "malloc") == 0)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	else if (strcmp(error_type, "usage") == 0)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

}
