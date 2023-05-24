#include "monty.h"
/**
 * our_pint: This will print the top of the stack.
 * @head: stack head
 * Authors: MIkiashailu and abdiali
*/
void our_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(tax.doc);
		free(tax.cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
printf("%d\n", (*head)->n);
}
