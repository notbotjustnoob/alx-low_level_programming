#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - A recursive function that checks if a string is a palindrome
 * @s: The string to check
 *
 * Return: True if the substring is a palindrome, false otherwise
 */

int is_palindrome(char *s)
{
	if (strlen(s) <= 1)
		return (1);
	
	if (s[0] != s[strlen(s) - 1])
		return (0);
	
    printf("%s\n",&s[1]);
    char *new_s = malloc(strlen(s));
    strncpy(new_s, s, strlen(s)-1);
    new_s[strlen(s)-1] = '\0';
    
	return (is_palindrome(&s[1]) && is_palindrome(&s[strlen(s) - 1]));
}
