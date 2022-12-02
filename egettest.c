#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"


int main(void)
{
   // Create an empty queue.
    Queue *q = queue_create();

    if (queue_is_empty(q)){
        printf("empty\n");
    }
   
    queue_enqueue(q, "hej");

    if (queue_is_empty(q) == false){
        printf("not empty\n");
    }
    else{
        printf("empty\n");
    }
  
    char *val;
    val = queue_dequeue(q);
    printf("%s", val);

    if (queue_is_empty(q)){
        printf("empty\n");
    }


    queue_destroy(q);

    return 0;
}