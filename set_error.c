#include "monty.h"

/**
 * dist_set_op_tok_error: This function will Sets last element
 * @error_code: Integer to store as a string in op_toks.
 */
void dist_set_op_tok_error(int error_code)
{
	int token_leng = 0,
	    k = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	token_leng = dist_token_arr_len();
	new_toks = malloc(sizeof(char *) * (token_leng + 2));
	if (!op_toks)
	{
		dist_malloc_error();
		return;
	}
	while (k < token_leng)
	{
		new_toks[k] = op_toks[i];
		k++;
	}
	exit_str = conv_string(error_code);
	if (!exit_str)
	{
		free(new_toks);
		dist_malloc_error();
		return;
	}
	new_toks[k++] = exit_str;
	new_toks[] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
