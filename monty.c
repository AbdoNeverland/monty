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
 * action_swap - action
 */
void action_swap(void)
{
	int n1 = Store->n;

	Store->n = Store->next->n;
	Store->next->n = n1;
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
	else if (strcmp(cmd, "swap") == 0)
	{
		if (len_store(Store) < 2)
			raise_error("can't swap, stack too short", "", oneline, &f, line_number);
		action_swap();
	}
	else if (strcmp(cmd, "add") == 0)
	{
		if (len_store(Store) < 2)
			raise_error("can't add, stack too short", "", oneline, &f, line_number);
		action_add();
	}
	else if (strcmp(cmd, "pop") == 0)
	{
		if (!Store)
			raise_error("can't pop an empty stack", "", oneline, &f, line_number);
		remove_first(&Store);
	}
	else if (strcmp(cmd, "pint") == 0)
	{
		if (!Store)
			raise_error("can't pint, stack empty", "", oneline, &f, line_number);
		printf("%d\n", Store->n);
	}
	else if (strcmp(cmd, "push") == 0)
	{
		if (!is_number(value) || value[0] == 0)
			raise_error("usage: push integer", "", oneline, &f, line_number);
		add2stack(&Store, atoi(value));
	}
	else if (strcmp(cmd, "pall") == 0)
		print_stack(Store);
	else
		raise_error("unknown instruction ", cmd, oneline, &f, line_number);
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
