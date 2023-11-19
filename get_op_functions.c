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
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{NULL, NULL}
	};
	int ops_len = (int)((sizeof(ops) / sizeof(ops[0])) - 1);

	while (i < ops_len)
	{
		if (strcmp(s, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (ops[i].f);
}
