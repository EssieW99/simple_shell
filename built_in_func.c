#include "main.h"

/**
 * other_commands - Checks for built-in functions
 * @arg: Input string
 *
 * Return: Is 0
 */
int other_commands(char **arg)
{

	if (strcmp(arg[0], "exit") == 0)
	{
			exit(0);
	}
	else if (strcmp(arg[0], "env") == 0)
	{
		print_current_environment();
	}
	else if (strcmp(arg[0], "cd") == 0)
	{
		if (arg[1] == NULL)
			chdir(getenv("HOME"));
		else
			chdir(arg[1]);
	}
	return (0);
}
/**
 * print_current_environment - Prints the current environment
 *
 */
void print_current_environment(void)
{
	char **environment = environ;

	while (*environment != NULL)
	{
		print_any_string(*environment);
		print_any_string("\n");
		environment++;
	}
}
/**
 * free_args - Frees input string
 * @arg: Input string
 *
 */
void free_args(char **arg)
{
	int i;

	for (i = 1; arg[i] != NULL; i++)
	{
		free(arg[i]);
	}
}
