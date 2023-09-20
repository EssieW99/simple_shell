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
	char *buffer = NULL;
	char *arg[10];
	size_t buff_size = 0;
	ssize_t nread;

	(void)ac;
	(void)argv;
	while (1)
	{
		if (isatty(0))
		{
			write(1, "Prompt $ ", 9);
		}
	nread = getline(&buffer, &buff_size, stdin);
	if (nread == -1)
	{
		free(buffer);
		termination();
	}
	remove_newline(buffer);
	tokenization_args(buffer, arg);
	executing(arg, envp);
	}
	free(buffer);
	return (0);
}
