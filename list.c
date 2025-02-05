#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *next;
  void *value;
} Node;

typedef struct LinkedList {
  size_t size;
  size_t typeSize;
  struct Node *first;
  struct Node *last;
} LinkedList;

LinkedList append(LinkedList list, void *ptr);
LinkedList prepend(LinkedList list, void *ptr);
Node *rem(Node *node);
LinkedList create(void *ptr, size_t size);
// void *last(LinkedList list) { return list.first->prev; }
void freeLinkedList(LinkedList list);
void *first(LinkedList list) { return list.first->value; }

LinkedList rest(LinkedList list) {
  // TODO error
  printf("Rest list\n");
  if (list.size == 1) {
    return list;
    printf("List contains only one node");
  }

  Node *currNode = list.first->next;
  printf("First element added to new list is %d\n", *((int *)currNode->value));
  LinkedList newList = create(currNode->value, list.typeSize);

  if (list.size > 2) {
    currNode = currNode->next;
  }

  while (currNode != NULL) {
    printf("looping to add to list\n");
    printf("adding %d to list\n", *((int *)currNode->value));
    newList = append(newList, currNode->value);
    currNode = currNode->next;
  }

  printf("\n\n");

  return newList;
}

LinkedList create(void *ptr, size_t size) {
  LinkedList list;
  Node *node = malloc(sizeof(Node));
  node->value = malloc(list.typeSize);
  list.typeSize = size;
  list.size = 1;
  list.first = node;
  list.last = node;
  node->value = ptr;
  node->next = NULL;
  return list;
}

void freeLinkedList(LinkedList list) {
  LinkedList freeList = list;
  Node *currNode = list.first;
  Node *nextNode = list.first->next;
  while (&freeList.first->next != &currNode) {
  }
}

LinkedList prepend(LinkedList list, void *ptr) {
  Node *node = malloc(sizeof(Node));
  if (sizeof(ptr) != list.typeSize) {
    node->value = malloc(sizeof(list.typeSize));
  }

  node->value = ptr;
  list.size += 1;

  return list;
}

LinkedList append(LinkedList list, void *ptr) {
  Node *node = malloc(sizeof(Node));
  void *value = malloc(list.typeSize);
  memcpy(value, ptr, list.typeSize);
  node->value = value;
  Node *last = list.last;

  printf("Appending %d to list\n", *((int *)ptr));

  last->next = node;
  node->next = NULL;

  list.size += 1;

  return list;
}

int main() {
  int num1 = 1;
  int num2 = 2;
  int num3 = 3;
  int num4 = 4;
  Node node;
  LinkedList list = create(&num1, sizeof(int));
  list = append(list, &num1);
  list = append(list, &num2);
  list = append(list, &num3);
  list = append(list, &num4);

  printf("The first of the list is %d\n", *((int *)list.first->value));
  printf("The first of the list is %d\n", *((int *)list.first->next->value));

  LinkedList secondList = rest(list);

  printf("The first of the list is %d\n", *((int *)secondList.first->value));

  return 0;
}
