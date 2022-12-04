/**
 * Programmering i C
 * Fall 22
 * OU4
 *
 * @file             stack.h
 * @brief            Declares functions for a stack.
 *                  
 * @author           Aaron Myhrberg (ens21amg)
 * @defgroup         stack.h
 * @since            2022-12-04
 */

#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

// The type for a stack.
typedef struct stack
{
    int capacity;
    int size;
    double *data;
} Stack;

/**
 * @brief            Creates an empty stack
 * 
 * @return           Returns an empty stack.
*/
Stack *stack_create(void);

/**
 * @brief            Destroys/Deallocates the stack.
 * 
 * @param s          A stack. 
*/
void stack_destroy(Stack *s);

/**
 * @brief            Push a value atop of the stack
 * 
 * @param s          A stack.
 * @param value      What value to push onto the stack
*/
void stack_push(Stack *s, double value);

/**
 * @brief            Reads the value at the top of the stack then removes it
 *                   from the stack. This function is undefined for an empty
 *                   stack.
 * 
 * @param s          A stack.
 * @return           Returns the value of the first item in the stack. 
*/
double stack_pop(Stack *s);

/**
 * @brief            Check if the stack is empty
 * 
 * @param s          A stack.
 * @return           Returns true if empty else false. 
*/
bool stack_is_empty(const Stack *s);

#endif /* STACK_H */
