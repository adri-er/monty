#include "monty.h"

/**
 * op_rotr - rotates the stack to the bottom.
 * @stack: top of the stack.
 * @line_number: number of line in the monty file.
 *
 * Return: None.
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;
	int i, temp;

	line_number = line_number;
	if (copy == NULL || stack == NULL)
		return;
	while (copy->next != NULL)
	{
		copy = copy->next;
	}

	while (i < (stack_length(stack) - 1) && copy != NULL)
	{
		temp = copy->n;
		copy->n = copy->prev->n;
		copy->prev->n = temp;
		i++;
		copy = copy->prev;
	}
}
