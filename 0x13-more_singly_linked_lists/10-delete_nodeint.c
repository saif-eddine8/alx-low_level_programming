#include "lists.h"

/**
 * delete_nodeint_at_index - deletes node at given index
 * @head: pointer address to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *node, *prev_node;
	unsigned int y = 0;

	if (!head || !*head)
		return (-1);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (y == index)
		{
			prev_node->next = node->next;
			free(node);
			return (1);
		}
		y++;
		prev_node = node;
		node = node->next;
	}
	return (-1);
}
