#include "monty.h"
stack_t *Store = NULL;

/**
 * action_add - action
*/
void action_add(void)
{
	int n1 = remove_first(&Store);
	int n2 = remove_first(&Store);

	printf("%d\n", n1 + n2);
}
/**
 * processCode - process Code
 * @cmd: command
 * @value: value
 * @line_number: line_number
 * @value: value
 * @oneline: to free
 * @f: file
 */
void processCode(const char *cmd, const char *value,
				 int line_number, char **oneline, FILE *f)
{
	if (cmd[0] == 0 || strcmp(cmd, "nop") == 0)
	{
	}
	else if (strcmp(cmd, "add") == 0)
	{
		if (len_store(Store) < 2)
			fprintf(stderr, "L%d>: can't add, stack too short\n", line_number),
				raise_error(oneline, &f);
		action_add();
	}
	else if (strcmp(cmd, "pop") == 0)
	{
		if (!Store)
			fprintf(stderr, "L%d>: can't pop an empty stack\n", line_number),
			raise_error(oneline, &f);
		remove_first(&Store);
	}
	else if (strcmp(cmd, "pint") == 0)
	{
		if (!Store)
			fprintf(stderr, "L%d>: can't pint, stack empty\n", line_number),
				raise_error(oneline, &f);
		printf("%d\n", Store->n);
	}
	else if (strcmp(cmd, "push") == 0)
	{
		int n = atoi(value);

		/*printf("add %d to  stack\n", n);*/
		if (!is_number(value) || value[0] == 0)
			fprintf(stderr, "L%d: usage: push integer\n", line_number),
				raise_error(oneline, &f);
		add2stack(&Store, n);
	}
	else if (strcmp(cmd, "pall") == 0)
		print_stack(Store);
	else
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd),
			raise_error(oneline, &f);
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
