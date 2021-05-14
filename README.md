# Monty - LIFO, FIFO

Monty 0.98 is a scripting language that is first compiled into Monty bytecode like Python. It relies on a unique stack with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Requirements

- All files compiled on Ubuntu 14.04 LTS
- Allow to use max one global variable
- Usage: monty file
  - where file is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to your program, print the error message ```USAGE: monty file```, followed by a new line, and exit with the status ```EXIT_FAILURE```
- If, for any reason, it’s not possible to open the file, print the error message ```Error: Can't open file <file>```, followed by a new line, and exit with the status ```EXIT_FAILURE```
   - where <file> is the name of the file
- If the file contains an invalid instruction, print the error message ```L<line_number>: unknown instruction <opcode>```, followed by a new line, and exit with the status ```EXIT_FAILURE```
   - where is the line number where the instruction appears.
   - Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
   - it executed properly every line of the file
   - it finds an error in the file
   - an error occured.
- If you can’t malloc anymore, print the error message ```Error: malloc failed```, followed by a new line, and exit with status ```EXIT_FAILURE```.
- You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …).

## Compile
```$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty```

```$ ./monty file_monty.m```

## Examples

there is a file called 00.m for the example that will contain:
the implementation of the code with push and pall:

      $ cat bytecodes/00.m
      push 1
      push 2
      push 3
      pall
      $ ./monty bytecodes/00.m
      3
      2
      1

Implementing the pint opcode:

      $ cat bytecodes/06.m
      push 1
      pint
      push 2
      pint
      push 3
      pint
      $ ./monty bytecodes/06.m
      1
      2
      3

Implementing the pchar opcode:

      $ cat bytecodes/28.m
      push 69
      pchar
      $ ./monty bytecodes/28.m
      E

## Functions

| Funcion | Description |
|---------|-------------|
| main.c  | contains the call to system functions |
| op_functions1.c | contains the call to the function push, pall, pint and pop |
| op_functions2.c | contains the call to the function swap, add, nop, sub and div |
| op_rotr.c | rotates the stack to the bottom |
| processing_file_name.c | contains the buffer_clean and processes each line of the file introduced. |
| selector.c |  selects function of opcode related to the line of monty |
|stack_operations.c | determines the length of a stack |
| strings.c| Determines the strings length. |

## Authors ✒️

- **Adriana Echeverri** - [adri-er](https://github.com/adri-er)
- **Juan Sebastian Tovar** - [juanstm200](https://github.com/juanstm200)
