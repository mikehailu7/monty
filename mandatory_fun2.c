#include "monty.h"

void our_monty_sum(stack_t **stack, unsigned int line_number);
void our_monty_swap(stack_t **stack, unsigned int line_number);
void our_monty_nop(stack_t **stack, unsigned int line_number);
/**
 * our_monty_nop: THis function will Do nothing.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * Author: Mikiashailu and Abdiali.
 * @line_number: THis will contain the current postion of the stack.
 */
void our_monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * our_monty_swap: THis function will Swaps the top two value elements of a stack_t.
 * @stack: This pointer will point to the top mode node of a stack_t linked list.
 * Author: Mikiashailu and Abdiali.
 * @line_number: THis will contain the current postion of the stack.
 */
void our_monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpo;
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		dist_set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
	}

	tmpo = (*stack)->next->next;
	(*stack)->next->next = tmpo->next;
	(*stack)->next->prev = tmpo;
	if (tmpo->next)
		tmpo->next->prev = (*stack)->next;
	tmpo->next = (*stack)->next;
	tmpo->prev = *stack;
	(*stack)->next = tmpo;
}

/**
 * our_monty_sum: THis fucntion will Adds the top two values of a stack_t linked list.
 * @line_number: This is a current working line number of a Monty.
 * @stack: This pointer points to the top mode node of a stack_t.
 * Author: Mikiashailu and Abdiali.
 * @line_number: THis will contain the current postion of the stack.
 */
void our_monty_sum(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		dist_set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}


	(*stack)->next->next->n += (*stack)->next->n;
	our_monty_pop(stack, line_number);
