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
	int i = 0;
	stack_t *copy = *stack;

	while (i < (stack_length(stack) - 1))
	{
		op_rotl(&copy, line_number);
		copy = copy->next;
		i++;
	}
}
