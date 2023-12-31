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
	char *buffer = NULL, *fullpath;
	char *arg[10];
	size_t buff_size = 0;
	ssize_t nread;

	(void)ac;
	(void)argv;
	while (1)
	{
		if (isatty(0))
			write(1, "Prompt $ ", 9);
	nread = getline(&buffer, &buff_size, stdin);
	if (nread == -1)
	{
		free(buffer);
		termination();
	}
	remove_newline(buffer);
	tokenization_args(buffer, arg);
	if (access(arg[0], X_OK) == 0)
		fullpath = arg[0];
	else
		fullpath = fetch_location(arg[0]);
	if (fullpath == NULL)
	{
		if (other_commands(arg) != 0)
			continue;
		else
			continue;
	}
	executing(fullpath, arg, envp);
	}
	free(buffer);
	return (0);
}
