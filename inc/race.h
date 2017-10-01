// Author: Sergio Rosendo 
#ifndef _race_h
#define _race_h
#include <stddef.h>

typedef struct cyclist_struct Cyclist;

struct cyclist_struct {
  int points;
  int points_placing;
  int placing;
  int lap;
  int speed;
  int id;
  int accident_lap;
  int accident_placing;
  int accident_points_placing;
} cyclist_struct;

Cyclist init_Cyc(int cycId);
Cyclist *new_CycArr(size_t size);
void free_CycArr(Cyclist *cycArr);

#endif