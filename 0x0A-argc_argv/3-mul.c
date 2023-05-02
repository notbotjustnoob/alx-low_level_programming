#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the result of a product and a new line
 * @argc: The number of arguments passed
 * @argv: An array of pointers to the arguments
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	result = num1 * num2;

	printf("%d\n", result);

	return (0);
}
