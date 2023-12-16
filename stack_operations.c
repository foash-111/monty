#define _GNU_SOURCE
#include"monty.h"

/**
 * add_function - add top  two element on the stack
 * @stack: pointer to my linked list
 * @num: file line counter
*/

void add_function(stack_t **stack, unsigned int num)
{
	stack_t *top = NULL;
	int temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		top = *stack;

		temp = top->n;
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		(*stack)->n += temp;
		free(top);

	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
}


/**
 * sub_function - add top  two element on the stack
 * @stack: pointer to my linked list
 * @num: file line counter
*/
void sub_function(stack_t **stack, unsigned int num)
{
	stack_t *top = NULL;
	int temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		top = *stack;

		temp = top->n;
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		(*stack)->n -= temp;
		free(top);

	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul_function - add top  two element on the stack
 * @stack: pointer to my linked list
 * @num: file line counter
*/
void mul_function(stack_t **stack, unsigned int num)
{
	stack_t *top = NULL;
	int temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		top = *stack;

		temp = top->n;
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		(*stack)->n *= temp;
		free(top);

	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
}


/**
 * div_function - add top  two element on the stack
 * @stack: pointer to my linked list
 * @num: file line counter
*/
void div_function(stack_t **stack, unsigned int num)
{
	stack_t *top = NULL;
	int temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		top = *stack;

		temp = top->n;
		if (temp == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", num);
			exit(EXIT_FAILURE);
		}
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		(*stack)->n /= temp;
		free(top);

	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
}

/**
 * mod_function - add top  two element on the stack
 * @stack: pointer to my linked list
 * @num: file line counter
*/
void mod_function(stack_t **stack, unsigned int num)
{
	stack_t *top = NULL;
	int temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		top = *stack;

		temp = top->n;
		if (temp == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", num);
			exit(EXIT_FAILURE);
		}
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		(*stack)->n %= temp;
		free(top);

	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
}
