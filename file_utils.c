#include "monty.h"
#include <stdio.h>

/**
	* get_line - returns the current line in file
	* @fp: file stream
	* Description: returns the current line in file
	* Return: char
*/
char *get_line(FILE *fp)
{
	int size = 1000000;
	char *res;
	char ch;
	int i = 0;

	res = malloc(sizeof(char) * size);
	if (res == NULL)
		handle_error("malloc");

	while ((ch = fgetc(fp)) != '\n')
	{
		if (ch == EOF)
			return (NULL);

		strncat(res, &ch, 1);
		i++;
	}

	return (res);
}


/**
	* get_tokenized_line - returns an array of line sep by space
	* Description: returns an array of line sep by space
	* Return: char
*/
char **get_tokenized_line()
{
	const char *delims = " ";
	char **res;
	char *token;
	int pos = 0;
	char *tmp;

	res = malloc(sizeof(char *) * 3);
	if (res == NULL)
	{
		handle_error("malloc");
	}

	tmp = _strdup(line);
	token = strtok(tmp, delims);
	while (pos < 2)
	{
		res[pos++] = token;
		token = strtok(NULL, delims);
	}
	res[pos] = NULL;

	return (res);
}

/**
	* is_valid_line - checks if a line is valid
	* @line: line to check if is valid
	* Description: checks if a line is valid
	* Return: int
*/
int is_valid_line(char *line)
{
	int i = 0;

	for (; line[i] != '\0'; i++)
	{
		if (line[i] != ' ')
			return (1);
	}

	return (0);
}
