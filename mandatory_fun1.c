#include "monty.h"

void our_monty_pall(stack_t **stack, unsigned int line_number);
void our_monty_push(stack_t **stack, unsigned int line_number);
void our_monty_pop(stack_t **stack, unsigned int line_number);
void our_monty_pint(stack_t **stack, unsigned int line_number);

/**
 * our_monty_pall: This fucntion will Prints the values of a stack_t.
 * @stack: THis pointer will point to the top mode node of a stack_t.
 * Author: Mikiashailu and Abdiali.
 * @line_number: THis will contain the current postion of the stack.
 */
void our_monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpo = (*stack)->next;


	while (tmpo)
	{
		printf("%d\n", tmpo->n);
		tmpo = tmpo->next;
	}
	(void)line_number;
}

/**
 * our_monty_push: THis fucntion will add a new number to the stack.
 * @line_number: THis will contain the current postion of the stack.
 * Author: Mikiashailu and Abdiali.
 * @stack: This pointer points to the top of the stack.
 */
void our_monty_push(stack_t **stack, unsigned int line_number)
{
	int m;
	stack_t *tmpo, *newl;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dist_set_op_tok_error(dist_malloc_error());
		return;
	}


	if (op_toks[1] == NULL)
	{
		dist_set_op_tok_error(no_int_error(line_number));
		return;
	}


	for (m = 0; op_toks[1][m]; m++)
	{
		if (op_toks[1][m] == '-' && m == 0)
			continue;
		if (op_toks[1][m] < '0' || op_toks[1][m] > '9')
		{
			dist_set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);


	if (dist_check_mode(*stack) == STACK)
	{
		tmpo = (*stack)->next;
		new->prev = *stack;
		new->next = tmpo;
		if (tmpo)
			tmpo->prev = newl;
		(*stack)->next = newl;
	}
	else
	{
		tmpo = *stack;
		while (tmpo->next)
			tmpo = tmpo->next;
		new->prev = tmpo;
		new->next = NULL;
		tmp->next = newl;
	}
}

/**
 * our_monty_pint: This function will Prints the top value of a stack_t.
 * @stack: This pointer will point to the top mode node of a stack_t.
 * Author: Mikiashailu and Abdiali.
 * @line_number: THis will contain the current postion of the stack.
 */
void our_monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		dist_set_op_tok_error(pint_error(line_number));
		return;
	}
	printf("%d\n", (*stack)->next->n);
}

/**
 * our_monty_pop: This functions will Removes the top value element of a stack_t.
 * @stack: This pointer will point to the top mode node of a stack_t linked list.
 * Author: Mikiashailu and Abdiali.
 * @line_number: THis will contain the current postion of the stack.
 */
void our_monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;
	if ((*stack)->next == NULL)
	{
		dist_set_op_tok_error(dist_pop_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
