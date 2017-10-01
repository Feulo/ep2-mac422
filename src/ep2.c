#include "race.h"
#include "error.h"
#include "array.h"
#include "thread.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pthread.h>

#define TRACK_WILDTH 10 //number of rows in the track

// Global variables
static int **track = NULL; // race track 2-d array

void *th_coord(void *arg) {
  // Coordinator thread, manages the track state

  return NULL;
}

void *th_cyclist(void *arg) {
  // Cyclist thread function

  return NULL;
}

int simulateRace(size_t trackLenght, size_t lapCnt, size_t cycCnt) {
  Cyclist *cyc = NULL; // cyclists array
  pthread_t *thCyc = NULL; // cyclists thread array
  pthread_t thCoord; // track coordinator thread
  pthread_attr_t attr;
  size_t ii = 0;

  // memory allocation
  cyc = new_CycArr(cycCnt);
  if (!cyc) goto error_noMem1;
  thCyc = new_pthArr(cycCnt);
  if (!thCyc) goto error_noMem2;
  track = new_iMat(TRACK_WILDTH, trackLenght);
  if (!track) goto error_noMem3;

  /* initializes attr to detached, attr used for all cyclists threads */
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

  // race starts 
  // executes the track coordinator thread
  if (pthread_create(&thCoord, NULL, th_coord, (void *)NULL) != 0) goto error_thCreateFail1;
  // executes each cyclist thread
  for (ii = 0; ii < cycCnt; ii++)
    if (pthread_create(&(thCyc[ii]), &attr, th_cyclist, (void *)&cyc[ii]) != 0) goto error_thCreateFail2;    
  // waits for the coordinator thread to finish, it only finishes when the race is done
  pthread_join(thCoord, NULL);
  // race ends

  free_iMat(track, TRACK_WILDTH);
  free_pthArr(thCyc);
  free_CycArr(cyc);
  return 0;  

  // error treatment
  error_thCreateFail2: // could not create a cyclist thread
  for (ii = 0; ii < cycCnt; ii++) pthread_cancel(thCyc[ii]); 
  error_thCreateFail1: // could not create the coordinator thread
  printErrNo();
  pthread_cancel(thCoord);
  free_iMat(track, TRACK_WILDTH);
  error_noMem3:
  free_pthArr(thCyc);
  error_noMem2:
  free_CycArr(cyc);
  error_noMem1:
  return -1;
}

int main(int argc, char **argv) 
{
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <speedway_lenght> <number_of_laps> <number_of_cyclists>\n", argv[0]);
    return EXIT_FAILURE;
  }

  simulateRace(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
  
  return EXIT_SUCCESS;
}