#include "monty.h"

/**
 * op_selector - selects function of opcode related to the line of monty.
 * @l: number of line in the monty code.
 * @top: pointer of the top of the stack.
 *
 * Return: pointer to functions related to command.
 */
void (*op_selector(int l, stack_t **top))(stack_t **top, unsigned int line_n)
{
	int i = 0;

	instruction_t list[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL}
	};

	for (i = 0; list[i].opcode; i++)
	{
		if (strcmp(global_var.command_array[0], list[i].opcode) == 0)
		{
			return (list[i].f);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n",
					l, global_var.command_array[0]);
	free_stack(top);
	fclose(global_var.fp);
	exit(EXIT_FAILURE);
}
