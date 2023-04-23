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
    // Base case: an empty string or a string of one character is a palindrome
    if (strlen(s) <= 1)
        return true;
    
    // Compare the first and last characters of the string
    if (s[0] != s[strlen(s) - 1])
        return false;

    // Recursively check the substring without the first and last characters
    return (is_palindrome(&s[1]) && is_palindrome(&s[strlen(s) - 1]));
}
