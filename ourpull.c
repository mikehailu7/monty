#include "monty.h"
/**
 * our_pall: This function will prints the stack
 * @head: This declares head of the stack
 * Author: Mikiashailu and Abdiali.
*/
void our_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
