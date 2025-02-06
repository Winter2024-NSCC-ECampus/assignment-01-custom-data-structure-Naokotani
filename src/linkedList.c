#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t size(LinkedList list) { return list.size; }
String *head(LinkedList list) { return list.first->string; }
String *tail(LinkedList list) { return list.last->string; }
Node *first(LinkedList list) { return list.first; }
Node *last(LinkedList list) { return list.last; }

Node *createNode(char *string) {
  Node *node = malloc(sizeof(Node));
  node->string = malloc(sizeof(String));
  node->string->length = strlen(string) + 1;
  node->string->string = malloc(sizeof(char) * node->string->length);
  strcpy(node->string->string, string);
  return node;
}

LinkedList create(char *string) {
  Node *node = createNode(string);
  node->next = NULL;
  LinkedList list;
  list.first = node;
  list.last = node;
  list.size = 1;
  return list;
}

LinkedList append(LinkedList list, char *string) {
  Node *node = createNode(string);
  list.last->next = node;
  list.last = node;
  node->next = NULL;
  list.size += 1;
  return list;
}

LinkedList prepend(LinkedList list, char *string) {
  Node *node = createNode(string);
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
    free(freeNode->string);
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
  newList = create(currNode->string->string);
  currNode = currNode->next;

  String *currString = malloc(sizeof(String));
  while (currNode != NULL) {
    currString->string = malloc(currNode->string->length);
    currString->length = currNode->string->length;
    strcpy(currString->string, currNode->string->string);
    newList = append(newList, currString->string);
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

  free(currNode->string->string);
  free(currNode->string);
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

void printList(LinkedList list) {
  Node *currNode = first(list);
  while (currNode != NULL) {
    char *str = malloc(sizeof(char) * currNode->string->length);
    strcpy(str, currNode->string->string);
    printf("%s", str);
    currNode = currNode->next;
    free(str);
  }
  printf("\n");
}

void printListFree(LinkedList list) {
  Node *currNode = first(list);
  while (currNode != NULL) {
    char *str = malloc(sizeof(char) * currNode->string->length);
    strcpy(str, currNode->string->string);
    printf("%s", str);
    free(str);
    Node *freeNode = currNode;
    currNode = currNode->next;
    free(freeNode->string->string);
    free(freeNode->string);
    free(freeNode);
  }
  printf("\n");
}

void removeNode(Node *node, LinkedList list) {
  Node *prevNode = node;
  Node *rNode = node->next;
  if (rNode->next != NULL) {
    Node *nextNode = rNode->next;
    prevNode->next = nextNode;
  } else {
    list.last = prevNode;
    prevNode->next = NULL;
  }
  free(rNode->string->string);
  free(rNode->string);
  free(rNode);
};

int recurRemove(int index, int currIndex, Node *currNode, LinkedList list) {
  if (currIndex == index - 1) {
    removeNode(currNode, list);
    return 0;
  } else if (currNode->next == NULL) {
    printf("Index out of bounds");
    return 1;
  } else {
    return recurRemove(index, ++currIndex, currNode->next, list);
  }
}

int removeIndex(LinkedList list, int index) {
  if (index == 0) {
    Node *firstNode = first(list);
    list.first = first(list)->next;
    free(firstNode->string->string);
    free(firstNode->string);
    free(firstNode);
    return 0;
  } else {
    int currIndex = 1;
    return recurRemove(index, currIndex, first(list)->next, list);
  }
}

Node *getIndexRecurSublist(LinkedList list, int index, int currIndex) {
  LinkedList newList = rest(list);

  if (index == currIndex) {
    printNode(first(newList));
  } else {
    return getIndexRecur(list, index, ++currIndex);
  }
  freeList(newList);
}

Node *getIndexSublist(LinkedList list, int index) {
  if (index == (int)list.size) {
    printf("Index is out of bounds");
    return NULL;
  }

  int currIndex = 0;
  if (index == currIndex) {
    return first(list);
  } else {
    return getIndexRecurSublist(list, index, ++currIndex);
  }
}

LinkedList subList(LinkedList list, size_t start, size_t end) {
  Node *node = getIndexSublist(list, start);
}
