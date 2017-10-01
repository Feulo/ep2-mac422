#include "race.h"
#include <stdio.h>
#include <stdlib.h>

Cyclist init_Cyc(int cycId) {
  Cyclist c;

  c.points = 0;
  c.points_placing = -1;
  c.placing = -1;
  c.lap = 0;
  c.speed = 0;
  c.id = cycId;  
  c.accident_lap = -1;
  c.accident_placing = -1;
  c.accident_points_placing = -1;

  return c;
}

Cyclist *new_CycArr(size_t size) {
  Cyclist *cycArr;

  cycArr = (Cyclist *)malloc(size*sizeof(cyclist_struct));
  if (!cycArr) 
    fprintf(stderr, "error: CycArray_new() could not allocate memory\n");

  return cycArr;
}

void free_CycArr(Cyclist *cycArr) {
  free(cycArr);
  cycArr = NULL;
}