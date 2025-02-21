#ifndef __HEADER_H__
#define __HEADER_H__
#include "linkedList.h"
#include "parse.h"
#include "texts.h"
#include <stdio.h>

#endif

int main() {
  printf("*** random Moby Dick quote ***\n\n\n\n");
  LinkedList dick = extractMobyDick();
  LinkedList randomDick = randomQuote(dick);
  printList(randomDick);

  printf("\n-------------------------------------\n");
  printf("\n\nKeep this quote?\n");
  printf("y to keep, any key to generate new quote\n");
  char c = getchar();

  while (c != 'y') {
    freeList(randomDick);
    randomDick = randomQuote(dick);
    printList(randomDick);
    printf("-------------------------------------\n");
    printf("Keep this quote? y\n");
    c = getchar();
  }

  freeList(dick);

  printf("\n\n*** Add your own string to the end ***\b\n");
  getchar();
  char str[200];
  fgets(str, 200, stdin);
  trimBuffer(str);

  randomDick = append(randomDick, str);
  printf("\n\n*** Add a string to the start ***\n\n");

  fgets(str, 200, stdin);
  trimBuffer(str);
  randomDick = prepend(randomDick, str);
  printList(randomDick);

  freeList(randomDick);
  return 0;
}
