#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t size(LinkedList list) { return list.size; }
int *head(LinkedList list) { return list.first->value; }
int *tail(LinkedList list) { return list.last->value; }
Node *first(LinkedList list) { return list.first; }
Node *last(LinkedList list) { return list.last; }

LinkedList create(int *value) {
  Node *node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  LinkedList list;
  list.first = node;
  list.last = node;
  list.size = 1;
  return list;
}

LinkedList append(LinkedList list, int *value) {
  Node *node = malloc(sizeof(Node));
  list.last->next = node;
  list.last = node;
  node->value = value;
  node->next = NULL;
  list.size += 1;
  return list;
}

LinkedList prepend(LinkedList list, int *value) {
  Node *node = malloc(sizeof(Node));
  node->next = list.first;
  node->value = value;
  list.first = node;
  list.size += 1;
  return list;
}

void freeList(LinkedList list) {
  Node *currNode = list.first;

  while (currNode != NULL) {
    Node *freeNode = currNode;
    currNode = currNode->next;
    free(freeNode);
  }
}

LinkedList rest(LinkedList list) {
  if (list.size == 1) {
    printf("List contains only one element\n");
    return list;
  }

  Node *currNode = list.first->next;
  int *currValue = malloc(sizeof(int));
  currValue = currNode->value;

  LinkedList newList;
  newList = create(currValue);
  currNode = currNode->next;

  while (currNode != NULL) {
    int *currValue = malloc(sizeof(int));
    memcpy(currValue, currNode->value, sizeof(int));
    newList = append(newList, currValue);
    currNode = currNode->next;
  }

  return newList;
}

Node *getIndexRecur(LinkedList list, int index, int currIndex) {
  Node *node;
  LinkedList newList = rest(list);
  printf("created new list\n");

  if (index == currIndex) {
    printf("indices match \n");
    node = first(newList);
  } else {
    node = getIndexRecur(list, index, ++currIndex);
  }
  freeList(newList);
  return node;
}

Node *getIndex(LinkedList list, int index) {
  int currIndex = 0;
  if (index == currIndex) {
    return first(list);
  } else {
    return getIndexRecur(list, index, ++currIndex);
  }
}

void pop(LinkedList *list) {
  Node *prevNode;
  Node *currNode = first(*list);
  while (currNode->next != NULL) {
    prevNode = currNode;
    currNode = currNode->next;
  }

  free(currNode);
  list->last = prevNode;
  prevNode->next = NULL;
}

size_t findFirstRecur(LinkedList list, int value, size_t currIndex) {
  LinkedList newList = rest(list);
  Node *firstNode = first(list);
  if (*head(newList) != value) {
    if (newList.first->next != NULL) {
      currIndex = findFirstRecur(newList, value, ++currIndex);
    } else {
      currIndex = -1;
    }
  }
  freeList(newList);
  return currIndex;
}

size_t findFirst(LinkedList list, int value) {
  size_t currIndex = 0;
  Node *firstNode = first(list);
  if (*head(list) != value) {
    if (firstNode->next != NULL) {
      currIndex = findFirstRecur(list, value, ++currIndex);
    } else {
      currIndex = -1;
    }
  }
  return currIndex;
}

int contains(LinkedList list, int value) {
  int found = findFirst(list, value);
  if (found >= 0) {
    return 1;
  } else {
    return 0;
  }
}
