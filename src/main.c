#include "linkedList.h"
#include <stdio.h>

int main() {
  LinkedList list = create("Hello ");

  list = append(list, "are ");
  list = append(list, "how ");
  list = append(list, "you?");

  printNode(first(list));
  printNode(last(list));
  printf("first list size is %ld\n\n", list.size);

  LinkedList secondList = rest(list);
  LinkedList thirdList = rest(secondList);
  LinkedList fourthList = rest(thirdList);

  printNode(first(secondList));
  printNode(last(secondList));
  printf("second list size is %ld\n\n", secondList.size);

  printNode(first(thirdList));
  printNode(last(thirdList));
  printf("second list size is %ld\n\n", thirdList.size);

  printNode(first(fourthList));
  printNode(last(fourthList));
  printf("second list size is %ld\n\n", fourthList.size);

  printf("Before popping second list last node is:\n");
  printNode(last(secondList));
  pop(&secondList);
  printf("After popping second list last node is:\n");
  printNode(last(secondList));
  printf("Appending it back on and last node is\n");
  secondList = append(secondList, "you?");
  printNode(last(secondList));

  printf("Before prepend second list last node is:\n");
  printNode(first(secondList));
  secondList = prepend(secondList, "Yo, ");
  printf("After prepend second list last node is:\n");
  printNode(first(secondList));
  printf("\n");

  int index = 1;
  printf("String at node %d is:\n", index);
  getIndex(list, 1);
  printf("\n\n");

  size_t i = findFirst(list, "are");
  size_t unfound = findFirst(list, "derp");

  printf("The index is %ld\n", i);
  printf("The index is %ld\n\n", unfound);

  int found = contains(list, "how");
  int notFound = contains(list, "derp");

  printf("found is %d\n", found);
  printf("not found is %d\n", notFound);
  freeList(list);
  freeList(secondList);
  freeList(thirdList);
  freeList(fourthList);

  LinkedList pList = create("I ");
  pList = append(pList, "am ");
  pList = append(pList, "going ");
  pList = append(pList, "to ");
  pList = append(pList, "mistake ");
  pList = append(pList, "print ");
  pList = append(pList, "this ");
  pList = append(pList, "list.");

  removeIndex(pList, 4);
  printList(pList);
  freeList(pList);

  // for (int i = 0; i < 90000000; i++) {
  //   char *string;
  //   asprintf(&string, "%d\n", i);
  //   pList = append(pList, string);
  //   free(string);
  // }

  // LinkedList breakList = rest(pList);
  //
  // pList = append(pList, "gone.");
  //
  // pop(&pList);
  //
  // printList(pList);
  // printNode(first(breakList));
  // printNode(last(breakList));
  // freeList(breakList);
  return 0;
}
