#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *prev;
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
LinkedList create(size_t size);
void *allocate_node(size_t size);
void *getFirst(LinkedList list);
void *getLast(LinkedList list);
void *car(Node *node) { return node->value; }
void *cdr(Node *node) { return node->next->value; }

void *getFirst(LinkedList list) { return list.first->value; }
void *getLast(LinkedList list) { return list.last->value; }

LinkedList create(size_t size) {
  LinkedList list;
  list.typeSize = size;
  list.size = 0;
  list.first = NULL;
  list.last = NULL;
  return list;
}

void *allocate_node(size_t size) { return malloc(sizeof(Node) * 2 + size); }

LinkedList prepend(LinkedList list, void *ptr) {
  Node *node = allocate_node(list.typeSize);

  if (list.size > 1) {
    node->next = list.first;
    node->prev = list.last;
    list.first->prev = node;
  }

  if (list.size == 1) {
    list.last->next = node;
  }

  if (list.size == 0) {
    list.first = node;
    list.last = node;
  } else {
    list.first = node;
  }

  node->value = ptr;
  list.size += 1;

  return list;
}

LinkedList append(LinkedList list, void *ptr) {
  Node *node = allocate_node(list.typeSize);

  if (list.size > 1) {
    node->prev = list.first;
    node->next = list.last;
    list.last->next = node;
  }

  if (list.size == 1) {
    list.first->prev = node;
  }

  if (list.size == 0) {
    list.first = node;
    list.last = node;
    node->next = node;
    node->prev = node;
  } else {
    list.last = node;
  }

  node->value = ptr;

  list.size += 1;

  return list;
}

int main() {
  LinkedList list = create(sizeof(int));
  Node node;
  int num1 = 1;
  int num2 = 2;
  int num3 = 3;
  int num4 = 0;
  list = append(list, &num1);
  list = append(list, &num2);
  list = append(list, &num3);

  printf("The first nubmer is %d\n", *((int *)getFirst(list)));
  printf("The last number is %d\n", *((int *)getLast(list)));

  Node *second = list.first->next;
  printf("The second number is %d\n", *((int *)second->value));
  Node *node1 = getFirst(list);

  int *result = car(node1);
  int *result2 = cdr(node1);

  list = prepend(list, &num4);

  printf("The first nubmer is %d\n", *((int *)getFirst(list)));
  printf("The last number is %d\n", *((int *)getLast(list)));

  printf("Hello, World!\n");
  return 0;
}
