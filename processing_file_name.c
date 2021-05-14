#include "monty.h"

/**
 * process_input - processes each line of the file introduced.
 * @clean_buffer: buffer without initial spaces.
 *
 * Return: EOF if end of file is reached, EXIT_FAILURE if getline fails.
 */
int process_input(char *clean_buffer)
{
	char *buffer_tmp = NULL;
	size_t length = 0;
	ssize_t n_characters = 0;

	*clean_buffer = '\0';
	n_characters = getline(&buffer_tmp, &length, global_var.fp);
	if (n_characters == ERR_GETLINE)
	{
		free(buffer_tmp);
		return (EOF);
	}
	buffer_cleaner(clean_buffer, buffer_tmp, n_characters);
	if (*clean_buffer == '\0')
	{
		free(buffer_tmp);
		return (EMPTY_LINE);
	}
	if (*clean_buffer == COMMENT_SYM)
	{
		free(buffer_tmp);
		return (COMMENT);
	}
	free(buffer_tmp);
	tokenizer(clean_buffer);

	return (EXIT_SUCCESS);
}

/**
 * tokenizer - tokenizes a line to an array.
 * @clean_buffer: buffer without initial spaces.
 *
 * Return: None.
 */
void tokenizer(char *clean_buffer)
{
	int i = 0;
	char *token = NULL;

	while (1)
	{
		token = strtok(((i == 0) ? clean_buffer : NULL), DELIM);
		global_var.command_array[i] = token;
		if (token == NULL)
			break;
		i++;
	}
}

/**
 * buffer_cleaner - removes initial spaces from line and \\n line jump.
 * @clean_buffer: buffer without initial spaces.
 * @buffer_temp: buffer with initial spaces.
 * @n_chars: number of characters in getline.
 *
 * Return: None.
 */
void buffer_cleaner(char *clean_buffer, char *buffer_temp, ssize_t n_chars)
{
	int i = 0, j = 0, start_letters = 0;

	while (i < n_chars)
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
