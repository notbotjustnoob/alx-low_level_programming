#include <stdio.h>
#include <stdlib.h>

/**
 * main - Calculates addition
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: 0 if the program ran successfully, 1 otherwise
 */
int main(int argc, char *argv[])
{
	int i, num, sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		num = atoi(argv[i]);
		if (num == 0 && *argv[i] != '0')
		{
			printf("Error\n");
			return (1);
		}
		else if (num < 0)
		{
			printf("Error\n");
			return (1);
		}
		sum += num;
	}

	printf("%d\n", sum);
	return (0);
}
