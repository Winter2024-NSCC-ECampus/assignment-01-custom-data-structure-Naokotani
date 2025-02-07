#ifndef __HEADER_H__
#define __HEADER_H__
#include "linkedList.h"

#endif

LinkedList extractText(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Failed to open file");
    return create("");
  }

  char ch;
  char buffer[50];
  int i;
  LinkedList list = createEmpty();

  while ((ch = fgetc(file)) != EOF) {
    buffer[i] = ch;
    i++;
    if ('\n' == ch || ' ' == ch) {
      buffer[i] = '\0';
      i = 0;
      list = append(list, buffer);
      memset(buffer, '0', sizeof(buffer));
    }
  }

  fclose(file);
  return list;
}

void trimBuffer(char *str) {
  int i = strlen(str) - 1;

  do {
    if ((str[i] == '\n') ||
        (str[i] == '\r')) /* strip line feeds and carriage returns */
      str[i] = '\0';
    else
      break;
  } while (i--);
}
