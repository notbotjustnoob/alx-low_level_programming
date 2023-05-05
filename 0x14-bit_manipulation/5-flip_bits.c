/**
 * flip_bits - returns the number of bits you would need to flip to get from
 * one number to another.
 * @n: the first number.
 * @m: the second number.
 *
 * Return: the number of bits that need to be flipped to convert n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flip = n ^ m;
	unsigned int count = 0;

	while (flip)
	{
		count += flip & 1;
		flip >>= 1;
	}

	return (count);
}
