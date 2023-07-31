#include "lists.h"

/**
 * pop_listint - pops head node of list
 * @head: Pointer to the pointer to the head of the list
 *
 * Return: value
 */
int pop_listint(listint_t **head)
{
	listint_t *present;
	int n;

	if (!head || !*head)
		return (0);

	present = (*head)->next;
	n = (*head)->n;
	free(*head);
	*head = present;
	return (n);
}
