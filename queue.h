#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#include "list.h"

// The type for the queue.
typedef struct queue
{
    List *list;
} Queue;

// Create and return an empty queue.
/**
 * @brief            Create and returns an empty queue.
 * 
 * @return Queue*    Returns a queue.
 */
Queue *queue_create(void);

// Destroy the queue.
/**
 * @brief            Deallocates the memory of the queue.
 * 
 * @param q          A queue.
 */
void queue_destroy(Queue *q);

// Add a value to the tail of the queue.
// The value is copied to dynamically allocated memory. 
/**
 * @brief            Adds a value to the tail of the queue.
 * 
 * @param q          A queue
 * @param value      A value to add. 
 */
void queue_enqueue(Queue *q, const char *value);

// Remove the value at the head of the queue.
// The caller is responsible for deallocating the returned pointer.
/**
 * @brief            Removes the value at the head of the queue
 * 
 * @param q          A queue.
 * @return char*     Returns the value that was removed from the queue.
 */
char *queue_dequeue(Queue *q);

// Check if the queue is empty.
/**
 * @brief            Test if the queue is empty.
 * 
 * @param q          A queue.
 * @return           Returns true if the queue is empty, else it returns false.    
 */
bool queue_is_empty(const Queue *q);

#endif /* QUEUE_H */