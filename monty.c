#include "monty.h"
stack_t *Store = NULL;

/**
 * processFile - process File
 * @filename: filename
 */
void processFile(char *filename)
{
	FILE *f;
	char *oneline = NULL;
	char tokens[10][20];
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
 * processCode - process Code
 * @cmd: command
 * @value: value
 * @line_number: line_number
 * @value: value
 * @oneline: to free
 */
void processCode(const char *cmd, const char *value,
				 int line_number, char **oneline, FILE *f)
{

	if (strcmp(cmd, "push") == 0)
	{
		int n = atoi(value);

		/*printf("add %d to  stack\n", n);*/
		if (!is_number(value) || value[0] == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(*oneline);
			fclose(f);
			exit(EXIT_FAILURE);
		}
		add2stack(&Store, n);
	}
	else if (strcmp(cmd, "pall") == 0)
	{
		/*printf("print stack\n");*/
		print_stack(Store);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
		free(oneline);
		fclose(f);
		exit(EXIT_FAILURE);
	}
}
/**
 * main - main fct
 * @argc: nb arguments
 * @argv: arguments
 * Return: int
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	processFile(argv[1]);
	free_stack(Store);
	exit(EXIT_SUCCESS);
}
