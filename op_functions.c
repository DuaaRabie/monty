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

	for (i = 0; i < (int)strlen(vars.topush); i++)
		if (isdigit(vars.topush[i]) == 0)
		{
			free(vars.topush);
			fclose(vars.fp);
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	n = atoi(vars.topush);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free(vars.topush);
		fclose(vars.fp);
		fprintf(stderr, "Error: malloc failed\n");
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
	while (temp != NULL)
	{
		fprintf(stdout ,"%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * op_pint - prints the value at the top
 * @stack: stach header
 * @line_number: line number
 * Return: nothing
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		fprintf(stdout, "%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_pop - removes the top element
 * @stack: stach header
 * @line_number: line number
 * Return: nothing
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp != NULL)
	{
		temp = temp->next;
		free(*stack);
		if (temp != NULL)
			temp->prev = NULL;
		*stack = temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
