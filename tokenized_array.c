#include"monty.h"

/**
 * tokanized_array - tokanized_array
 * @str: string i want to tokanize
 * Return: tokanized_array
*/

char **tokanized_array(char *str)
{
	char **arr;
	char *dub, *ptr;
	int i = 0;

	 dub = _strdup(str);

	ptr = strtok(str, " \n\t");
	while (ptr != NULL)
	{
		ptr = strtok(NULL, " \n\t");
		i++;
	}

arr = malloc(sizeof(char *) * (i + 1));
if (arr == NULL)
{
	perror("Error: malloc failed\n");
	free(dub);
	exit(EXIT_FAILURE);
}


i = 0;
ptr = strtok(dub, " \n\t");
while (ptr)
{
	arr[i] = _strdup(ptr);
	ptr = strtok(NULL, " \n\t");
	i++;
}
arr[i] = NULL;
free(dub);
return (arr);
}

/**
 * free_all_array - free_all_array
 * @arr: array of pointers to the commands
 * Retuen: nothing
*/
void free_all_array(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}

	free(arr);
}
/**
 * free_stack - free_list
 * @head: pointer to the list
 * Return: nothing
*/
void free_stack(stack_t *head)
{
	stack_t *current = head;

		while (head)
		{
		head = head->next;
		free(current);
		current = head;
		}
}
/**
 * free_stack_from_func - free_list
 * @head: pointer to the list
 * Return: nothing
*/
void free_stack_from_func(stack_t **head)
{
	stack_t *current = *head;

		while (*head)
		{
		*head = (*head)->next;
		free(current);
		current = *head;
		}
}
