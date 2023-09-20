#include "main.h"
/**
 * executing - This function to execute command
 * @arg: Input string
 * @envp: environment variables
 *
 * Return: always 0
 */
int executing(char **arg, char **envp)
{
	pid_t child_processID;
	int status;

	child_processID = fork();

	if (child_processID == 0)
	{
		if (execve(arg[0], arg, envp) == -1)
		{
			perror("Could not execute");
			exit(0);
		}
	}
	else if (child_processID < 0)
	{
		termination_child();
	}
	else
	{
		wait(&status);
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
