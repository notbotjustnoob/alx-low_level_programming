/**
 * is_palindrome - checks if a string is a palindrome
 * @s: the string to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
    int len = 0;
    char *p;

    if (s == NULL)
        return (0);

    p = s;
    while (*p != '\0')
    {
        len++;
        p++;
    }

    return (check_palindrome(s, len));
}

/**
 * check_palindrome - recursive helper function to check if a string is a palindrome
 * @s: the string to check
 * @len: the length of the string
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int check_palindrome(char *s, int len)
{
    if (len <= 1)
        return (1);

    if (*s != s[len - 1])
        return (0);

    return (check_palindrome(s + 1, len - 2));
}
