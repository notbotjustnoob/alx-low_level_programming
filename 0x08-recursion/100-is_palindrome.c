/**
 * is_palindrome - checks if a string is a palindrome
 * @s: the string to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
    int len = 0;
    char *start, *end;

    while (s[len] != '\0')
        len++;

    start = s;
    end = s + len - 1;

    while (end > start)
    {
        if (*start != *end)
            return (0);

        start++;
        end--;
    }

    return (1);
}
