#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints a linked list, even if it has a loop
 * @head: pointer to head of linked list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current, *check;
	size_t count = 0;

	current = head;
	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;
		current = current->next;
		if (current == head)
			break;
		if (current == NULL)
			return (count);
		check = head;
		while (check != current)
		{
			if (current->next == check)
			{
				printf("-> [%p] %d\n", (void *)current->next, current->next->n);
				exit(98);
			}
			check = check->next;
		}
	}
	return (count);
}
