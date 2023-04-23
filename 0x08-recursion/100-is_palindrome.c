/**
 * is_palindrome - checks if a string is a palindrome
 * @s: the string to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
    int len = 0;

    while (s[len])
        len++;

    return check_palindrome(s, 0, len - 1);
}

/**
 * check_palindrome - recursive function to check if a string is a palindrome
 * @s: the string to check
 * @start: the starting index to check
 * @end: the ending index to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int check_palindrome(char *s, int start, int end)
{
    if (start >= end)
        return 1;

    if (s[start] != s[end])
        return 0;

    return check_palindrome(s, start + 1, end - 1);
}
