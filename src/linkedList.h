#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct String {
  size_t length;
  char *string;
} String;

typedef struct Node {
  struct Node *next;
  String *string;
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
String *head(LinkedList list);

/*
 * Gets the value in the final node of the linked list.
 */
String *tail(LinkedList list);

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
LinkedList create(char string[]);
LinkedList createEmpty();

/*
 *  Apeend a `Node` after the final `Node` of a linked list.
 *  the value is the value to be placed in node->value.
 */
LinkedList append(LinkedList list, char string[]);

/*
 *  Prepends a `Node` before first `Node` of a linked list.
 *  the value is the value to be placed in node->value.
 */
LinkedList prepend(LinkedList list, char *string);

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
 *  This is the "at" fuction but I gave it a different name.
 */
void getIndex(LinkedList list, int index);

/*
 * Removes the final element from a `LinkedList`.
 */
void pop(LinkedList *list);

/*
 * Finds the index of the first `Node` where node->value equals `value`
 * This is the "find" function, but I gave it a slighty different name
 */
size_t findFirst(LinkedList list, char *string);

/*
 * Searched through a `LinkedList` to check if it contains `value`
 * returns 1 if present and 0 if not present;
 */
int contains(LinkedList list, char *string);

/**
 * Prints the string in a node.
 */
void printNode(Node *node);

/*
 * Prints the entire list.
 */
void printList(LinkedList);

/*
 * Remove node at index.
 */
int removeIndex(LinkedList list, int index);

/*
 * Returns a new sublist of the list. from index `start` to index `end`
 */
LinkedList subList(LinkedList list, size_t start, size_t end);
