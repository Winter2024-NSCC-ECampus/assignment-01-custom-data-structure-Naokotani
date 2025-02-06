#include "linkedList.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t size(LinkedList list) { return list.size; }
String *head(LinkedList list) { return list.first->string; }
String *tail(LinkedList list) { return list.last->string; }
Node *first(LinkedList list) { return list.first; }
Node *last(LinkedList list) { return list.last; }

LinkedList create(String *string) {
  Node *node = malloc(sizeof(Node));
  node->string = malloc(sizeof(String));
  node->string->string = malloc(sizeof(char) * string->length);
  node->string->length = string->length;
  strcpy(node->string->string, string->string);
  node->next = NULL;
  LinkedList list;
  list.first = node;
  list.last = node;
  list.size = 1;
  return list;
}

LinkedList append(LinkedList list, String *string) {
  Node *node = malloc(sizeof(Node));
  node->string = malloc(sizeof(String));
  node->string->string = malloc(sizeof(char) * string->length);
  node->string->length = string->length;
  strcpy(node->string->string, string->string);
  list.last->next = node;
  list.last = node;
  node->next = NULL;
  list.size += 1;
  return list;
}

LinkedList prepend(LinkedList list, String string) {
  Node *node = malloc(sizeof(Node));
  String *stringPtr = malloc(sizeof(String));
  stringPtr->string = malloc(sizeof(char) * string.length);
  stringPtr->length = string.length;
  strcpy(stringPtr->string, string.string);
  node->next = list.first;
  list.first = node;
  list.size += 1;
  return list;
}

void freeList(LinkedList list) {
  Node *currNode = list.first;

  while (currNode != NULL) {
    Node *freeNode = currNode;
    free(freeNode->string->string);
    currNode = currNode->next;
    free(freeNode);
  }
}

LinkedList rest(LinkedList list) {
  if (list.size == 1) {
    printf("List contains only one element\n");
    return list;
  }

  Node *currNode = first(list)->next;
  LinkedList newList;
  newList = create(currNode->string);
  currNode = currNode->next;

  String *currString = malloc(sizeof(String));
  while (currNode != NULL) {
    currString->string = malloc(currNode->string->length);
    currString->length = currNode->string->length;
    strcpy(currString->string, currNode->string->string);
    newList = append(newList, currString);
    currNode = currNode->next;
    free(currString->string);
  }
  free(currString);

  return newList;
}

void getIndexRecur(LinkedList list, int index, int currIndex) {
  LinkedList newList = rest(list);

  if (index == currIndex) {
    printNode(first(newList));
  } else {
    getIndexRecur(list, index, ++currIndex);
  }
  freeList(newList);
}

void getIndex(LinkedList list, int index) {

  // TODO error
  if (index == (int)list.size) {
    printf("Index is out of bounds");
    return;
  }

  int currIndex = 0;
  if (index == currIndex) {
    printNode(first(list));
  } else {
    getIndexRecur(list, index, ++currIndex);
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

size_t findFirstRecur(LinkedList list, char *string, size_t currIndex) {
  LinkedList newList = rest(list);
  if (strcmp(head(newList)->string, string)) {
    if (newList.first->next != NULL) {
      currIndex = findFirstRecur(newList, string, ++currIndex);
    } else {
      currIndex = -1;
    }
  }
  freeList(newList);
  return currIndex;
}

size_t findFirst(LinkedList list, char *string) {
  size_t currIndex = 0;
  Node *firstNode = first(list);
  if (strcmp(head(list)->string, string)) {
    if (firstNode->next != NULL) {
      currIndex = findFirstRecur(list, string, ++currIndex);
    } else {
      currIndex = -1;
    }
  }
  return currIndex;
}

int contains(LinkedList list, char *string) {
  int found = findFirst(list, string);
  if (found >= 0) {
    return 1;
  } else {
    return 0;
  }
}

void printNode(Node *node) {
  char *str = malloc(sizeof(char) * node->string->length);
  strcpy(str, node->string->string);
  printf("%s\n", str);
  free(str);
}

String *createString(char ptr[]) {
  String *string = malloc(sizeof(String));
  string->length = strlen(ptr) + 1;
  string->string = malloc(sizeof(char) * string->length);
  strcpy(string->string, ptr);
  return string;
}
