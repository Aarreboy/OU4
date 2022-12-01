/*
 * Programmering i C
 * Fall 22
 * OU2
 *
 * @file             list.c
 * @brief            Defines the functions from "list.h".
 *                  
 * @author           Aaron Myhrberg (ens21amg)
 * @defgroup         list.c
 * @since            2022-11-20
 */

#include <stdlib.h>
#include <string.h>
#include "list.h"
#include <stdio.h>


static char *clone_string(const char *in)
{
    size_t len = strlen(in);
    char *out = calloc(len + 1, sizeof(char));
    strncpy(out, in, len);

    return out;
}


static struct node *make_node(const char *value)
{
    struct node *p = malloc(sizeof(struct node));
    if (value == NULL){
        p->value = "";
    }
    else{
    p->value = clone_string(value);
    }

    p->next = NULL;
    p->prev = NULL;

    return p;
}


List *list_create(void)
{
    List *p = malloc(sizeof(List));
    p->head.next = &p->head;
    p->head.prev = &p->head;
    p->head.value = NULL;

    return p;
}


void list_destroy(List *lst)
{
    struct node *p = lst->head.next;
    
    if (p != &lst->head){
        while(p != &lst->head){
            p = p->next;
            free(p->prev->value);
            free(p->prev);
            
        }
    }
    free(lst);
    lst = NULL;
}


bool list_is_empty(const List *lst)
{
    return (lst->head.next == &lst->head);
}


ListPos list_first(List *lst)
{
    ListPos pos = {
        .node = lst->head.next
    };

    return pos;  
}


ListPos list_end(List *lst)
{
    ListPos pos = {
        .node = &lst->head
    };

    return pos;
}

bool list_pos_equal(ListPos p1, ListPos p2)
{
    if ((p1.node->value == NULL && p2.node->value != NULL) || (p1.node->value != NULL && p2.node->value == NULL)){
        return false;
    }
    else if (p1.node->value == NULL && p2.node->value == NULL){
        return true;
    }
    else{
    return(strncmp(p1.node->value, p2.node->value, 20) == 0);
    }
    
}

ListPos list_next(ListPos pos)
{
    if (pos.node->value == NULL){
        fprintf(stderr, "list_next is not defined for last element (head)");
        return pos; 
    }

    ListPos next_pos;
    next_pos.node = pos.node->next;

    return next_pos;
}

ListPos list_prev(ListPos pos)
{
    if (pos.node->prev->value == NULL){
        fprintf(stderr, "list_prev is not defined for first element");
        return pos; 
    }
    
    ListPos pre_pos;
    pre_pos.node = pos.node->prev;

    return pre_pos;
}

ListPos list_insert(ListPos pos, const char *value)
{
    // Create a new node.
    struct node *node = make_node(value);

    // Find nodes before and after (may be the same node: the head of the list).
    struct node *before = pos.node->prev;
    struct node *after = pos.node;

    // Link to node after.
    node->next = after;
    after->prev = node;

    // Link to node before.
    node->prev = before;
    before->next = node;

    // Return the position of the new element.
    pos.node = node;
    return pos;
}

ListPos list_remove(ListPos pos)
{
     if (pos.node->value == NULL){
        fprintf(stderr, "list_remove is not defined for last element (head)");
        return pos;
    }
    ListPos temp;
    temp.node = pos.node->next;

    pos.node->prev->next = pos.node->next;
    pos.node->next->prev = pos.node->prev;
    free(pos.node->value);
    free(pos.node);

    return temp; 
}

const char *list_inspect(ListPos pos)
{
    if (pos.node->value == NULL){
        fprintf(stderr, "list_inspect is not defined for last element (head)");
        return 0; 
    }
    
    const char *temp;
    temp = pos.node->value;

    return temp;
}