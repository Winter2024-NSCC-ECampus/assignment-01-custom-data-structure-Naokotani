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
    return -1;
  }
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

  int newNum = 7;
  secondList = append(secondList, &newNum);
  int anohterNum = 9;
  secondList = prepend(secondList, &anohterNum);

  printf("prepend first of secondList is %d\n",
         *((int *)secondList.first->value));
  printf("prepend last of secondList is %d\n",
         *((int *)secondList.last->value));

  fourthList = prepend(fourthList, &newNum);

  printf("prepend first of fourthList is %d\n",
         *((int *)fourthList.first->value));
  printf("prepend last of fourthList is %d\n",
         *((int *)fourthList.last->value));

  secondList = rest(secondList);

  printf("rest after prepend first of secondList is %d\n",
         *((int *)secondList.first->value));
  printf("rest after prepend last of secondList is %d\n\n\n",
         *((int *)secondList.last->value));

  Node *gotNode = getIndex(list, 2);

  printf("list first before pop %d\n", *((int *)list.first->value));
  printf("list last before pop %d\n\n\n", *((int *)list.last->value));

  pop(&list);

  printf("list first after pop %d\n", *((int *)list.first->value));
  printf("list last after pop %d\n\n\n", *((int *)list.last->value));

  size_t i = findFirst(list, 2);
  printf("The index is %ld\n", i);

  size_t unfound = findFirst(list, 22);
  printf("The index is %ld\n", unfound);

  int found = contains(list, 2);
  int notFound = contains(list, 22222);

  printf("found is %d\n", found);
  printf("not found is %d\n", notFound);

  return 0;
}
