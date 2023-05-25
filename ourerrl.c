#include "monty.h"


int short_stack_error(unsigned int line_number, char *op);
int dist_div_error(unsigned int line_number);
int dist_pop_error(unsigned int line_number);
int dist_div_error(unsigned int line_number);
int dist_pop_error(unsigned int line_number, char *message);

/**
 * dist_dist_pop_error: This funciton will Print pop error messages for empty stacks.
 * @line_number: Line number in script where error occured.
 * Author: Mikiashailu and Abdiali.
 * Return: this will return exit failure.
 */
int dist_pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}


/**
 * pint_error: This function will Prints pint error messages for empty stacks.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * Author: Mikiashailu and Abdiali.
 * Return: this will return exit failure.
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}


/**
 * dist_short_stack_error: This function will Prints monty math function error messages.
 * @op: Operation where the error occurred.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * Author: Mikiashailu and Abdiali.
 * Return: this will return exit failure.
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * dist_div_error: This funciton will Prints division error message.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * Author: Mikiashailu and Abdiali.
 * Return: this will return exit failure.
 */
int dist_div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * dist_pop_error - Prints pchar error messages for empty stacks.
 * @message: The corresponding error message to print.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * Author: Mikiashailu and Abdiali.
 * Return: this will return exit failure.
 */
int dist_pop_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
