#include "lists.h"
#include <stdlib.h>

/**
 * find_listint_loop - Finds the start of a loop
 * @head: Pointer to the head of the linked list
 *
 * Return: The address of the node where the loop starts
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *end;

	if (head == NULL)
		return (NULL);
	for (end = head->next; end != NULL; end = end->next)
	{
		if (end == end->next)
			return (end);
		for (slow = head; slow != end; slow = slow->next)
			if (slow == end->next)
				return (end->next);
	}

	return (NULL);
}
