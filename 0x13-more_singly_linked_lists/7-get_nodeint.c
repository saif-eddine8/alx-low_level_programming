#include "lists.h"

/**
 * get_nodeint_at_index - returns node at index
 * @head: Pointer to the head of the list
 * @index: index of node
 *
 * Return: pointer to node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *node = head;

	while (node != NULL)
	{
		if (count == index)
			return (node);
		node = node->next;
		count++;
	}

	return (NULL);
}
