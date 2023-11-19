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

/**
 * op_pchar - prints the char at the top
 * @stack: stack header
 * @line_number: line number
 * Return: nothing
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	int c;

	if (*stack != NULL)
	{
		c = (*stack)->n;
		if (c >= 0 && c <= 127)
		{
			fprintf(stdout, "%c\n", c);
		}
		else
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_str - prints the str at the top
 * @stack: stack header
 * @line_number: line number
 * Return: nothing
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int c;

	(void)line_number;
	if (temp != NULL)
	{
		while (temp != NULL)
		{
			c = temp->n;
			if (c > 0 && c <= 127)
			{
				putchar(c);
				temp = temp->next;
			}
			else
				break;
			
		}
		putchar('\n');
	}
	else
		fprintf(stdout, "\n");
}
