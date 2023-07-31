#include "lists.h"

/**
 * listint_len - prints linked lists
 * @h: pointer to first node
 *
 * Return: list size
 */
size_t listint_len(const listint_t *h)
{
	size_t y = 0;

	while (h)
	{
		h = h->next;
		y++;
	}
	return (y);
}
