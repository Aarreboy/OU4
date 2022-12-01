#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "list.h"


Queue *queue_create(void)
{
    Queue *q = malloc(sizeof(Queue));
    List *p = list_create();

    q->list = p;

    return q;
}


void queue_destroy(Queue *q)
{
    list_destroy(q->list);
    free(q);
}


void queue_enqueue(Queue *q, const char *value)
{
    ListPos endpos = list_end(q->list);
    list_insert(endpos, value);

}


char *queue_dequeue(Queue *q)
{
    ListPos firstpos = list_first(q->list);
    char *result = list_inspect(firstpos);
    list_remove(firstpos);

    return result;
}

bool queue_is_empty(const Queue *q)
{
    return list_is_empty(q->list);
}


