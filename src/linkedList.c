#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t size(LinkedList list) { return list.size; }
String *head(LinkedList list) { return list.first->string; }
String *tail(LinkedList list) { return list.last->string; }
Node *first(LinkedList list) { return list.first; }
Node *last(LinkedList list) { return list.last; }

void freeNode(Node *node) {
  free(node->string->string);
  free(node->string);
  free(node);
}

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

LinkedList createEmpty() {
  LinkedList list;
  list.first = NULL;
  list.last = NULL;
  list.size = 0;
  return list;
}

LinkedList append(LinkedList list, char *string) {
  Node *node = createNode(string);
  if (list.first == NULL) {
    list.first = node;
    list.last = node;
  }
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

LinkedList restSublistRecur(Node *node, LinkedList list) {
  String *currString = malloc(sizeof(String));
  currString->string = malloc(node->string->length);
  strcpy(currString->string, node->string->string);
  list = append(list, currString->string);
  free(currString->string);
  free(currString);

  if (node->next == NULL) {
    return list;
  } else {
    return restSublistRecur(node->next, list);
  }
}

LinkedList restSublist(Node *node) {
  LinkedList list = create(node->string->string);

  if (node->next == NULL) {
    return list;
  } else {
    return restSublistRecur(node->next, list);
  }
}

LinkedList rest(LinkedList list) {
  if (list.size == 1) {
    printf("List contains only one element\n");
    return create("");
  }
  return restSublist(first(list)->next);
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

size_t findFirstRecur(Node *node, char *string, size_t currIndex) {
  if (!strcmp(node->string->string, string)) {
    return currIndex;
  }

  if (node->next == NULL) {
    return -1;
  }

  return findFirstRecur(node->next, string, ++currIndex);
}

size_t findFirst(LinkedList list, char *string) {
  size_t currIndex = 0;
  Node *node = first(list);
  if (!strcmp(node->string->string, string)) {
    return currIndex;
  } else {
    return findFirstRecur(node->next, string, ++currIndex);
  }
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

void removeNode(Node *node, LinkedList *list) {
  Node *prevNode = node;
  Node *rNode = node->next;
  if (rNode->next != NULL) {
    Node *nextNode = rNode->next;
    prevNode->next = nextNode;
  } else {
    list->last = prevNode;
    prevNode->next = NULL;
  }
  free(rNode->string->string);
  free(rNode->string);
  free(rNode);
};

int recurRemove(int index, int currIndex, Node *currNode, LinkedList list) {
  if (currIndex == index - 1) {
    removeNode(currNode, &list);
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

Node *getIndexRecurSublist(Node *node, int index, int currIndex) {
  if (index == currIndex)
    return node;

  if (node->next == NULL) {
    printf("Index ouf of bounds");
  }

  return getIndexRecurSublist(node->next, index, ++currIndex);
}

Node *getIndexSublist(LinkedList list, int index) {
  if (index == (int)list.size) {
    printf("Index is out of bounds");
    return NULL;
  }

  int currIndex = 0;
  if (index == currIndex)
    return first(list);

  return getIndexRecurSublist(first(list), index, currIndex);
}

void subListRemoveNodes(Node *node) {
  Node *nextNode = node->next;
  freeNode(node);

  if (nextNode == NULL)
    return;

  subListRemoveNodes(nextNode);
}

Node *subListTrim(Node *node, int index, int currIndex) {
  if (currIndex == index)
    return node;

  if (node->next == NULL) {
    printf("Index out of bounds");
    return node;
  }

  return subListTrim(node->next, index, ++currIndex);
}

LinkedList subList(LinkedList list, size_t start, size_t end) {
  Node *startNode = getIndexSublist(list, start);
  LinkedList subList = restSublist(startNode);
  Node *endNode = subListTrim(first(subList), end - start, 0);
  subList.last = endNode;
  subList.size = end - start + 1;
  subListRemoveNodes(endNode->next);
  endNode->next = NULL;
  return subList;
}
