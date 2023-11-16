#include "monty.h"

/**
 * op_push - push opcode
 * @stack: stach header
 * @line_number: line number
 * Return: nothing
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int n, i;

	for (i = 0; i < (int)strlen(topush); i++)
		if (isdigit(topush[i]) == 0)
		{
			free(line);
			fclose(fp);
			fprintf(stderr, "L%d: usage: push integer", line_number);
			exit(EXIT_FAILURE);
		}
	n = atoi(topush);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free(line);
		fclose(fp);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	new->prev = NULL;
	*stack = new;
	new->n = n;
}

/**
 * op_pall - pull all
 * @stack: stach header
 * @line_number: line number
 * Return: nothing
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	if (temp != NULL)
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
}
