#define _GNU_SOURCE
#include"monty.h"

/**
 * pint_function - print top element on the stack
 * @stack: pointer to my linked list
 * @num: file line counter
*/
void pint_function(stack_t **stack, unsigned int num)
{
	stack_t *top = NULL;

	if (*stack != NULL)
	{
		top = *stack;
		printf("%d\n", top->n);

	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", num);
		exit(EXIT_FAILURE);
	}
}
/**
 * pop_function - delete top element on the stack
 * @stack: pointer to my linked list
 * @num: file line counter
*/
void pop_function(stack_t **stack, unsigned int num)
{
	stack_t *top = NULL;

	if (*stack != NULL)
	{
		top = *stack;
		(*stack) = top->next;
		if (*stack)
		top->next->prev = NULL;

		free(top);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num);
		exit(EXIT_FAILURE);
	}
}
/**
 * swap_function - swap top  two element on the stack
 * @stack: pointer to my linked list
 * @num: file line counter
*/
void swap_function(stack_t **stack, unsigned int num)
{
	stack_t *top = NULL;
	int temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		top = *stack;

		temp = top->n;
		top->n = top->next->n;
		top->next->n = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop_function - don't do anything
 * @stack: pointer to my linked list
 * @num: file line counter
*/
void nop_function(stack_t **stack, unsigned int num)
{
	(void) stack;
	(void) num;
}


/**
 * main - Entry point
 *
 * Description: A C program that prints with put function
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0 (Success)
*/

int main(int argc, char **argv)
{
	FILE *my_file = NULL;
	stack_t *stack = NULL;

if (argc != 2)
{
	perror("USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

	my_file = fopen(argv[1], "r");
	if (my_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	enter_file(my_file, &stack);

	fclose(my_file);
	free_stack(stack);
	return (0);
}
