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
	stack_t *copy_1 = *stack, *copy_2 = *stack;
	int i, temp, length = 0;

	line_number = line_number;
	if (copy_1 == NULL || stack == NULL)
		return;
	length = stack_length(stack);
	if (length == 0 || length == 1)
	{
		return;
	}
	while (copy_2->next != NULL)
	{
		copy_2 = copy_2->next;
	}
	for (i = 0; i < (length) / 2; i++)
	{
		temp = copy_1->n;
		copy_1->n = copy_2->n;
		copy_2->n = temp;
		copy_1 = copy_1->next;
		copy_2 = copy_2->prev;
	}
}
