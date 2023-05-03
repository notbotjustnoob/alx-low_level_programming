#include <stdlib.h>

/**
 * array_range - creates an array of integers containing all values
 *               from min to max (inclusive).
 * @min: the minimum value to include in the array.
 * @max: the maximum value to include in the array.
 *
 * Return: On success, a pointer to the newly created array.
 *         On failure, NULL.
 */

int *array_range(int min, int max)
{
    int *arr, i;

    if (min > max)
        return (NULL);

    arr = malloc((max - min + 1) * sizeof(int));
    if (arr == NULL)
        return (NULL);

    for (i = 0; i <= max - min; i++)
        arr[i] = min + i;

    return (arr);
}
