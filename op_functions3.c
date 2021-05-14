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

/**
 * op_pchar - prints the char at the top of the stack.
 * @stack: top of the stack.
 * @line_number: number of line in the monty file.
 *
 * Return: None.
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	if (stack_length(stack) == 0)
	{
		fclose(global_var.fp);
		free_stack(stack);
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fclose(global_var.fp);
		free_stack(stack);
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}

/**
 * op_pstr - prints string formed by the stack.
 * @stack: top of the stack.
 * @line_number: number of line in the monty file.
 *
 * Return: None.
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *copy = *stack;

	line_number = line_number;
	while (i < stack_length(stack))
	{
		if (copy->n <= ASCCII_LLIMIT || copy->n > ASCCII_ULIMIT)
		{
			break;
		}
		fprintf(stdout, "%c", copy->n);
		i++;
		copy = copy->next;
	}
	fprintf(stdout, "\n");
}

/**
 * op_rotl - rotates the stack to the top.
 * @stack: top of the stack.
 * @line_number: number of line in the monty file.
 *
 * Return: None.
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	int temp, i = 0;
	stack_t *copy = *stack;

	line_number = line_number;
	while (i < (stack_length(stack) - 1) && copy != NULL)
	{
		temp = copy->n;
		copy->n = copy->next->n;
		copy->next->n = temp;
		i++;
		copy = copy->next;
	}
}
