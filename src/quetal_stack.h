#ifndef _STACK_H
#define _STACK_H

/* El Stack Que Tal
 * A simple "Stack" that also works
 * a any type of list:
 * FIFO, LIFO, bidirectional 
 * 
 * Copyright zekemyapp 2020 */

#include <stdlib.h>

/* Element of the stack
 * Type: uint8_t */
struct stack_e
{
    uint8_t e;
    struct stack_e *next_e;
    struct stack_e *prev_e;
};

/* Stack Header
 * Holds first and last elements of the stack
 * Size: Current size of the stack */
struct stack
{
    struct stack_e *first;
    struct stack_e *last;
    uint32_t size;
};

/* Add a new element to the top of the list */
uint8_t stack_add_on_top (struct stack *s, uint8_t value);

/* Remove an element from the top of the list */
uint8_t stack_rm_from_top (struct stack *s);

/* Remove an element from the bottom of the list */
uint8_t stack_rm_from_bottom (struct stack *s);

/* Remove an element from a given position on the list */
uint8_t stack_rm_from_index (struct stack *s, int index);

/* Get an element from a given position on the list */
uint8_t stack_get_index (struct stack *s, int index);

/* Swap the values of two elements */
void stack_swap(struct stack_e *e1, struct stack_e *e2);

#endif  /* _STACK_H */