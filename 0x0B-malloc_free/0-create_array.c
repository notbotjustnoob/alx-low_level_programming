#include "main.h"
#include <stdlib.h>

/**
* create_array - creates an array of chars, and initializes it
* @size: size of the array
* @c: specific char to initialize the array with
*
* Return: pointer to the created array,
*		or NULL if size is 0 or if malloc fails
*/
char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	if (size == 0)
		return (NULL);

	arr = malloc(size * sizeof(char));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = c;

	return (arr);
}
