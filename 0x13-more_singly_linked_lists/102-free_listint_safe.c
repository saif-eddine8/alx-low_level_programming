#include "lists.h"
#include <stdlib.h>

/**
 * find_listint_loop_fl - finds a loop in a linked list
 *
 * @head: linked list to search
 *
 * Return: node  address where loop starts/returns, NULL if no loop
 */
listint_t *find_listint_loop_fl(listint_t *head)
{
	listint_t *ptr, *end;

	if (head == NULL)
		return (NULL);

	for (end = head->next; end != NULL; end = end->next)
	{
		if (end == end->next)
			return (end);
		for (ptr = head; ptr != end; ptr = ptr->next)
			if (ptr == end->next)
				return (end->next);
	}
	return (NULL);
}

/**
 * free_listint_safe - frees a listint list, even if it has a loop
 *
 * @h: head of list
 *
 * Return: nodes number freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *next, *lpNode;
	size_t len;
	int lp = 1;

	if (h == NULL || *h == NULL)
		return (0);

	lpNode = find_listint_loop_fl(*h);
	for (len = 0; (*h != lpNode || lp) && *h != NULL; *h = next)
	{
		len++;
		next = (*h)->next;
		if (*h == lpNode && lp)
		{
			if (lpNode == lpNode->next)
			{
				free(*h);
				break;
			}
			len++;
			next = next->next;
			free((*h)->next);
			lp = 0;
		}
		free(*h);
	}
	*h = NULL;
	return (len);
}
