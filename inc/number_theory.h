// Author: Sergio Rosendo 
#ifndef _number_theory_h
#define _number_theory_h
#include <stddef.h>

void getResiduesModp(int p, int **rsd, size_t *rsdCnt);
int isPrimRoot(int r, int nTot, int *nTotDivisors, size_t nTotDivisorsCnt);
void getPrimitiveRoots(int n, int **roots, size_t *rootsCnt);
int mobiusFn(int n);
int mertensFn(int n);
int *mertensFnUpTo(int n);

#endif