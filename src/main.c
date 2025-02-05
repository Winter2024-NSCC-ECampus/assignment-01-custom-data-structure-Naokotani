#include "linkedList.h"

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
