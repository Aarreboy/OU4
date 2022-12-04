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
 * @since            2022-11-30
 */

#include <stdio.h>
#include "stack.h"
#include <math.h>

static double power_of(double base, double exponent);
static bool verify_stack(Stack *s);

int main(void)
{
    // Skapa en tom stack
    Stack *p = stack_create();
   
    //Fyll stacken med ärdena 0.5n för n = 1, 2, …, 10 genom att pusha dem.
    for (int i = 1; i <= 10; i++) {
        stack_push(p, pow(0.5, i));
    }

    // Verifiera att stacken innehåller de förväntade värdena genom att poppa dem.
    if (verify_stack(p)){
        printf("Test the functioning of the stack ... PASS");
    }
    else{
        printf("Test the functioning of the stack ... FAIL");
    }

    //FÖRSTÖR STACKEN
    stack_destroy(p);

    return 0;
}

static double power_of(double base, double exponent)
{
    double ans = base;
    if(exponent == 0){
        return 1;
    }
    for (int i = 1 ; i < exponent ; i++){
        ans = ans * base;
    }
    return ans;
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
    
   
        
    
