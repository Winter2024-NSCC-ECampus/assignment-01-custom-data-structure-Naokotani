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

int main() {
  int num1 = 1;
  int num2 = 2;
  int num3 = 3;
  int num4 = 4;

  LinkedList list = create(&num1);
  list = append(list, &num2);
  list = append(list, &num3);
  list = append(list, &num4);

  printf("First of list is %d\n", *((int *)list.first->value));
  printf("Last of list is %d\n", *((int *)list.last->value));

  printf("first list size is %ld\n\n", list.size);

  LinkedList secondList = rest(list);
  LinkedList thirdList = rest(secondList);
  LinkedList fourthList = rest(thirdList);

  printf("First of secondList is %d\n", *((int *)secondList.first->value));
  printf("Last of secondList is %d\n", *((int *)secondList.last->value));

  printf("first list size is %ld\n\n", secondList.size);

  printf("First of thirdList is %d\n", *((int *)thirdList.first->value));
  printf("Last of thirdList is %d\n", *((int *)thirdList.last->value));

  printf("first list size is %ld\n\n", thirdList.size);

  printf("First of fourthList is %d\n", *((int *)fourthList.first->value));
  printf("Last of fourthList is %d\n", *((int *)fourthList.last->value));

  printf("first list size is %ld\n\n", fourthList.size);

  freeList(list);
  freeList(secondList);
  freeList(thirdList);
  freeList(fourthList);

  return 0;
}
