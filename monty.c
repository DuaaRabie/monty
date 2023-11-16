#include "monty.h"

struct global_var vars;

/**
 * check - to check the command
 * @argc: arguments count
 * @argv: arguments vector
 * Return: nothing
 */
void check(int argc, char **argv)
{

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	vars.fp = fopen(argv[1], "r");
	if (vars.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}

/**
 * interpret_line - interpret line
 * @line: the read line
 * Return: nothing
 */
void interpret_line(char *line)
{
	void (*opfun)(stack_t **, unsigned int);
	char *opcode;
	static unsigned int line_number;

	opcode = malloc(strlen(line) + 1);
	vars.topush = malloc(strlen(line) + 1);
	line_number++;

	if (sscanf(line, "%s %s", opcode, vars.topush) == 2)
	{
		;
	}
	opfun = get_op(opcode);
	if (opfun == NULL)
	{
		free(opcode);
		free(line);
		free(vars.topush);
		fclose(vars.fp);
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
	free(opcode);
	free(line);
	opfun(&vars.stack, line_number);
	free(vars.topush);
}
/**
 * main - entry point
 * @argc: arguments count
 * @argv: arguments vector
 * Return: 0 success
 */
int main(int argc, char **argv)
{
	size_t len = 0;
	char *line;

	check(argc, argv);
	while (1)
	{
		line = NULL;
		if (getline(&line, &len, vars.fp) != -1)
			interpret_line(line);
		else
		{
			free(line);
			break;
		}
	}
	fclose(vars.fp);
	return (0);
}
