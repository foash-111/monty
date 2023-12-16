#define _GNU_SOURCE
#include "monty.h"

/**
 * enter_file - enter_file
 * @my_file: pointer to the file
 * @stack: pointer to my linked-list
 */
void enter_file(FILE *my_file, stack_t **stack)
{
	char *str = NULL, **arr = NULL;
	size_t in_len = 0;
	int reads_chars = 0;
	unsigned int line_number = 1;

	while (1)
	{
		reads_chars = getline(&str, &in_len, my_file);
		if (reads_chars == -1)
		{
			if (str != NULL)
				free(str);
			break;
		}
		if (str[reads_chars - 1] == '\n')
			str[reads_chars - 1] = '\0';
		if (str[0] == '\0')
		{
			str = NULL;
			continue;
		}
		arr = tokanized_array(str);
		if (arr[0] != NULL)
		{
			if (arr[0][0] == '#')
			{
			free_all_array(arr);
			arr = NULL;
			continue;
			}
			execute_function(arr, line_number, stack);
			free_all_array(arr);
			arr = NULL;
		}
		else
		{ free_all_array(arr); }
		line_number++;
	}
}

/**
 * execute_function - execute_function
 * @arr: tokanized array
 * @line_number: line counter
 * @stack: pointer to my linked list
 */
void execute_function(char **arr, unsigned int line_number, stack_t **stack)
{
	int i = 0, flag = 0;
	instruction_t op_func[] = {{"pall", pall_function},
	{"pint", pint_function}, {"pop", pop_function},
	{"swap", swap_function}, {"add", add_function},
	{"nop", nop_function}, {"sub", sub_function},
	{"mul", mul_function}, {"div", div_function},
	{"mod", mod_function}, {NULL, NULL}};
if (!(check_push(arr, line_number, stack)))
{
	while (i < 10)
	{
		if (strcmp(arr[0], op_func[i].opcode) == 0)
		{
			op_func[i].f(stack, line_number);
			flag = 1;
		}
		if (flag == 1)
		break;
		i++;
	}
	if (i == 10)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, arr[0]);
		exit(EXIT_FAILURE);
	}
}
}
/**
 * check_push - check_push
 * @arr: tokanized array
 * @line_number: line counter
 * @stack: pointer to my linked list
 * Return: boolean value
 */
int check_push(char **arr, unsigned int line_number, stack_t **stack)
{
	char *check_int = NULL;
	int i = 0, flag = 1;

	if ((_strcmp(arr[0], "push") == 0))
	{
		if (arr[1] != NULL)
		{
			check_int = arr[1];

			while (check_int[i])
			{
				if ((check_int[0] == '-') || (check_int[i] >= '0' && check_int[i] <= '9'))
				{
					i++;
					continue;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			if (flag == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}

			push_function(stack, _atoi(arr[1]));
			return (1);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
/**
 * push_function - push element to the stack
 * @num: data that we will add inside our node
 * @stack: pointer to my linked list
 */
void push_function(stack_t **stack, int num)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;

	if (*stack == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->prev = NULL;
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

/**
 * pall_function - print our stack data
 * @stack: --
 * @num: our file line counter
 */
void pall_function(stack_t **stack, unsigned int num)
{
	stack_t *top = NULL;
	(void)num;
	if (*stack != NULL)
	{
		top = *stack;
		while (top)
		{
			printf("%d\n", top->n);
			top = top->next;
		}
	}
}
