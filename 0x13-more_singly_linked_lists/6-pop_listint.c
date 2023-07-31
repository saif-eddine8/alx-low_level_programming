#include "lists.h"

/**
 * pop_listint - pops head node of list
 * @head: Pointer to the pointer to the head of the list
 *
 * Return: value
 */
int pop_listint(listint_t **head)
{
	listint_t *node;
	int d;

	if (!head || !*head)
		return (0);

	node = (*head)->next;
	d = (*head)->d;
	free(*head);
	*head = node;
	return (d);
}
