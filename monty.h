#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

extern char **op_toks;

/**
 * struct stack_s: THis structure is doubly linked list
 * @n: TTHis is an integer.
 * @next: This pointer points to the next element of the stack.
 * @prev: This pointer points to the previous element of the stack.
 * Author: Mikiashailu and Abdiali.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s: THis structure is opcode and its function.
 * @f: This one is a function to handle the opcode.
 * @opcode: This one is the opcode.
 * Author: Mikiashailu and Abdiali.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void dist_free_stack(stack_t **stack);
int dist_init_stack(stack_t **stack);
int dist_check_mode(stack_t *stack);
void dist_free_tokens(void);
unsigned int dist_token_arr_len(void);
int dist_run_monty(FILE *script_fd);
void dist_set_op_tok_error(int error_code);

void our_monty_push(stack_t **stack, unsigned int line_number);
void our_monty_pall(stack_t **stack, unsigned int line_number);
void our_monty_pint(stack_t **stack, unsigned int line_number);
void our_monty_pop(stack_t **stack, unsigned int line_number);
void our_monty_swap(stack_t **stack, unsigned int line_number);
void our_monty_sum(stack_t **stack, unsigned int line_number);
void our_monty_nop(stack_t **stack, unsigned int line_number);


char **struct_tow(char *str, char *delims);
char *conv_string(int n);



int dist_usage_error(void);
int dist_malloc_error(void);
int dist_f_open_error(char *filename);
int dist_ unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int dist_div_error(unsigned int line_number);
int dist_pop_error(unsigned int line_number, char *message);


#endif
