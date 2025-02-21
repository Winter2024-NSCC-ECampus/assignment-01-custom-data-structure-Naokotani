#ifndef __HEADER_H__
#define __HEADER_H__
#include "linkedList.h"
#include "parse.h"
#include <time.h>

#endif

LinkedList extractMobyDick() { return extractText("moby_dick.txt"); }
int randomNumber(int min_num, int max_num);

LinkedList randomQuote(LinkedList list) {
  int start = randomNumber(0, list.size);
  int end = randomNumber(start, start + 150);
  return subList(list, start, end);
}

int randomNumber(int min, int max) {
  int low = 0, hi = 0;

  if (min < max) {
    low = min;
    hi = max + 1; // include max_num in output
  } else {
    low = max + 1; // include max_num in output
    hi = min;
  }

  srand(time(NULL));
  return (rand() % (hi - low)) + low;
}
