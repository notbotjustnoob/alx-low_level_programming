#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list safely
 * @h: double pointer to the beginning of the list
 *
 * Return: size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *temp;

	if (!h || !*h)
		return (0);

	current = *h;
	*h = NULL;

	while (current)
	{
		count++;
		temp = current;
		current = current->next;

		if (temp <= current)
		{
			free(temp);
			break;
		}
		free(temp);
	}
	return (count);
}
