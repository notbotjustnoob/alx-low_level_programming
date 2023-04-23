int is_prime_secondary(int n, int i);

/**
 * is_prime_number - checks if a number is a prime number
 * @n: the number to check
 *
 * Return: 1 if n is a prime number, 0 otherwise
 */
int is_prime_number(int n)
{
	/* Negative numbers, 0, and 1 are not prime */
	if (n < 2)
		return (0);

	/* Check if n is divisible by any number less than n */
	return (is_prime_secondary(n, 2));
}

/**
 * is_prime_secondary - checks if n is divisible by i
 * @n: the number to check
 * @i: the divisor to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_secondary(int n, int i)
{
	/* Base case: n is divisible by i, so it's not prime */
	if (n % i == 0)
		return (0);

	/* Base case: n is not divisible by any number less than i, so it's prime */
	if (i * i > n)
		return (1);

	/* Check the next divisor */
	return (is_prime_secondary(n, i + 1));
}
