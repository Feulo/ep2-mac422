#include "container.h"
#include "array.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>

intVector *new_iVec(size_t capacity) {
  intVector *v = NULL;

  v = (intVector *)malloc(sizeof(intVector));
  if (!v) {
    printErrNo();
    return NULL;
  }
  v->data = new_iArr(capacity);
  if (!v->data) {
    free_iVec(v);
    return NULL;
  }
  v->capacity = capacity;
  v->count = 0;

  return v;
}

void free_iVec(intVector *v) {
  if (v->data) free_iArr(v->data);
  free(v);
  v = NULL;
}

int isFull_iVec(intVector *v) {
  if (v->count >= v->capacity)
    return 1;
  return 0;
}

int isEmpty_iVec(intVector *v) {
  if (v->count <= 0)
    return 1;
  return 0;
}

int isWastingSpace_iVec(intVector *v) {
  if (v->count > MINIMUM_CAP && v->count < v->capacity/5)
    return 1;
  return 0;
}

void add_iVec(int x, intVector *v, size_t index) {
  if (isFull_iVec(v)) {
    v->data = resize_iArr(v->data, (v->capacity *= 2));
    if (!v->data) return;
  }

  push_iArr(v->data, index, v->count);
  v->data[index] =  x;
  v->count += 1;
  return;
}

int get_iVec(intVector *v, size_t index) {
  int x;
  
  if (isEmpty_iVec(v)) {
    printWarning("Tried to get element from an empty vector, 0 was returned");
    return 0;
  }
  x = v->data[index];
  pull_iArr(v->data, index, v->count);
  v->count -= 1;
  if (isWastingSpace_iVec(v)) {
    v->data = resize_iArr(v->data, (v->capacity /= 2));
    if (!v->data) { 
      printErrNo();
      return 0;
    }
  }

  return x;
}

void delete_iVec(intVector *v, int index) {
  if (isEmpty_iVec(v)) return;
  pull_iArr(v->data, index, v->count);
  v->count -= 1;
  return;
}

intVector *new_iQue(size_t capacity) {
  return (new_iVec(capacity));
}

void free_iQue(intQueue *q) {
  free_iVec(q);
}

int isFull_iQue(intQueue *q) {
  return (isFull_iVec(q));
}

int isEmpty_iQue(intQueue *q) {
  return (isEmpty_iVec(q));
}

void add_iQue(int x, intQueue *q) {
  add_iVec(x, q, q->count);
}

int get_iQue(intQueue *q) {
  return get_iVec(q, 0);
}

void delete_iQue(intQueue *q, int index) {
  delete_iVec(q, index);
}

intVector *intStack_new(size_t capacity) {
  return (new_iVec(capacity));
}

void intStack_free(intStack *s) {
  free_iVec(s);
}

int intStack_isFull(intStack *s) {
  return (isFull_iVec(s));
}

int intStack_isEmpty(intStack *s) {
  return (isEmpty_iVec(s));
}

void intStack_add(int x, intStack *s) {
  add_iVec(x, s, s->count);
}

int intStack_get(intStack *s) {
  return get_iVec(s, s->count-1);
}

void intStack_delete(intStack *s, int index) {
  delete_iVec(s, index);
}