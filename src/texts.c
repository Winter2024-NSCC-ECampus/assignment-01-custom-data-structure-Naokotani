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
  int end = randomNumber(start, start + 300);
  return subList(list, start, end);
}

int randomNumber(int min_num, int max_num) {
  int result = 0, low_num = 0, hi_num = 0;

  if (min_num < max_num) {
    low_num = min_num;
    hi_num = max_num + 1; // include max_num in output
  } else {
    low_num = max_num + 1; // include max_num in output
    hi_num = min_num;
  }

  srand(time(NULL));
  result = (rand() % (hi_num - low_num)) + low_num;
  return result;
}
