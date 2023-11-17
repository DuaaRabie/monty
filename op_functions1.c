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
	int n;

	topush_check(line_number);
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
		fprintf(stdout, "%d\n", temp->n);
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
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
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

	if (*stack != NULL || stack == NULL)
	{
		*stack = (*stack)->next;
		free(temp);
		if (*stack != NULL)
			(*stack)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_swap - swap the top two elements
 * @stack: stach header
 * @line_number: line number
 * Return: nothing
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1 = *stack;
	stack_t *temp2;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp2 = (*stack)->next;
		*stack = temp2;
		temp1->next = temp2->next;
		if (temp1->next != NULL)
			temp1->next->prev = temp1;
		temp2->next = temp1;
		temp1->prev = temp2;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

}
