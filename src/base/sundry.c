// Miscellaneous functions
// Author: Sergio Rosendo 
#include "sundry.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_FILE_NAME_LENGHT 100
#define MAX_FILE_PATH_LENGHT 300

void swp_i(int *a, int *b) {
  int tmp;

  tmp = *a; *a = *b; *b = tmp;
}

void swp_u(unsigned *a, unsigned *b) {
  unsigned tmp;

  tmp = *a; *a = *b; *b = tmp;
}

void swp_c(char *a, char *b) {
  char tmp;

  tmp = *a; *a = *b; *b = tmp;
}

void swp_f(float *a, float *b) {
  float tmp;

  tmp = *a; *a = *b; *b = tmp;
}

void swp_d(double *a, double *b) {
  double tmp;

  tmp = *a; *a = *b; *b = tmp;
}

int max_i(int a, int b) {
  if (a > b) return a;
  return b;
}

unsigned max_u(unsigned a, unsigned b) {
  if (a > b) return a;
  return b;
}

char max_c(char a, char b) {
  if (a > b) return a;
  return b;
}

float max_f(float a, float b) {
  printf ("oi\n");
  if (a > b) return a;
  return b;
}

double max_d(double a, double b) {
  if (a > b) return a;
  return b;
}

int min_i(int a, int b) {
  if (a > b) return b;
  return a;
}

unsigned min_u(unsigned a, unsigned b) {
  if (a > b) return b;
  return a;
}

char min_c(char a, char b) {
  if (a > b) return b;
  return a;
}

float min_f(float a, float b) {
  if (a > b) return b;
  return a;
}

double min_d(double a, double b) {
  if (a > b) return b;
  return a;
}

double random_d(double max) {
  return (double)rand()/(double)((double)RAND_MAX/max);
}

double getTimeSpent(struct timeval startTime) {
  // Calculates the time spent executing the main function 
  double tf;
  struct timeval currentTime;

  gettimeofday(&currentTime, NULL); 
  tf = (double)(currentTime.tv_usec - startTime.tv_usec)/1000000 
     + (double)(currentTime.tv_sec - startTime.tv_sec);

  return tf;
}

void iToStr(int n, char dest[]) {
    char const digit[] = "0123456789";
    char *p = dest;
    int shifter;
    
    if (n < 0) n *= -1;
    shifter = n;

    do {
        ++p;
        shifter = shifter/10;
    } while (shifter);
    *p = '\0';
    do { 
        *--p = digit[n%10];
        n = n/10;
    } while (n); 
}

unsigned pVMsize(pid_t procPID) {
  FILE* statusFile; 
  unsigned vmSize = 0;
  char line[50], pidFolder[50]; 
  char path[MAX_FILE_PATH_LENGHT] = "/proc/", path_suffix[] = "/status";

  iToStr((int)procPID, pidFolder);
  strcat(path, pidFolder);
  strcat(path, path_suffix);

  if ((statusFile = fopen(path, "r"))== NULL) {
    printErrNo();
    return 0;
  }
  while (!vmSize) {
    if (!fgets(line, 50, statusFile))
      return 1;
    if (strncmp(line, "VmSize:", 7) == 0)
      vmSize = (unsigned) atoi(&line[8]);
  }
  fclose(statusFile);
  
  return vmSize;
}

