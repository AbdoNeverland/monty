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
	long unsigned int i, j, k, line_number = 0;

	f = fopen(filename, "r");
	if (!f)
	{
		print("file not found\n");
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
		/*for (ii = 0; i < sizeof(inst) / sizeof(instruction_t); i++)
		{
			if (strcmp(inst[ii].opcode, tokens[0]) == 0)
			inst[ii].f(Store,line_number);
		}*/
		printf("%s<->%s#\n", tokens[0], tokens[1]);
		int n = atoi(tokens[1]);
		if (strcmp(tokens[0], "push") == 0)
		{
			add2stack(&Store, n);
		}
	}
	fclose(f);
	if (oneline)
		free(oneline);
}
/**
 * main - main fct
 * @argc: nb arguments
 * @argv: arguments
 * Return: int

void i_push(stack_t **stack, unsigned int line_number)
{
printf("push founded ::::: %d %d",7, line_number);
}*/
int main(int argc, char **argv)
{
	/*stack_t *Store = NULL;
	instruction_t Instructions[] = {{"poooooow",i_push}};*/
	if (argc != 2)
	{
		print("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	processFile(argv[1]);
	exit(EXIT_SUCCESS);
}
