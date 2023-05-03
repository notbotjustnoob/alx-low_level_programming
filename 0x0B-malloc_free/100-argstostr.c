#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of a program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to the concatenated string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	int i, j, len = 0, total_len = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* Find total length of concatenated string */
	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len])
			len++;
		total_len += len + 1; /* Add 1 for newline character */
	}

	/* Allocate memory for concatenated string */
	str = malloc(total_len * sizeof(char));
	if (str == NULL)
		return (NULL);

	/* Copy each argument to concatenated string */
	len = 0;
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j])
		{
			str[len] = av[i][j];
			len++;
			j++;
		}
		str[len] = '\n';
		len++;
	}

	/* Add terminating null byte */
	str[len] = '\0';

	return (str);
}
