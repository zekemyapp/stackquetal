#include "quetal_stack.h"

/* */
uint8_t stack_add_on_top (struct stack *s, uint8_t value)
{
    struct stack_e *e = malloc(sizeof(struct stack_e));
    e->e = value;
    e->next_e = NULL;
    e->prev_e = s->last;

    if(s->last == NULL) {
        // Empty stack
        s->first = e;
        s->size = 1;
    } else {
        // One or more elements in stack
        s->last->next_e = e;
        s->size += 1;
    }
    
    s->last= e;
    return s->last->e;
}

/* */
uint8_t stack_rm_from_top (struct stack *s)
{
    if (s == NULL || s->last == NULL)
        return 0;

    uint8_t e = s->last->e;
    struct stack_e *prev_e = s->last->prev_e;

    free(s->last);
    s->last = prev_e;
    
    if (s->last != NULL)
        s->last->next_e = NULL;
    else {
        // Empty
        s->first = NULL;
    }

    s->size -= 1;
    return e;
}

/* */
uint8_t stack_rm_from_bottom (struct stack *s)
{
    if (s == NULL || s->first == NULL)
        return 0;
        
    uint8_t e = s->first->e;
    struct stack_e *next_e = s->first->next_e;

    free(s->first);
    s->first = next_e;

    if (s->first != NULL)
        s->first->prev_e = NULL;
    else
        // Empty
        s->last = NULL;

    s->size -= 1;
    return e;
}

/* */
static uint8_t stack_rm_element (struct stack_e *e) 
{
    if (e == NULL)
        return 0; // TODO: Print error

    uint8_t value = e->e;

    e->prev_e->next_e = e->next_e;
    e->next_e->prev_e = e->prev_e;

    free(e);
    return value;
}

/* */
static uint8_t _stack_rm_from_index (struct stack *s, struct stack_e *e, int count, int index)
{
    if (e == NULL)
        return 0; // TODO: Print error

    if(count == index) {
        // If last element of the stack
        if (e->next_e == NULL) {
            return stack_rm_from_top(s);
        }
        else {
            return stack_rm_element(e);
        }
    }
    else
        if (e->next_e == NULL)
            return 0; // TODO: Print error

        return _stack_rm_from_index (s, e->next_e, count+1, index);
    
}

/* */
uint8_t stack_rm_from_index (struct stack *s, int index)
{
    // If first element of the stack
    if (index == 0) {
        // TODO: Handle empty stack
        return stack_rm_from_bottom(s);
    }

    return _stack_rm_from_index (s, s->first, 0, index);
}

/* */
static uint8_t _stack_get_index (struct stack *s, struct stack_e *e, int count, int index)
{
    if(e == NULL)
        return 0; // TODO: Handle error

    if (count == index)
        return e->e;
    else
    {
        if (e->next_e == NULL)
            return 0;
        else
            return _stack_get_index(s, e->next_e, count+1, index);
    }
}

/* */
uint8_t stack_get_index (struct stack *s, int index)
{
    if(s == NULL || s->first == NULL || s->last == NULL)
        return 0; // TODO: print error

    if(index == 0)
        return s->first->e;

    else
        return _stack_get_index(s, s->first, 0, index);
}

/* */
void stack_swap(struct stack_e *e1, struct stack_e *e2)
{
    if(e1 == NULL || e2 == NULL)
        return;

    uint8_t tmp = e2->e;
    e2->e = e1->e;
    e1->e = tmp;
}