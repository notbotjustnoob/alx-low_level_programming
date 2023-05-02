#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: Pointer to a pointer to the first element of the list.
 * @n: Value to store in the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *current_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	/* Initialize the new node */
	new_node->n = n;
	new_node->next = NULL;

	/* If the list is empty, make the new node the head */
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		/* Otherwise, traverse the list to find the last node */
		current_node = *head;
		while (current_node->next != NULL)
			current_node = current_node->next;

		/* Add the new node at the end of the list */
		current_node->next = new_node;
	}

	return (new_node);
}
