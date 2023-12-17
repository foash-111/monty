#define _GNU_SOURCE
#include"monty.h"

/**
 * pchar_function - print top element on the stack
 * @stack: pointer to my linked list
 * @line_number: file line counter
*/
void pchar_function(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL;

	if (*stack != NULL)
	{
		top = *stack;
		if (top->n > 0 && top->n < 127)
		printf("%c\n", top->n);
		else
		{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
		}

	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr_function - print our stack data
 * @stack: --
 * @line_number: our file line counter
 */
void pstr_function(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL;
	(void)line_number;
	if (*stack != NULL)
	{
		top = *stack;
		while (top && top->n > 0 && top->n < 127)
		{
			printf("%c", top->n);
			top = top->next;
		}
		printf("\n");

	}
	else
	printf("\n");
}


/**
 * rotl_function - print our stack data
 * @stack: --
 * @line_number: our file line counter
 */
void rotl_function(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int temp = 0;

	(void) line_number;

	if (*stack != NULL)
	{
		current = *stack;
		temp = current->n;

		while (current->next)
		{
			current->n = current->next->n;
			current = current->next;
		}
		current->n = temp;
	}
}
/**
 * rotr_function - print our stack data
 * @stack: --
 * @line_number: our file line counter
 */
void rotr_function(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL, *tail = NULL;
	int temp = 0, stack_len = 0, i = 0;

	(void) line_number;

	if (*stack != NULL)
	{
		current = *stack;
		tail = *stack;
		while (tail->next)
		{
			tail = tail->next;
			stack_len++;
		}

		stack_len = stack_len / 2;

		while (i < stack_len)
		{
		temp = current->n;
		current->n = tail->n;
		tail->n = temp;

		current = current->next;
		tail = tail->prev;
		i++;
		}

	}
}
