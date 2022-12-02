#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "list.h"


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
    if (q->list->head.prev == NULL){
        list_insert(list_first(q->list), value);
    }
    else{
        list_insert(list_end(q->list), value);
    }
   
   
   
    // if (list_is_empty){
    //     list_insert(list_first(q->list), value);
    // }
    // else{
    // ListPos pos = list_end(q->list);
    // pos = list_prev(pos);

    // list_insert(pos, value);
    // }

    // ListPos endpos = list_end(q->list);
    // list_insert(endpos, value);

    //HÄR ÄR NÅGOT LURT

    // if(queue_is_empty){
    //     list_insert(list_first(q->list), value);
    // }
    // else{
    //     list_insert(list_end(q->list), value);
    // }

}


char *queue_dequeue(Queue *q)
{
    // q->list->head.next = q->list->head.next->next;
    // q->list->head.next->prev = &q->list->head;
    
    char *result;
    ListPos firstpos = list_first(q->list);
    result = list_inspect(firstpos);
    list_remove(firstpos);

    return result;
}

bool queue_is_empty(const Queue *q)
{

    return list_is_empty(q->list);
}




