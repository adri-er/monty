#include "monty.h"

glob_var global_var = {NULL, NULL};

/**
 * main - main function of the monty processing.
 * @argc: integer with the amount of arguments.
 * @argv: array with pointers to each argument.
 *
 * Return: EXIT_SUCCESS if success, EXIT_FAILURE instead.
 */
int main(int argc, char *argv[])
{
    ssize_t is_EOF = 0;
    char clean_buffer[5000], *buffer_array[2000];
    stack_t *stack = NULL;
    unsigned int line_number = 0;
    void (*op_function)(stack_t **, unsigned int);

    global_var.command_array = buffer_array;
    if (argc > 1)
    {
        check_permissions(argv[1]);
        global_var.fp = fopen(argv[1], "r");
        if (global_var.fp == NULL)
        {
            printf("Error: Can't open file %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        while (is_EOF != EOF)
        {
            line_number++;
            is_EOF = process_input(clean_buffer);
            if (is_EOF == EOF)
            {
                fclose(global_var.fp);
                free(stack);
                return (EXIT_SUCCESS);
            }
            op_function = op_function;
            op_function = opcode_selector(line_number, &stack);
            op_function(&stack, line_number);
        }
    }
    return (0);
}


/**
 * check_permissions - checks if the files have the corresponding permissions
 * if not, it exits.
 * @file_name: name of the monty file.  
 * 
 * Return: None.
 */
void check_permissions(char *file_name)
{
    int str_len, access_permission;

    access_permission = access(file_name, F_OK);
    if (access_permission == -1)
    {
        printf("Error: Can't open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    access_permission = access(file_name, R_OK);
    if (access_permission == -1)
    {
        printf("Error: Can't open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    str_len = str_length(file_name);
    if (file_name[str_len - 1] != 'm' || file_name[str_len - 2] != '.')
    {
        printf("Error: Can't open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }
}
