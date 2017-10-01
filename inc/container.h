// Author: Sergio Rosendo S. Jr. 
#ifndef _container_h
#define _container_h
#include <stddef.h>

typedef struct int_vector_struct intVector;

struct int_vector_struct {
  size_t capacity;
  size_t count;
  int *data;
} int_vector_struct;

#define intQueue intVector 
#define intStack intVector 

#define MINIMUM_CAP 50

intVector *new_iVec(size_t capacity);

void free_iVec(intVector *v);
int isFull_iVec(intVector *v);
int isEmpty_iVec(intVector *v);
int isWastingSpace_iVec(intVector *v);
void add_iVec(int x, intVector *v, size_t index);
int get_iVec(intVector *v, size_t index);
void delete_iVec(intVector *v, int index);
intVector *new_iQue(size_t capacity);
void free_iQue(intQueue *q);
int isFull_iQue(intQueue *q);
int isEmpty_iQue(intQueue *q);
void add_iQue(int x, intQueue *q);
int get_iQue(intQueue *q);
void delete_iQue(intQueue *q, int index);
intVector *intStack_new(size_t capacity);
void intStack_free(intStack *s);
int intStack_isFull(intStack *s);
int intStack_isEmpty(intStack *s);
void intStack_add(int x, intStack *s);
int intStack_get(intStack *s);
void intStack_delete(intStack *s, int index);

#endif