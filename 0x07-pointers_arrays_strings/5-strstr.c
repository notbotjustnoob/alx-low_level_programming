#include "main.h"
/**
 * _strstr - locates a substring
 * @haystack: pointer to the string to search
 * @needle: pointer to the substring to search for
 *
 * Return: pointer to the beginning of the located substring, or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	char *h = haystack;
	char *n = needle;

	while (*h)
	{
		if (*h == *n)
		{
			char *temp = h;

			while (*temp && *n && *temp == *n)
			{
				temp++;
				n++;
			}
			if (*n == '\0')
				return (h);
			n = needle;
		}
		h++;
	}
	return (NULL);
}
