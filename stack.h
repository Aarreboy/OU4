#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// The type for a stack.
typedef struct stack
{
    //capacity = hur mycket arrayen kan hålla
    int capacity;

    //size = hur mycket arrayen har i sig för tillfället.
    int size;
    double *data;
} Stack;

// Create an empty stack.
/**
 * @brief            Creates an empty stack
 * 
 * @return           Returns an empty stack.
*/
Stack *stack_create(void);

// Destroy the stack.
/**
 * @brief            Deallocates the stack.
 * 
 * @param s          A stack. 
*/
void stack_destroy(Stack *s);

// Push a value onto the stack.
/**
 * @brief            Push a value atop of the stack
 * 
 * @param s          A stack.
 * @param value      What value to push onto the stack
*/
void stack_push(Stack *s, double value);

// Pop the value at the top of the stack.
/**
 * @brief            Reads the value at the top of the stack then removes it
 *                   from the stack. "If stack is not empty"
 * 
 * @param s          A stack.
 * @return           Returns the value of the first item in the stack. 
*/
double stack_pop(Stack *s);

// Check if the stack is empty.
/**
 * @brief            Check if the stack is empty
 * 
 * @param s          A stack.
 * @return           Returns true if empty else false. 
*/
bool stack_is_empty(const Stack *s);

#endif /* STACK_H */