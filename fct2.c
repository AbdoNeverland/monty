#include "monty.h"

/**
 * remove_first -remove first
 * @head: head
 * Return: int
*/
int remove_first(stack_t **head)
{
	stack_t *t;
	int n = 0;

if (*head)
{
t = (*head)->next;
n = (*head)->n;
free(*head);
*head = t;
}
return (n);
}
/**
 *delete_at_index - delete node
 *@head: the list
 *@index: index where to add
 * Return: 1 or -1
 */
int delete_at_index(stack_t **head, unsigned int index)
{
	unsigned int i = 0;
	stack_t *prv = NULL, *h;

	h = *head;
	if (!h)
		return (-1);
	do {
		if (index == i && h)
		{
			if (prv)
			{
				prv->next = h->next;
				if (h->next)
					h->next->prev = prv;
			}
			if (i == 0)
			{
				*head = h->next;
				(*head)->prev = NULL;
			}
			free(h);
			return (1);
		}
		if (!h)
			break;
		prv = h;
		h = h->next;
		i++;
	} while (1);
	return (-1);
}
/**
 * len_store - len of a list
 *@h: list
 * Return: int
 */
size_t len_store(stack_t *h)
{
	size_t n = 0;

	while (h)
	{
		h = h->next;
		n++;
	}
	return (n);
}
