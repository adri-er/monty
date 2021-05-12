#include "monty.h"

/**
 * process_input - processes each line of the file introduced.
 * @clean_buffer: buffer without initial spaces.  
 * @fp: pointer to file in memory.
 * 
 * Return: EOF if end of file is reached, EXIT_FAILURE if getline fails.
 */
int process_input(char *clean_buffer, FILE *fd, char *command_array[])
{
    char *buffer_tmp = NULL;
    size_t length = 0;
    ssize_t n_characters = 0;

    n_characters = getline(&buffer_tmp, &length, fd);
    if (n_characters == -1)
    {       
        free(buffer_tmp);
        return (EOF);
    }
    if (n_characters == 1)
    {       
        free(buffer_tmp);
        return (EXIT_FAILURE);
    }
    buffer_cleaner(clean_buffer, buffer_tmp, n_characters);
    free(buffer_tmp);
    tokenizer(command_array, clean_buffer);
    
    return (EXIT_SUCCESS);
}

/**
 * tokenizer - tokenizes a line to an array. 
 * @array: arrays of commands. 
 * @clean_buffer: buffer without initial spaces.
 * 
 * Return: None. 
 */
void tokenizer(char *command_array[], char *clean_buffer)
{
    int i = 0;
    char *token = NULL;

    while (1)
    {
        token = strtok(((i == 0) ? clean_buffer : NULL), " ");
        command_array[i] = token;
        if (token == NULL)
            break;
        i++;
    }
}

/**
 * buffer_cleaner - removes initial spaces from line and \\n line jump.
 * @clean_buffer: buffer without initial spaces.  
 * @buffer_temp: buffer with initial spaces.
 * 
 * Return: None.
 */
void buffer_cleaner(char *clean_buffer, char *buffer_temp, ssize_t n_characters)
{
    int i = 0, j = 0, start_letters = 0;

    while (i < n_characters)
    {
        if (buffer_temp[i] != ' ')
        {
            start_letters = 1;
        }
        if (start_letters == 1)
        {
            clean_buffer[j] = buffer_temp[i];
            j++;
        }
        i++;
    }
    clean_buffer[j - 1] = '\0';
}