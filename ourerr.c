#include "monty.h"

int dist_usage_error(void);
int dist_malloc_error(void);
int dist_f_open_error(char *filename);
int dist_ unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);

/**
 * dist_usage_error: function Prints usage error messages.
 * Author: Mikiashailu and Abdiali.
 * Return: will return correct if the code is right.
 */
int dist_usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * dist_malloc_error: This fucntion will Prints malloc error messages.
 * Author: Mikiashailu and Abdiali.
 * Return: Return exit always.
 */
int dist_malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * dist_f_open_error: This function will Prints file opening err messages file name.
 * @filename: Name of file failed to open
 * Author: Mikiashailu and Abdiali.
 * Return: return exit always.
 */
int dist_f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * dist_dist_ unknown_op_error: This will Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @line_number: Line number in Monty bytecodes file where error occured.
 * Author: Mikiashailu and Abdiali.
 * Return: return exit if the code is correct.
 */
int dist_ unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * dist_no_int_error: This function will Prints invalid monty argument error messages.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * Author: Mikiashailu and Abdiali.
 * Return: (EXIT_FAILURE) always.
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);

	return (EXIT_FAILURE);
}
