#include "monty.h"
/**
 * processFile - process File
 * @filename: filename
 */
void processFile(char *filename)
{
	FILE *f;
	char *oneline = NULL;
	char tokens[1024][512];
	size_t line_length = 0;
	ssize_t line_length_readed;
	unsigned long int i, j, k, line_number = 0;

	f = fopen(filename, "r");
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((line_length_readed = getline(&oneline, &line_length, f)) != -1)
	{
		tokens[0][0] = 0;
		line_number++;
		for (i = 0, j = 0, k = 0;; i++)
		{
			if (oneline[i] != ' ' && oneline[i] != '\n' &&
				oneline[i] != '\t' && oneline[i] != '\0')
				tokens[j][k] = oneline[i], k++;
			else
			{
				if (tokens[j][0] != 0 || oneline[i] == '\n' || oneline[i] == '\0')
				{
					tokens[j][k] = '\0';
					j++, k = 0;
					tokens[j][0] = 0;
				}
			}
			if (!oneline[i])
				break;
		}
		processCode(tokens[0], tokens[1], line_number, &oneline, f);
	}
	fclose(f);
	if (oneline)
		free(oneline);
}
/**
 * is_number - is number
 * @str: string
 * Return: 1 or 0
 */
int is_number(const char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != '-' && (str[i] < '0' || str[i] > '9'))
			return (0);
	}
	return (1);
}
/**
 * raise_error - raise error
 * @e1: error 1
 * @e2: error 2
 * @oneline: oneline
 * @f: file
 * @line_number: line number
 */
void raise_error(const char *e1, const char *e2,
char **oneline, FILE **f, int line_number)
{
	fprintf(stderr, "L%d>: %s%s\n", line_number, e1, e2);
	if (*oneline)
		free(*oneline);
	fclose(*f);
	free_stack(Store);
	exit(EXIT_FAILURE);
}
