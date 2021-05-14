#include "monty.h"

/**
 * op_push - adds a node to thetop of the stack.
 * @stack: top of the stack.
 * @line_number: number of line in the monty file.
 *
 * Return: None.
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	long int n;
	char *end_point = NULL;

	if (stack == NULL)
	{
		fclose(global_var.fp);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fclose(global_var.fp);
		free_stack(stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if ((global_var.command_array[1]) == NULL)
	{	fclose(global_var.fp);
		free(new_node);
		free_stack(stack);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = strtol(global_var.command_array[1], &end_point, 10);
	if (end_point == global_var.command_array[1] || *end_point != '\0')
	{	fclose(global_var.fp);
		free_stack(stack);
		free(new_node);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = (int)n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * op_pall - prints all the values in the stack.
 * @stack: top of the stack.
 * @line_number: number of line in the monty file.
 *
 * Return: None.
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;

	line_number = line_number;
	while (copy != NULL)
	{
		fprintf(stdout, "%d\n", copy->n);
		copy = copy->next;
	}
}

/**
 * op_pint - prints the value at the top of the stack.
 * @stack: top of the stack.
 * @line_number: number of line in the monty file.
 *
 * Return: None.
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fclose(global_var.fp);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * op_pop - removes the top element of the stack.
 * @stack: top of the stack.
 * @line_number: number of line in the monty file.
 *
 * Return: None.
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *copy_stack = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fclose(global_var.fp);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = copy_stack->next;
	if (copy_stack->next)
	{
		copy_stack->next->prev = copy_stack->prev;
	}
	free(copy_stack);
}

/**
 * free_stack - frees a stack.
 * @stack: pointer to top of a stack.
 *
 * Return: None.
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	while ((*stack)->next)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	free(*stack);
}
