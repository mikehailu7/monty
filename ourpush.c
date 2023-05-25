#include "monty.h"
/*
 * our_push: This function will add nodes to the stack.
 * @head: This shows the head of the stack.
 * @counter: This shows the line_number.
 * Author: Mikiashailu and Abdiali.
 */
void our_push(stack_t **head, unsigned int counter)
{
      int a,
      fla = 0,
      k = 0;

	if (tax.argu)
	{
		if (tax.argu[0] == '-')
			k++;
		for (; tax.argu[k] != '\0'; k++)
		{
			if (tax.argu[k] > 57 || tax.argu[k] < 48)
				fla = 1; }
		if (fla == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(tax.doc);
			free(tax.cont);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(tax.doc);
		free(tax.cont);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	a = atoi(tax.argu);
	if (tax.li == 0)
		addnode(head, a);
	else
		addqueue(head, a);
}
