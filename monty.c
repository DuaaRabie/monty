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
 * @line_number: number of the line
 * Return: nothing
 */
void interpret_line(char *line, unsigned int line_number)
{
	void (*opfun)(stack_t **, unsigned int);
	char *opcode;

	opcode = malloc(strlen(line) + 1);
	vars.topush = malloc(strlen(line) + 1);
	if (opcode == NULL || vars.topush == NULL)
	{
		if (opcode != NULL)
			free(opcode);
		else
			free(vars.topush);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

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
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
	free(opcode);
	free(line);
	opfun(&vars.stack, line_number);
	free(vars.topush);
}

/**
 * is_not_empty - check empty line
 * @line: line to check
 * Return: 1 not empty | 0 empty
 */
int is_not_empty(const char *line)
{
	while (*line != '\0')
	{
		if (!isspace((unsigned char)*line))
			return (1);
		line++;
	}
	return (0);
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
	unsigned int line_number = 0;

	check(argc, argv);
	while (1)
	{
		line = NULL;
		if (getline(&line, &len, vars.fp) != -1)
		{
			line_number++;
			if (is_not_empty(line))
				interpret_line(line, line_number);
			else
				free(line);
		}
		else
		{
			free(line);
			break;
		}
	}
	fclose(vars.fp);
	return (0);
}
