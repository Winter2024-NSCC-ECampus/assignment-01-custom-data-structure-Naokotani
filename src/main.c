#include "linkedList.h"

int main() {
  String *string1 = createString("Hello");
  String *string2 = createString("how");
  String *string3 = createString("are");
  String *string4 = createString("you?");

  LinkedList list = create(string1);

  list = append(list, string2);
  list = append(list, string3);
  list = append(list, string4);

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
  secondList = append(secondList, string4);
  printNode(last(secondList));

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

  return 0;
}
