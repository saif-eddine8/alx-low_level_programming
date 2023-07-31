#include "lists.h"

/**
 * free_listint2 - frees a list of ints
 * @head: Pointer to the pointer to the head of the list to be freed
 *
 * Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *present, *temp;

	if (!head)
		return;

	node = *head;
	while (present)
	{
		temp = present;
		present = present->next;
		free(temp);
	}
	*head = NULL;
}
