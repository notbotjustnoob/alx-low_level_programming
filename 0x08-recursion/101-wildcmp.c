/**
 * wildcmp - Compares two strings, allowing for wildcard characters
 * @s1: First string to compare
 * @s2: Second string to compare, may contain wildcard character *
 *
 * Return: 1 if the strings can be considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0')
	{
		if (*s2 == '\0' || (*s2 == '*' && *(s2 + 1) == '\0'))
			return (1);
		return (0);
	}
	else if (*s2 == '\0')
		return (0);
	else if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));
		else if (*(s2 + 1) == '\0')
			return (1);
		else if (*s1 == '\0')
			return (wildcmp(s1, s2 + 1));
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	}
	else if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}