#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "list.h"
#include <string.h>

#define SIZE 20

Queue *queue_create(void)
{
    Queue *q = malloc(sizeof(Queue));
    q->list = list_create();

    return q;
}


void queue_destroy(Queue *q)
{
    list_destroy(q->list);
    free(q);
}


void queue_enqueue(Queue *q, const char *value)
{
    list_insert(list_end(q->list), value);
}
  





char *queue_dequeue(Queue *q)
{    
    char *result; 
    result = malloc(sizeof(char[SIZE]));
    ListPos firstpos = list_first(q->list);
    strncpy(result, list_inspect(firstpos), SIZE);
    list_remove(firstpos);

    return result;
}

bool queue_is_empty(const Queue *q)
{

    return list_is_empty(q->list);
}
