#ifndef __HEADER_H__
#define __HEADER_H__
#include "linkedList.h"
#include "parse.h"
#include "texts.h"
#include <stdio.h>

#endif

int main() {
  printf("*** random Moby Dick quote ***\n\n\n\n");
  getchar();
  LinkedList dick = extractMobyDick();
  LinkedList randomDick = randomQuote(dick);
  freeList(dick);
  printList(randomDick);

  printf("\n\n*** remove the last word ***\n\n");
  getchar();

  pop(&randomDick);
  printList(randomDick);

  printf("\n\n*** Add your own string to the end ***\b\n");
  char str[200];
  fgets(str, 200, stdin);
  trimBuffer(str);
  randomDick = append(randomDick, str);
  printList(randomDick);

  printf("\n\n*** Add a string to the start ***\n\n");

  fgets(str, 200, stdin);
  trimBuffer(str);
  randomDick = prepend(randomDick, str);
  printList(randomDick);

  freeList(randomDick);
  return 0;
}
