#include "monty.h"

/**
 * str_length - Determines the strings length.
 * @str: string to analize.
 *
 * Return: integer with the length of the string.
 */
int str_length(char *str)
{
	int i, count = 0;

	for (i = 0; str[i]; i++)
	{
		count++;
	}

	return (count);
}
