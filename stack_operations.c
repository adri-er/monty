#include "monty.h"

/**
 * stack_length - determines the length of a stack.
 * @stack: top of the stack.
 *
 * Return: None.
 */
int stack_length(stack_t **stack)
{
	stack_t *copy = *stack;
	int counter = 0;

	while (copy && stack)
	{
		copy = copy->next;
		counter++;
	}

	return (counter);
}
