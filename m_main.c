#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/**
 * main: This funciton will be the the main function to our monty porject.
 * @argc: This is the count of arguments passed to the program.
 * Author: Mikiashailu and Abdiali.
 * @argv: This pointer will point to an array of char pointers to arguments
 * Return: This will return the correct one if the code is correct.
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (dist_usage_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (dist_f_open_error(argv[1]));
	exit_code = dist_run_monty(script_fd);
	fclose(script_fd);
	return (exit_code);
}
