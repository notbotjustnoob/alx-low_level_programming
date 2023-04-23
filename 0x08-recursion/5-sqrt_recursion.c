/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to find the square root of
 * @i: the current number to start with
 *
 * Return: the natural square root of n, or -1 if n does not have a natural
 * square root
 */
int _sqrt_secondary(int n, int i)
{
	if (i * i == n)
		return (i);
	else if (i * i > n)
		return (-1);
	return (_sqrt_secondary(n, i + 1));
}

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt_secondary(n, 0));
}
