#include "monty.h"
/**
 * _strdup - copy an array of chars to a new memory
 *@str: string to copy
 * Return: char *
 */
char *_strdup(char *str)
{
	unsigned int i = 0;
	unsigned int size = 0;
	char *array;

	if (str == NULL)
		return (NULL);
	while (str[size] != '\0')
		size++;
	array = malloc((1 + size) * sizeof(char));
	if (!array)
		return (NULL);
	do {
		array[i] = str[i];
	} while (i++ < size);
	array[size] = '\0';
	return (array);
}

/**
 * getlineFromFile - get line from file descriptor
 *@line: where to store line buffer
 *@len: line lenght
 *@file_descriptor: the file
 * Return: int
*/
int getlineFromFile(char **line, int *len, int file_descriptor)
{
	char c[1];
	char buff[1024];
	int n, i;

	buff[0] = '\0';
	i = 0;
	while ((n = read(file_descriptor, c, 1)) > 0)
	{

		if (c[0] == '\n')
		{
			buff[i] = '\0';
			break;
		}
		buff[i++] = c[0];
	}
	*len = i + 1;
	*line = strdup(buff);
	return (n);
}
/**
 * add_dnodeint - adds new node at the beginning
 *@head: the head of the list
 *@n: n
 *Return: number of nodes
 */
stack_t *add2stack(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (*head);
}
