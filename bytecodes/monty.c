#include "monty.h"

FILE *fp;
stack_t *stack;
char *topush, *line;

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
	char *linewspace = NULL;
	void (*opfun)(stack_t **, unsigned int);

	check(argc, argv);
	while (1)
	{
		/*line = NULL;
		topush = NULL;
		linewspace = NULL;*/
		if (getline(&line, &len, fp) != -1)
		{
			printf("line = %slength = %ld\n", line, strlen(line));
			linewspace = malloc(strlen(line) * sizeof(char) + 1);
			line_number++;
			for (i = 0, j = 0; i < (int)(strlen(line)); i++)
				if (line[i] != ' ' && line[i] != '\n')
					linewspace[j++] = line[i];
			linewspace[j] = '\0';
			printf("linewspace = %s, length = %ld\n", linewspace, strlen(linewspace));
			opfun = get_op(linewspace);
			if (opfun == NULL)
			{

				fclose(fp);
				fprintf(stderr, "L%d: unknown instruction <opcode>\n", line_number);
				exit(EXIT_FAILURE);
			}
			if (strncmp(linewspace, "push", 4) == 0)
			{
				topush = malloc(strlen(linewspace) - 3);
				for (i = 4, j = 0; i <= (int)(strlen(linewspace)); i++, j++)
					topush[j] = linewspace[i];
				printf("topush = %s, length = %ld\n", topush, strlen(topush));
			}
			opfun(&stack, line_number);
			printf("next line\n");
			if (strncmp(linewspace, "push", 4) == 0)
				free(topush);
			free(linewspace);	
			free(line);
		}
		else
			break;
	}
	fclose(fp);
	return (0);
}
