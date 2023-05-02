#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head, *loop_start = NULL;
	size_t count = 0;

	while (current)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;
		current = current->next;

		if (current == loop_start)
		{
			fprintf(stderr, "Error: infinite loop detected, exiting\n");
			exit(98);
		}

		if (current && current < loop_start)
			loop_start = current;
	}

	return (count);
}
