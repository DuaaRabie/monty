#include "monty.h"

FILE *fp = NULL;
stack_t *stack = NULL;
char *topush = NULL, *line = NULL;
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

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - entry point
 * @argc: arguments count
 * @argv: arguments vector
 * Return: 0 success
 */
int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	int i = 0, j = 0;
	size_t len = 0;
	char *linewspace = NULL, *topush = topush, *line = line;
	void (*opfun)(stack_t **, unsigned int);

	check(argc, argv);
	while (1)
	{
		if (getline(&line, &len, fp) != -1)
		{
			line_number++;

			for (i = 0; i < (int)len; i++)
				if (line[i] != ' ')
					linewspace[j++] = line[i];

			opfun = get_op(linewspace);
			if (opfun == NULL)
			{
				fclose(fp);
				fprintf(stderr, "L%d: unknown instruction <opcode>\n", line_number);
				exit(EXIT_FAILURE);
			}
			if (strncmp(linewspace, "push", 4) == 0)
			{
				for (i = 4, j = 0; i < (int)(strlen(linewspace - 4)); i++, j++)
					topush[j] = linewspace[i];
			}
			opfun(&stack, line_number);
			free(line);
		}
		else
			break;
	}
	fclose(fp);
	return (0);
}
