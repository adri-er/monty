#include "monty.h"

/**
 * opcode_selector - selects function of opcode related to the line of monty.
 * @line_num: number of line in the monty code.
 * 
 * Return: pointer to functions related to command.
 */
void (*opcode_selector(int line_num))(stack_t **stack, unsigned int line_number)
{
    int i = 0;

    instruction_t list[] = {
        {"push", op_push},
        {"pall", op_pall},
        /*{"pint", op_pint},
        {"pop", op_pop},
        {"swap", op_swap},
        {"add", op_add},
        {"nop", op_nop},*/
        {NULL, NULL}
    };

    for (i = 0; list[i].opcode; i++)
    {
        if (strcmp(global_var.command_array[0], list[i].opcode) == 0)
        {
            return (list[i].f);
        }
    }
    printf("L%d: unknown instruction %s\n", line_num, global_var.command_array[0]);
    fclose(global_var.fp);
    exit(EXIT_FAILURE);
}