#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM " \t\n"

/**
 * count_words - count the number of words in a string
 * @str: the string to count words in
 *
 * Return: the number of words in the string
 */
static int count_words(char *str)
{
	int i, count = 0, in_word = 0;

	for (i = 0; str[i] != '\0'; i++) {
		if (strchr(DELIM, str[i])) {
			if (in_word) {
				count++;
				in_word = 0;
			}
		} else {
			in_word = 1;
		}
	}

	if (in_word) {
		count++;
	}

	return count;
}

/**
 * strtow - split a string into words
 * @str: the string to split
 *
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str)
{
	int i, j, count;
	char **words, *word;

	if (str == NULL || *str == '\0') {
		return NULL;
	}

	count = count_words(str);
	words = malloc(sizeof(char *) * (count + 1));

	if (words == NULL) {
		return NULL;
	}

	for (i = 0; i < count; i++) {
		while (*str != '\0' && strchr(DELIM, *str)) {
			str++;
		}

		word = malloc(sizeof(char) * strlen(str) + 1);

		if (word == NULL) {
			for (j = 0; j < i; j++) {
				free(words[j]);
			}
			free(words);
			return NULL;
		}

		for (j = 0; str[j] != '\0' && !strchr(DELIM, str[j]); j++) {
			word[j] = str[j];
		}

		word[j] = '\0';
		words[i] = word;
		str += j;
	}

	words[i] = NULL;

	return words;
}
