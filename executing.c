#include "main.h"
/**
 * executing - This function to execute commands
 * @str: the command to execute
 * @array: array of commands passed by user
 * @envp environment variables
 * Return: always o
 */
int executing(char *str, char **array, char **envp)
{
	if (execve(str, array, envp) == -1)
	{
		perror("Could not execute");
		exit(0);
	}
	return (0);
}
/**
 * termination_child - used to terminate child if error occurs
 */
void termination_child(void)
{
	perror("Could not create child");
	exit(1);
}
/**
 * tokenization_args - function to tokenize user input
 * @str: string to tokenize
 * @argument: vector array
 */
void tokenization_args(char *str, char **argument)
{
	int counter = 0;

	argument[counter] = strtok(str, " \t\n");
	while (argument[counter] != NULL)
	{
		counter++;
		argument[counter] = strtok(NULL, " \t\n");
	}
	argument[counter] = NULL;
}
