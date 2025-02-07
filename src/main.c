#include "linkedList.h"
#include <stdio.h>

// Function to extract strings from a file, including trailing whitespace
void extractText(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Failed to open file");
    return;
  }

  fclose(file);
}
int main() {
  extractText("/home/naokotani/code/school/data-structures/text.text");
  // LinkedList list = create("Hello ");
  //
  // list = append(list, "how ");
  // list = append(list, "are ");
  // list = append(list, "you?");
  //
  // printNode(first(list));
  // printNode(last(list));
  // printf("first list size is %ld\n\n", list.size);
  //
  // LinkedList secondList = rest(list);
  // LinkedList thirdList = rest(secondList);
  // LinkedList fourthList = rest(thirdList);
  //
  // printNode(first(secondList));
  // printNode(last(secondList));
  // printf("second list size is %ld\n\n", secondList.size);
  //
  // printNode(first(thirdList));
  // printNode(last(thirdList));
  // printf("second list size is %ld\n\n", thirdList.size);
  //
  // printNode(first(fourthList));
  // printNode(last(fourthList));
  // printf("second list size is %ld\n\n", fourthList.size);
  //
  // int index = 1;
  // printf("String at node %d is:\n", index);
  // getIndex(list, 1);
  // printf("here 1");
  // printf("\n\n");
  //
  // size_t i = findFirst(list, "how ");
  //
  // size_t unfound = findFirst(list, "derp");
  // printf("The index is %ld\n", i);
  // printf("The index is %ld\n\n", unfound);
  //
  // int found = contains(list, "are ");
  // int notFound = contains(list, "derp");
  //
  // printf("found is %d\n", found);
  // printf("not found is %d\n", notFound);
  // freeList(list);
  // freeList(secondList);
  // freeList(thirdList);
  //
  // freeList(fourthList);

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

  LinkedList sub = subList(pList, 2, 4);
  printList(sub);
  freeList(pList);
  freeList(sub);
  return 0;
}
