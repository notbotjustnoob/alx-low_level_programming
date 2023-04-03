/**
 * _strspn - Gets the length of a prefix substring.
 * @s: The string to be searched.
 * @accept: The bytes to accept.
 *
 * Return: The number of bytes in the initial segment of s which consist only
 *         of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, count = 0;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
			{
				count++;
				break;
			}
		}

		if (!accept[j])
			break;
	}

	return (count);
}
