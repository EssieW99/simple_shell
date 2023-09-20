#include "main.h"

/**
 * fetch_location - Gets the PATH location
 * @array: User input
 *
 * Return: Is path_vector or NULL
 */
char *fetch_location(char *array)
{
	char *path_vector;

	path_vector = getenv("PATH");
	if (path_vector != NULL)
	{
		path_vector = pathing(path_vector, array);
		return (path_vector);
	}
	return (NULL);
}
/**
 * pathing - Tokenizes the PATH variable
 * @path: The PATH variable
 * @array: Input string
 *
 * Return: Is NULL or fullpath
 */
char *pathing(char *path, char *array)
{
	char *path_copy, *token, *fullpath = NULL;

	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		free(array);
		perror("Unable to allocate memory");
		exit(1);
	}
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		fullpath = malloc(strlen(array) + 1 + strlen(token) + 1);
		if (fullpath == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		strcpy(fullpath, token);
		strcat(fullpath, "/");
		strcat(fullpath, array);
		strcat(fullpath, "\0");
		if (access(fullpath, X_OK) == 0)
		{
			free(path_copy);
			return (fullpath);
		}
		free(fullpath);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
