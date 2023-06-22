#include "monty.h"

/**
 * remove_first -remove first
 * @head: head
*/
void remove_first(stack_t **head)
{
	stack_t *t;

if (*head)
{
t = (*head)->next;
free(*head);
*head = t;
}
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
