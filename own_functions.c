#include "main.h"
/**
 * _atoi - Converts string to an integer
 * @str: Input string
 *
 * Return: Is value of result
 */
int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
	{
		str++;
	}

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}

	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
