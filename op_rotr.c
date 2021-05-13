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

	line_number = line_number;
	if (copy == NULL || stack == NULL)
		return;

	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	*stack = copy;
}
