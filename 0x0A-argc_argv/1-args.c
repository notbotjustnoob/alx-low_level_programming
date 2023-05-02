#include <stdio.h>

/**
 * main - Prints the number of arguments passed to it
 * @argc: The number of arguments passed
 * @argv: An array of pointers to the arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	printf("%d\n", argc - 1);
	(void)argv;
	return (0);
}
