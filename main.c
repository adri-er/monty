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
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		while (is_EOF != EOF)
		{
			line_number++;
			is_EOF = process_input(clean_buffer);
			if (is_EOF == EOF)
			{
				fclose(global_var.fp);
				free_stack(&stack);
				return (EXIT_SUCCESS);
			}
			if (is_EOF == EMPTY_LINE || is_EOF == COMMENT)
			{
				continue;
			}
			op_function = op_selector(line_number, &stack);
			op_function(&stack, line_number);
		}
	}
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
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
	int access_permission;

	access_permission = access(file_name, F_OK);
	if (access_permission == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	access_permission = access(file_name, R_OK);
	if (access_permission == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
}
