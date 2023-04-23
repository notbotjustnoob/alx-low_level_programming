#include <stdbool.h>
#include <string.h>

/**
 * is_palindrome - A recursive function that checks if a string is a palindrome
 * @s: The string to check
 *
 * Return: True if the substring is a palindrome, false otherwise
 */

bool is_palindrome(char *s)
{
    if (strlen(s) <= 1)
        return true;
    
    if (s[0] != s[strlen(s) - 1])
        return false;

    return (is_palindrome(&s[1]) && is_palindrome(&s[strlen(s) - 1]));
}
