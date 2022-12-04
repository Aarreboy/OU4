/*
 * Programmering i C
 * Fall 22
 * OU4
 *
 * @file             stack-test.c
 * @brief            A test program for stack.
 *                  
 * @author           Aaron Myhrberg (ens21amg)
 * @defgroup         stack-test.c
 * @since            2022-12-04
 */

#include <stdio.h>
#include "stack.h"
#include <math.h>

static double power_of(double base, double exponent);
static bool verify_stack(Stack *s);

int main(void)
{
    Stack *p = stack_create();
   
    for (int i = 1; i <= 10; i++) {
        stack_push(p, pow(0.5, i));
    }

    if (verify_stack(p)){
        printf("Test the functioning of the stack ... PASS");
    }
    else{
        printf("Test the functioning of the stack ... FAIL");
    }

    stack_destroy(p);

    return 0;
}

static bool verify_stack(Stack *s)
{
    for (int i = 10; i > 0; i--) {
        if (stack_pop(s) != pow(0.5, i)){
            return false;
        }
    }
    return true;
}
    
   
        
    

   
        
    
