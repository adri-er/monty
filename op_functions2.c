#include "monty.h"

/**
 * op_swap - prints all the values in the stack.
 * @stack: top of the stack.
 * @line_number: number of line in the monty file.
 *
 * Return: None.
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack_length(stack) < 2)
	{
		fclose(global_var.fp);
		free_stack(stack);
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * op_add - adds the top two elements of the stack.
 * @stack: top of the stack.
 * @line_number: number of line in the monty file.
 *
 * Return: None.
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;

	if (stack_length(stack) < 2)
	{
		fclose(global_var.fp);
		free_stack(stack);
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	op_pop(stack, line_number);
}

/**
 * op_nop - Does nothing.
 * @stack: top of the stack.
 * @line_number: number of line in the monty file.
 *
 * Return: None.
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}
