#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

// Create an empty stack.

Stack *stack_create(void)
{
    Stack *p = malloc(sizeof(Stack));
    //p.size = ?
    //p->capacity = ?
    p->data = malloc(p->size * sizeof(double));

}

// Destroy the stack.
void stack_destroy(Stack *s);

// Push a value onto the stack.
void stack_push(Stack *s, double value)
{
    //kapaciteten dubbleras när size == capacity 
}

// Pop the value at the top of the stack.
double stack_pop(Stack *s);

// Check if the stack is empty.
bool stack_is_empty(const Stack *s);

