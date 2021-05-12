#include "monty.h"

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
    FILE *fp = NULL;
    int line_number = 0;
    char clean_buffer[5000], *command_array[2000];
    
    if (argc > 1)
    {
        check_permissions(argv[1]);
        fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            printf("Error: Can't open file %s", argv[1]);
            exit(EXIT_FAILURE);
        }
        while (is_EOF != EOF)
        {
            line_number++;
            is_EOF = process_input(clean_buffer, fp, command_array);
            if (is_EOF == EOF)
            {
                fclose(fp);
                return (EXIT_SUCCESS);
            }

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
        printf("Error: Can't open file %s", file_name);
        exit(EXIT_FAILURE);
    }
    access_permission = access(file_name, R_OK);
    if (access_permission == -1)
    {
        printf("Error: Can't open file %s", file_name);
        exit(EXIT_FAILURE);
    }
    str_len = str_length(file_name);
    if (file_name[str_len - 1] != 'm' || file_name[str_len - 2] != '.')
    {
        printf("Error: Can't open file %s", file_name);
        exit(EXIT_FAILURE);
    }
}
