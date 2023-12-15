#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
	* pop - removes the top element of the stack
	* @stack: stack to operate on
	* @line_number: line number where operation is called
	* Description: removes the top element of the stack
	* Return: void
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	while (current->next != NULL)
		current = current->next;

	current->prev->next = NULL;
	free(current);
}

/**
	* swap - swaps the top 2 elements of the stack
	* @stack: stack to operate on
	* @line_number: line number where operation was called
	* Description: swaps the top 2 elements of the stack
	* Return: void
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int length = 0;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	while (current->next->next != NULL)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%i: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	current->prev->next = current->next;
	current->next->next = current;
	current->next->prev = current->prev;
	current->prev = current->next;
	current->next = NULL;

}

/**
	* add - adds top two elements of the stack
	* @stack: stack to operate on
	* @line_number: line number where add operation was asked to be done
	* Description: adds top two elements of the stack
	* Return: void
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int length = 0;
	int sum;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	while (current->next != NULL)
	{
		length++;
		current = current->next;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = current->n + current->prev->n;
	current->prev->n = sum;
	current->prev->next = NULL;

	free(current);
}

/**
	* nop - does nothing
	* @stack: stack to do nothing on
	* @line_number: line where nop operation was asked to be done
	* Description: does nothing
	* Return: void
*/
void nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{


}
