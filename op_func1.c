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
        printf("L%d: usage: push integer\n", line_number); /* Check error message */
        exit(EXIT_FAILURE);
    }
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fclose(global_var.fp);
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    if (*(global_var.command_array[1]) == '\0')
    {
        fclose(global_var.fp);
        printf("L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    n = strtol(global_var.command_array[1], &end_point, 10); /* Revisar caso que sea n sea cero error o valido? */
    if (end_point == global_var.command_array[1] || *end_point != '\0')
    {
        fclose(global_var.fp);
        printf("L%d: usage: push integer\n", line_number);
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
    while (copy)
	{
		printf("%d\n", copy->n);
		copy = copy->next;
	}
}
