#include "monty.h"

/**
 * get_op - get the opcode function
 * @s: string of the opcode
 * Return: pointer to the function
 */
void (*get_op(char *s))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL}
	};

	while (i < 2)
	{
		if (strncmp(s, ops[i].opcode, 4))
			return (ops[i].f);
		i++;
	}
	return (ops[i].f);
}
