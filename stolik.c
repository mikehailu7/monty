#include "monty.h"
#include <string.h>

int dist_init_stack(stack_t **stack);
int dist_check_mode(stack_t *stack);
void dist_free_stack(stack_t **stack);

/**
 * dist_check_mode: This funciton will Checks
 * @stack: This pointer will point to a pointer to the top or bottom.
 * Author: Mikiashailu and Abdiali.
 */
int dist_check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}

/**
 * dist_init_stack: This funciton will Initializes a stack_t stack
 * @stack: A pointer to an unitialized stack_t stack.
 * Author: Mikiashailu and Abdiali.
 */
int dist_init_stack(stack_t **stack)
{
	stack_t *m;

	m = malloc(sizeof(stack_t));

	if (m == NULL)
		return (dist_malloc_error());

	m->n = STACK;
	m->prev = NULL;
	m->next = NULL;
	*stack = m;

	return (EXIT_SUCCESS);
}

/**
 * dist_free_stack: This funciton will Frees a stack_t stack.
 * @stack: This one is a pointer that points to the top stack.
 * Author: Mikiashailu and Abdiali.
 */
void dist_free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
