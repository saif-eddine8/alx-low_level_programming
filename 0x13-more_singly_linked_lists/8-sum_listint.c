#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data
 * @head: Pointer to the head of the linked list.
 *
 * Return: The sum of all the data (n) in the linked list.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *node = head;

	while (node != NULL)
	{
		sum += node->n;
		node = node->next;
	}

	return (sum);
}
