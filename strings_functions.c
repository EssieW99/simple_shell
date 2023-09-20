/**
 * _strlen - this function gets the length of a string
 * @str: string to get the length
 * Return: returns the length of the string
 */
int _strlen(char *str)
{
	int length = 0;
	int i;

	for (i = 0; str[i] != NULL; i++)
	{
		length++;
	}
	return (length);
}
/**
 * _strcat - appends source string to the destination string
 * @dest: destination string
 * @src: source string
 * Return: returns a pointer to the resulting string destination.
 */
char *_strcat(char *dest, char *src)
{
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}
/**
 * _strcpy - copies the source string to destination
 * @dest: destination string
 * @source: source string
 * Return: a pointer to the destination string.
 */
char *_strcpy(char *dest, char *source)
{
	int i = 0;

	while (source[i] != '\0')
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcmp - function compares two strings s1 and s2
 * @str1: string one
 * @str2: string two
 * Return: 0 if two strings are equal, -1 if s1 is less that s2,
 * positive value if s1 is grater that s2
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}
	if (*str1 == '\0' && *str2 != '\0')
	{
		return (-1);
	}
	else if (*str1 != '\0' && *str2 == '\0')
	{
		return (1);
	}
	return (0);
}
/**
 * _strdup - Returns a pointer to a new string which is a
 *  duplicate of the string passed as a parameter
 *  @str: string that we need to duplicate
 *  Return: A pointer to the duplicate string
 */
char *_strdup(const char *str)
{
	char *pointer;
	int i, length = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	while (str[i] != '\0')
	{
		length++;
	}
	pointer = malloc(length + 1);
	if (pointer == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= length; i++)
	{
		ptr[i] = str[i];
	}
	return (pointer);
}
