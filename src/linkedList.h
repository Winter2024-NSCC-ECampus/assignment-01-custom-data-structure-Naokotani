#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  struct Node *next;
  int *value;
} Node;

typedef struct LinkedList {
  size_t size;
  struct Node *first;
  struct Node *last;
} LinkedList;

/*
 * Returns the length of the linked list.
 */
size_t size(LinkedList list);

/*
 * Gets the value in the first node of the linked list.
 */
int *head(LinkedList list);

/*
 * Gets the value in the final node of the linked list.
 */
int *tail(LinkedList list);

/*
 *  Retrieves the first `Node` from the linked list;
 */
Node *first(LinkedList list);

/*
 *  Retrieves the last `Node` from the linked list;
 */
Node *last(LinkedList list);

/*
 *  Creates and initilizes a new `LinkedList`
 */
LinkedList create(int *value);

/*
 *  Apeend a `Node` after the final `Node` of a linked list.
 *  the value is the value to be placed in node->value.
 */
LinkedList append(LinkedList list, int *value);

/*
 *  Prepends a `Node` before first `Node` of a linked list.
 *  the value is the value to be placed in node->value.
 */
LinkedList prepend(LinkedList list, int *value);

/*
 *  Frees the memory for a linked List.
 */
void freeList(LinkedList list);

/*
 *  Retuns a new list composed of all nodes in a `LinkedList` after the first.
 *  This can be used to recursively searched the `LinkedList`
 */
LinkedList rest(LinkedList list);

/*
 *  used to recursively search through a linked list if the index is not 0.
 */
Node *getIndex(LinkedList list, int index);

/*
 * Removes the final element from a `LinkedList`.
 */
void pop(LinkedList *list);

/*
 * Finds the index of the first `Node` where node->value equals `value`
 */
size_t findFirst(LinkedList list, int value);

/*
 * Searched through a `LinkedList` to check if it contains `value`
 * returns 1 if present and 0 if not present;
 */
int contains(LinkedList list, int value);
