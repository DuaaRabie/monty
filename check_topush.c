#include "monty.h"

/**
 * check_topush - check to push
 *
 * Return: nothing
 */
void topush_check(unsigned int line_number)
{
	int i;

	if (vars.topush[0] == '\0')
	{
		free(vars.topush);
		fclose(vars.fp);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; vars.topush[i] != '\0'; i++)
		if (isdigit(vars.topush[i]) == 0)
		{
			if (vars.topush[i] != '-' && vars.topush[i] != '+')
			{
				free(vars.topush);
				fclose(vars.fp);
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
}
