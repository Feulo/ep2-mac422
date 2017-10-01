/* Author: Sergio Rosendo */
#ifndef _thread_h
#define _thread_h
#include <pthread.h>
#include <stddef.h>

pthread_t *new_pthArr(size_t size);
void free_pthArr(pthread_t *arr);

#endif