/**
 * Programmering i C
 * Fall 22
 * OU2
 *
 * @file             list.h
 * @brief            Declares the functions and structures which belongs
 *                   to a list.
 * @author           Aaron Myhrberg (ens21amg)
 * @defgroup         list.h
 * @since            2022-11-20
 * @{
 */

#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

/**
 * @brief            The type for a node in the list.
 * 
 */
struct node
{
    struct node *next;
    struct node *prev;
    char *value;
};

/**
 * @brief            The type for a list.
 * 
 */

typedef struct list
{
    struct node head;    
} List;

/**
 * @brief            The type for a list position.
 * 
 */
typedef struct list_pos
{
    struct node *node;
} ListPos;

/**
 * @brief            list_create generates a new and empty list item.
 *                   Even though an empty list has no elements, we will still
 *                   have a position (head).                          
 *
 * @return           *list_create get the List item as its value.
 */ 
List *list_create(void);

/**
 * @brief            list_destroy deallocates memory of the list and its values.
 * 
 * @param lst        the input of list_destroy is a List.  
 */
void list_destroy(List *lst);

/**
 * @brief            list_is_empty checks if the list is empty
 * 
 * @param lst        the input is what List to be checked.  
 * @return           true if list is empty, false if it is not empty
 */
 
bool list_is_empty(const List *lst);

/**
 * @brief            list_first acquire the position of the first element in the list.
 * 
 * @param lst        the input is a list. 
 * @return           list_first returns the position of the first element. 
 */
ListPos list_first(List *lst);

/**
 * @brief            list_end acquire the position of the last element in the list.
 * 
 * @param lst        The input is a list.
 * @return           list_end returns the position of the last element.
 */ 
ListPos list_end(List *lst);

/**
 * @brief            list_pos_equal checks the equality between the value
 *                   of two positions.
 * 
 * @param p1         first position to be compared.
 * @param p2         second position to be compared.
 * @return           returns true if the values of the positions is the equal.
 * @return           returns false if the values of the positions is not equal. 
 */
bool list_pos_equal(ListPos p1, ListPos p2);

/**
 * @brief            list_next acquire the position of the next position. 
 *                   The function is not defined for the last position in the list.
 * 
 * @param pos        a position
 * @return           returns the the closest following position.  
 */
ListPos list_next(ListPos pos);

/**
 * @brief            list_prev acquire the position of the previous position.
 * 
 * @param pos        a position is needed as input.
 * @return           returns the closest previous position.
 */
ListPos list_prev(ListPos pos);

/**
 * @brief            list_insert modifies the list by inserting a new element and value
 *                   before the given position.
 * 
 * @param pos        a position to tell where the new element and value
 *                   is going to be inserted. 
 * @param value      what value to be inserted.
 * @return           returns the position of the new element created.
 */
ListPos list_insert(ListPos pos, const char *value);

/**
 * @brief            list_remove removes the element at the given position. 
 *                   The function is not defined for the last position in the list.
 * 
 * @param pos        the position of what element to be removed.
 * @return           returns the position of the following element of
 *                   the removed element. 
 */ 
ListPos list_remove(ListPos pos);

/**
 * @brief            list_inspect acquire the value of the given position.
 *                   The function is not defined for the last position in a list. 
 * 
 * @param pos        what positions value to be inspected.
 * @return           returns the value of the given position.
 */ 
const char *list_inspect(ListPos pos);

/**
 * @}
 */

#endif /* LIST_H */