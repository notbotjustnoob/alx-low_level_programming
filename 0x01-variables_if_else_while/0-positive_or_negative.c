#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */

int main(void)
{
    int i;
    srand(time(0));
    i = rand() - RAND_MAX / 2;
    printf("%d ", i);
    if (i > 0)
    {
        printf("is positive\n");
    }
    else if (i == 0)
    {
        printf("is zero\n");
    }
    else
    {
        printf("is negative\n");
    }
    return (0);
}
