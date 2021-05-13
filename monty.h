#ifndef MONTY_H
#define MONTY_H

/*---------------LIBRARIES-------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/*---------------STRUCTURES-------------------*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_values - global values needed.
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_values
{
        FILE *fp;
        char **command_array;
} glob_var;

/*---------------GLOBAL VARIABLES-------------------*/
extern glob_var global_var;


/*---------------FUNCTIONS-------------------*/

/* main.c */
void check_permissions(char *file_name);

/* strings.c */
int str_length(char *str);

/* processing_file_name.c */
void buffer_cleaner(char *clean_buffer, char *buffer_temp, ssize_t n_characters);
int process_input(char *clean_buffer);
void tokenizer(char *clean_buffer);

/* selector.c */
void (*opcode_selector(int line_num))(stack_t **stack, unsigned int line_number);

/* op_functions1.c */
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
