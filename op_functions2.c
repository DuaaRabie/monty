#include "monty.h"

/**
 * op_nop - do nothing
 * @stack: stach header
 * @line_number: line number
 * Return: nothing
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * op_add - add the top two elements
 * @stack: stach header
 * @line_number: line number
 * Return: nothing
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int n1;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		n1 = (*stack)->n;
		*stack = (*stack)->next;
		free(temp);
		(*stack)->prev = NULL;
		(*stack)->n = (*stack)->n + n1;
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_sub - subtract the top two elements
 * @stack: stach header
 * @line_number: line number
 * Return: nothing
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int n1;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		n1 = (*stack)->n;
		*stack = (*stack)->next;
		free(temp);
		(*stack)->prev = NULL;
		(*stack)->n = (*stack)->n - n1;
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
