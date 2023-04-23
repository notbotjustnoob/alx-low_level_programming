/**
 * is_palindrome - checks if a string is a palindrome
 * @s: the string to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
    int len = _strlen_recursion(s);

    if (len <= 1)
        return (1);
    return (_palindrome_secondary(s, 0, len - 1));
}

/**
 * _palindrome_secondary - helper function for is_palindrome
 * @s: the string to check
 * @start: the starting index of the substring to check
 * @end: the ending index of the substring to check
 *
 * Return: 1 if the substring is a palindrome, 0 otherwise
 */
int _palindrome_secondary(char *s, int start, int end)
{
    if (start >= end)
        return (1);
    if (s[start] != s[end])
        return (0);
    return (_palindrome_secondary(s, start + 1, end - 1));
}

/**
 * _strlen_recursion - helper function to get the length of a string
 * @s: the string to get the length of
 *
 * Return: the length of the string
 */
int _strlen_recursion(char *s)
{
    if (*s == '\0')
        return (0);
    return (_strlen_recursion(s + 1) + 1);
}
