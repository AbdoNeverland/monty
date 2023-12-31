#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef MONTY_H
#define MONTY_H

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
extern stack_t *Store;
void processFile(char *filename);
int is_number(const char *str);
char *_strdup(char *str);
int getlineFromFile(char **line, int *len, int file_descriptor);
void free_array(char **array);
char **parse_line(char *str, long int *nb_parts);
stack_t *add2stack(stack_t **head, const int n);
void processCode(const char *cmd, const char *value, int line_number, char **, FILE *);
size_t print_stack(const stack_t *h);
void free_stack(stack_t *head);
int delete_at_index(stack_t **head, unsigned int index);
int remove_first(stack_t **head);
size_t len_store(stack_t *h);
void raise_error(const char *e1, const char *e2, char **oneline, FILE **f, int line_number);

#endif
