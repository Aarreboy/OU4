/*
 * Programmering i C
 * Fall 22
 * OU4
 *
 * @file             stack.c
 * @brief            Defines the functions from "stack.h".
 *                  
 * @author           Aaron Myhrberg (ens21amg)
 * @defgroup         stack.c
 * @since            2022-12-04
 */

#include <stdio.h>
#include "stack.h"
#include <stdlib.h>


// Create an empty stack.

Stack *stack_create(void)
{
    Stack *p = malloc(sizeof(Stack));
    p->size = 0;
    p->capacity = 1; 
    p->data = malloc(sizeof(double));

    return p;
}

// Destroy the stack.
void stack_destroy(Stack *s)
{
    free(s->data);
    free(s);
}

// Push a value onto the stack.
void stack_push(Stack *s, double value)
{
    if (s->size == s->capacity){
        s->data = realloc(s->data, s->capacity * sizeof(double) * 2);
        s->capacity *= 2;
    }
    s->data[s->size] = value;
    s->size++;
} 

// Pop the value at the top of the stack.
double stack_pop(Stack *s)
{
    double res = s->data[s->size - 1];
    s->size--;
    return res;
}


// Check if the stack is empty.
bool stack_is_empty(const Stack *s)
{
    if (s->size == 0){
        return true;
    }
    else{
        return false;
    }
}
