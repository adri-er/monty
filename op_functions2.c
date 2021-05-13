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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
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

/**
 * op_sub - subtracts the top two elements of the stack.
 * @stack: top of the stack.
 * @line_number: number of line in the monty file.
 *
 * Return: None.
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	int sub = 0;

	if (stack_length(stack) < 2)
	{
		fclose(global_var.fp);
		free_stack(stack);
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = sub;
	op_pop(stack, line_number);
}

/**
 * op_div - divides the top two element of the stack to the first.
 * @stack: top of the stack.
 * @line_number: number of line in the monty file.
 *
 * Return: None.
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	int div = 0;

	if (stack_length(stack) < 2)
	{
		fclose(global_var.fp);
		free_stack(stack);
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fclose(global_var.fp);
		free_stack(stack);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	div = ((*stack)->next->n) / ((*stack)->n);
	(*stack)->next->n = div;
	op_pop(stack, line_number);
}
