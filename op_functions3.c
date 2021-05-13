#include "monty.h"

/**
 * op_mul - multiplies second top element of stack with top element of stack.
 * @stack: top of the stack.
 * @line_number: number of line in the monty file.
 *
 * Return: None.
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	int mul = 0;

	if (stack_length(stack) < 2)
	{
		fclose(global_var.fp);
		free_stack(stack);
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mul = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = mul;
	op_pop(stack, line_number);
}

/**
 * op_mod - computes the rest of the division of the
 * second top element of stack with top element of stack.
 * @stack: top of the stack.
 * @line_number: number of line in the monty file.
 *
 * Return: None.
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	int mod = 0;

	if (stack_length(stack) < 2)
	{
		fclose(global_var.fp);
		free_stack(stack);
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fclose(global_var.fp);
		free_stack(stack);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = mod;
	op_pop(stack, line_number);
}
