#include "thread.h"
#include "error.h"
#include <stdlib.h>

pthread_t *new_pthArr(size_t size) {
  pthread_t *arr = NULL;

  arr = (pthread_t *)malloc(size*sizeof(pthread_t));
  if (!arr) printErrNo();

  return arr;
}

void free_pthArr(pthread_t *arr) {
  free(arr);
  arr = NULL;
}
