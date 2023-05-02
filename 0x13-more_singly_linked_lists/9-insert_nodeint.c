#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @head: Pointer to the head of the list
 * @index: Index of the list where the new node should be added
 * @n: Data to be stored in the new node
 *
 * Return: Address of the new node or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int index, int n)
{
	listint_t *new_node, *current_node = *head;
	unsigned int i = 0;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	if (index == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	while (current_node != NULL && i < index - 1)
	{
		current_node = current_node->next;
		i++;
	}

	if (current_node == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = current_node->next;
	current_node->next = new_node;

	return (new_node);
}
