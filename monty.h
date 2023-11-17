#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

/* monty.h file for ALX monty project */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly-linked list depicting a stack (or queue).
 * @n: integer
 * @prev: pts to previous element of stack (or queue)
 * @next: pts to next element of stack (or queue)
 *
 * Description: doubly-linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its func
 * @opcode: the opcode
 * @f: func to handle opcode
 *
 * Description: opcode and its funct
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file ops*/
int len_chars(FILE *);
int parse_line(char *buffer, int line_number, int format);
void find_func(char *, char *, int, int);
void read_file(FILE *);
void open_file(char *file_name);

/*stack ops*/
void free_nodes(void);
stack_t *create_node(int n);
void add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);
void print_stack(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void swap_nodes(stack_t **, unsigned int);
void print_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);

/*maths ops with nodes*/
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);

void mul_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);

void mod_nodes(stack_t **, unsigned int);

/*str ops*/
void print_char(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);

/*err hanlding*/
void err(int error_code, ...);
void more_err(int error_code, ...);

void string_err(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif
