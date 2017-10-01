// Author: Sergio Rosendo 
#ifndef _sundry_h
#define _sundry_h
#include <stddef.h>
#include <sys/time.h>
#include <sys/types.h>

#define swap(a, b) _Generic(a, int *: swap_i, unsigned *: swp_u, char *: swp_c, float *: swp_f, double *: swp_d)(a, b)
void swp_i(int *a, int *b);
void swp_u(unsigned *a, unsigned *b);
void swp_c(char *a, char *b);
void swp_f(float *a, float *b);
void swp_d(double *a, double *b);

int max_i(int a, int b);
unsigned max_u(unsigned a, unsigned b);
char max_c(char a, char b);
float max_f(float a, float b);
double max_d(double a, double b);

int min_i(int a, int b);
unsigned min_u(unsigned a, unsigned b);
char min_c(char a, char b);
float min_f(float a, float b);
double min_d(double a, double b);

double random_d(double max_v);
double getTimeSpent(struct timeval startTime);
// Returns the difference in seconds between startTime and current time. 
void iToStr(int n, char dest[]);
// Stores in dest[] the string corresponding to n 
unsigned pVMsize(pid_t procPID);
// Returns the current virtual memory usage (in kBytes) of the calling process

#endif