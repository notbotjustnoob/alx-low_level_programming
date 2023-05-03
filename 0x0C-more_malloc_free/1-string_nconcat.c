#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - Concatenates two strings.
 * @s1: The first string to be concatenated.
 * @s2: The second string to be concatenated.
 * @n: The maximum number of bytes to be used from s2.
 *
 * Return: A pointer to the concatenated string.
 *         NULL on failure.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat_str;
	unsigned int s1_len, s2_len, i, j;

	s1 = (s1 == NULL ? "" : s1);
	s2 = (s2 == NULL ? "" : s2);

	s1_len = strlen(s1);
	s2_len = strlen(s2);

	if (n >= s2_len)
		concat_str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	else
		concat_str = malloc(sizeof(char) * (s1_len + n + 1));

	if (concat_str == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		concat_str[i] = s1[i];

	for (j = 0; s2[j] != '\0' && j < n; j++, i++)
		concat_str[i] = s2[j];

	concat_str[i] = '\0';

	return (concat_str);
}
