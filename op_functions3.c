#include "monty.h"

/**
 * op_mod - mod the top two elements
 * @stack: stack header
 * @line_number: line number
 * Return: nothing
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int n1;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		n1 = (*stack)->n;
		if (n1 == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		*stack = (*stack)->next;
		free(temp);
		(*stack)->prev = NULL;
		(*stack)->n = (*stack)->n % n1;
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
