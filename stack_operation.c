#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
	* push_to_head - adds an element to the head of a stack
	* @head: head of stack(linked list)
	* @n: value of new node
	* Description: adds an element to the head of a stack
	* Return: pointer to new head of stack
*/
stack_t *push_to_head(stack_t **head, int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = n;

	if (*head == NULL)
	{
		*head = node;
		return (node);
	}

	node->next = *head;
	(*head)->prev = node;
	*head = node;

	return (node);
}

/**
	* push - pushes a new value onto the stack
	* @stack: stack to operate on
	* @line_number: line number of current operation
	* Description: pushes a new value onto the stack
	* Return: void
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	stack_t *node;
	char **tokenized_line;
	int n;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		handle_error("malloc");
	}

	tokenized_line = get_tokenized_line();

	if (tokenized_line[1] == NULL || is_number(tokenized_line[1]) == 0)
	{
		free(tokenized_line);
		free(node);
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(tokenized_line[1]);
	node->n = n;

	if (*stack == NULL)
	{
		*stack = node;
		return;
	}

	current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = node;
	node->prev = current;

	free(tokenized_line);
}

/**
	* pall - prints all values in the stack
	* @stack: stack to operate on.
	* @line_number: line number where operation is located.
	* Description: prints all values in the stack
	* Return: void
*/
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
		return;
	current = *stack;

	while (current->next != NULL)
		current = current->next;

	while (current->prev != NULL)
	{
		printf("%i\n", current->n);
		current = current->prev;
	}
}

/**
	* free_stack - frees the stack from memory
	* @stack: stack to free
	* Description: frees the stack from memory
	* Return: void
*/
void free_stack(stack_t *stack)
{
	stack_t *current;

	while ((current = stack) != NULL)
	{
		stack = stack->next;
		free(current);
	}
}

/**
	* pint - prints the value at the top of the stack
	* @stack: stack to operate on
	* @line_number: line number where op is called
	* Description: prints the value at the top of the stack
	* Return: void
*/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	while (current->next != NULL)
		current = current->next;

	printf("%i\n", current->n);
}
