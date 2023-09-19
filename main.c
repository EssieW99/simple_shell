#include "main.h"
/**
 * main - This is my main function for the simple shell project
 * @ac: argument count
 * @argv: argument vector
 * @envp: arguments variables
 * Return: 0 on success
 */
int main(int ac, char **argv, char **envp)
{
	char *prompt = "Prompt $ ";
	char *buffer = NULL;
	char *arg[10];
	size_t buff_size = 0;
	ssize_t nread;
	int status;
	pid_t child_processID;

	(void)ac;
	(void)argv;

	while (1)
	{
		if (isatty(0))
			printf("%s", prompt);
	nread = getline(&buffer, &buff_size, stdin);
	if (nread == -1)
	{
		free(buffer);
		termination();
	}
	remove_newline(buffer);
	tokenization_args(buffer, arg);
	child_processID = fork();
	if (child_processID == 0)
		executing(arg[0], arg, envp);

	else if (child_processID < 0)
		termination_child();
	else
		wait(&status);
	}
	free(buffer);
	return (0);
}
