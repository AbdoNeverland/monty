#include "monty.h"
/**
 * free_array - free memory allocated to individual arrays
 * @tokens: arrays to be freed
 */

void free_array(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/**
 * parse_line - split the string by space
 * @str: input string
 * @nb_parts: nb parts
 * Return: array
 */
char **parse_line(char *str, long int *nb_parts)
{
	char *parsed;
	char **tokens;
	char *src;
	char *delim = " \n\t";
	int length = 0;
	int count_tokens = 0;

	src = _strdup(str);
	if (src == NULL)
	{
		free(src);
		return (NULL);
	}
	parsed = strtok(str, delim);
	while (parsed != NULL)
	{
		count_tokens++;
		parsed = strtok(NULL, delim);
	}
	count_tokens++;
	tokens = malloc(sizeof(char *) * count_tokens);
	if (tokens == NULL)
	{
		free(src);
		return (NULL);
	}

	parsed = strtok(src, delim);
	while (parsed != NULL)
	{
		tokens[length] = _strdup(parsed);
		length++;
		parsed = strtok(NULL, delim);
	}
	tokens[length] = NULL;
	if (nb_parts)
		*nb_parts = count_tokens;
	free(src);
	return (tokens);
}