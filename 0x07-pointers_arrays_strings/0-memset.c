/**
 * _memset - fills the first n bytes of the memory area pointed to by s
 * with the constant byte b
 * @s: pointer to the memory area to be filled
 * @b: the constant byte
 * @n: number of bytes to be filled starting from the memory address pointed by s
 *
 * Return: pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}
