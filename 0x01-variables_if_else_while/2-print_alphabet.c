#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char letter = 'a';

    putchar(letter);
    while (letter != 'z')
    {
        letter++;
        putchar(letter);
    }
    putchar('\n');

    return (0);
}
