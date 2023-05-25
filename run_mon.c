#include "monty.h"
#include <string.h>

void dist_free_tokens(void);
unsigned int dist_token_arr_len(void);
int dist_is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int dist_run_monty(FILE *script_fd);

void dist_free_tokens(void)
{
	size_t a = 0;
	if (op_toks == NULL)
		return;
	for (a = 0; op_toks[a]; a++)
		free(op_toks[a]);
	free(op_toks);
}

/**
 * dist_is_empty_line: This will Checks if a line read from getline only contains delimiters.
 * @delims: A string of delimiter characters.
 * @line: A pointer to the line.
 * Author: Mikiashailu and Abdiali.
 * Return: It will return the Length of current op_toks.
 */
int dist_is_empty_line(char *line, char *delims)
{
	int m, a;


	for (m = 0; line[m]; m++)
	{
		for (a = 0; delims[a]; a++)
		{
			if (line[m] == delims[a])
				break;
		}
		if (delims[a] == '\0')
			return (0);
	}


	return (1);
}

/**
 * dist_token_arr_len: This function will Gets the length of current op_toks.
 * Author: Mikiashailu and Abdiali.
 * Return: This will return the Length of current op_toks.
 */
unsigned int dist_token_arr_len(void)
{
	unsigned int token_length = 0;
	while (op_toks[token_length])
		token_length++;
	return (token_length);
}

/**
 * dist_run_monty: This function will display Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 * Author: Mikiashailu and Abdiali.
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int dist_run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int lin_num = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (dist_init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		lin_num++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (dist_is_empty_line(line, DELIMS))
				continue;
			dist_free_stack(&stack);
			return (dist_malloc_error());
		}
		else if (op_toks[0][0] == '#')
		{
			dist_free_tokens();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			dist_free_stack(&stack);
			exit_status = dist_unknown_op_error(op_toks[0], lin_num);
			dist_free_tokens();
			break;
		}
		prev_tok_len = dist_token_arr_len();
		op_func(&stack, lin_num);
		if (dist_token_arr_len() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			dist_free_tokens();
			break;
		}
		dist_free_tokens();
	}
	dist_free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (dist_malloc_error());
	}

	free(line);
	return (exit_status);
}

/**
 * get_op_func: This function will Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 * Author: Mikiashailu and Abdiali.
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", our_monty_push},
		{"pall", our_monty_pall},
		{"pint", our_monty_pint},
		{"pop", our_monty_pop},
		{"swap", our_monty_swap},
		{"add", our_monty_sum},
		{"nop", our_monty_nop},
		{NULL, NULL}
	};
	int z;


	for (z = 0; op_funcs[z].opcode; z++)
	{
		if (strcmp(opcode, op_funcs[z].opcode) == 0)
			return (op_funcs[z].f);
	}

	return (NULL);
}
