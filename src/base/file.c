#include "error.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>

size_t fCntLines(char fileName[]) {
  // warning: lines not ending with '\n' are not considered
  FILE *file;
  char c = 'c';
  size_t linesCnt = 0;

  if ((file = fopen(fileName, "r")) == NULL) {
    printErrNo(); // file not found
    return 0;
  }
  do {
    c = fgetc(file);
    if (c == '\n')
      linesCnt++;
  } while (c != EOF);   
  fclose(file);

  return linesCnt;
}

void freplaceChar(char fileName[], char target, char new) {
  char c;
  FILE *file;

  if ((file = fopen(fileName, "r+")) == NULL) {
    printErrNo(); // file not found
    return;
  }
  while ((c = fgetc (file)) != EOF)
    if (c == target) {
      fseek(file, ftell(file) - 1, SEEK_SET);
      fprintf(file, "%c", new);      
    }
  fclose(file);
}