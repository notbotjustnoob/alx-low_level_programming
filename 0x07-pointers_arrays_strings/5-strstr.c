/**
 * _strstr - finds the first occurrence of the substring needle in the
 *           string haystack.
 * @haystack: the string to search in
 * @needle: the substring to search for
 *
 * Return: a pointer to the beginning of the located substring, or NULL
 *         if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	char *haystack_ptr, *needle_ptr;

	while (*haystack)
	{
		haystack_ptr = haystack;
		needle_ptr = needle;

		while (*haystack_ptr && *needle_ptr && *haystack_ptr == *needle_ptr)
		{
			haystack_ptr++;
			needle_ptr++;
		}

		if (!*needle_ptr)
			return (haystack);

		haystack++;
	}

	return (NULL);
}
