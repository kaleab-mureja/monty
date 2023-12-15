#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
	* _strdup - duplicate a string
	* @str: string we want duplicated
	* Description: duplicate a string
	* Return: duplicated string
*/
char *_strdup(char *str)
{
	int i = 0;
	char *new_str;

	new_str = malloc(sizeof(char) * strlen(str));
	if (new_str == NULL)
	{
		handle_error("malloc");
	}

	for (; str[i] != '\0'; i++)
	{
		new_str[i] = str[i];
	}

	return (new_str);
}

/**
	* is_number - checks if a string can be converted to an int
	* @str: string to check if is a number
	* Description: checks if a string can be converted to an int
	* Return: int
*/
int is_number(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);

		i++;
	}

	return (1);
}

