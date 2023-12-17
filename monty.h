#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE

#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdbool.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



void enter_file(FILE *my_file, stack_t **stack);
int execute_function(char **arr, unsigned int line_number, stack_t **stack);
int check_push(char **arr, unsigned int line_number, stack_t **stack);

void push_function(stack_t **stack, int num);
void pall_function(stack_t **stack, unsigned int num);
void pint_function(stack_t **stack, unsigned int num);
void pop_function(stack_t **stack, unsigned int num);
void swap_function(stack_t **stack, unsigned int num);
void nop_function(stack_t **stack, unsigned int num);

void add_function(stack_t **stack, unsigned int num);
void sub_function(stack_t **stack, unsigned int num);
void mul_function(stack_t **stack, unsigned int num);
void div_function(stack_t **stack, unsigned int num);
void mod_function(stack_t **stack, unsigned int num);

void pchar_function(stack_t **stack, unsigned int line_number);
void pstr_function(stack_t **stack, unsigned int line_number);
void rotl_function(stack_t **stack, unsigned int line_number);
void rotr_function(stack_t **stack, unsigned int line_number);

void free_stack(stack_t *head);
void free_stack_from_func(stack_t **head);

int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, int n);
char *_strdup(char *str);
int _atoi(char *s);

int _putchar(char c);
char **tokanized_array(char *str);
void free_all_array(char **arr);

#endif
