#include "algebra.h"
#include "array.h"
#include <stdlib.h>
#include <stdio.h>

static int gcdR(int m, int n);

int mod_i(int a, int b) {
  if (a < 0) 
    a = b - (abs(a)%b);
  return (a%b);
}

int abs_i(int n) {
  if (n < 0) return (n*(-1));
  return n;
}

float abs_f(float n) {
  if (n < 0) return (n*(-1));
  return n;
}

double abs_d(double n) {
  if (n < 0) return (n*(-1));
  return n;
}

int pow_i(int n, int p) {
  int m;

  m = n;
  while (p-- > 1)
    n *= m;

  return n;
}

static int gcdR(int m, int n) {
  if (n == 0) return m;
  return gcdR(n, m%n);
}

int gcd(int m, int n) {
  m = abs(m);
  n = abs(n);

  if (m > n) 
    return gcdR(m, n);
  return gcdR(n, m);
}

int isCoprime(int m, int n) {
  if (gcd(m, n) == 1) 
    return 1;
  return 0;
}


void getPrimeFactors(int n, int **fac, size_t *facCnt) {
  int p;
  size_t buffSize = 20;

  n = abs(n);
  *facCnt = 0;
  *fac = new_iArr(buffSize);
  if (!*fac) return;

  for (p = 2; n > 1; p++)
    // fac points to an ordered int array containing facCnt factors of n
    for (; n > 1 && n%p == 0; n /= p) {
      if (*facCnt >= buffSize) {
        *fac = resize_iArr(*fac, (buffSize *= 2));
        if (!*fac) return;
      }
      (*fac)[*facCnt] = p;
      *facCnt += 1;
    }
  
  return;
}

int isPrime(int n) {
  int *pFacs = NULL;
  size_t pFacsCnt = 0;

  getPrimeFactors(n, &pFacs, &pFacsCnt);
  free_iArr(pFacs);

  if (pFacsCnt == 1) 
    return 1;
  return 0;
}

void getPrimeDivisors(int n, int **div, size_t *divCnt) {
  int p;
  size_t buffSize = 20;

  n = abs(n);
  *divCnt = 0;
  *div = new_iArr(buffSize);
  if (!*div) return;

  for (p = 2; n > 1; p++) {
    // fac points to an ordered int array containing facCnt factors of n
    if (n%p == 0) {
      if (*divCnt >= buffSize) {
        *div = resize_iArr(*div, (buffSize *= 2));
        if (!*div) return;
      }
      (*div)[*divCnt] = p;
      *divCnt += 1;
      while (n%p == 0) 
        n /= p;
    }
  }
  return;  
}

int eTotient(int n) {
  int *pDiv = NULL;
  int tot;
  size_t ii, pDivCnt = 0;

  getPrimeDivisors(n, &pDiv, &pDivCnt);
  if (!pDiv) return -1;

  tot = n;
  for (ii = 0; ii < pDivCnt; ii++)
    tot *= pDiv[ii] - 1;
  for (ii = 0; ii < pDivCnt; ii++)
    tot /= pDiv[ii];  

  free_iArr(pDiv);
  return tot;
}

void getPrimesUpTo(int n, int **primes, size_t *primesCnt) {
  getPrimesFromTo(2, n, primes, primesCnt);
}

void getPrimesFromTo(int m, int n, int **primes, size_t *primesCnt) {
  size_t buffSize = 50;

  *primes = new_iArr(buffSize);
  if (!*primes) goto error_noMem1;
  
  *primesCnt = 0;
  if (m <= 2) {
    (*primes)[0] = 2; 
    *primesCnt += 1;
    m = 3;
  }
  if (m%2 == 0) m++;
  for (; m <= n; m += 2) {
    if (isPrime(m)) {
      if (*primesCnt >= buffSize) {
        *primes = resize_iArr(*primes, (buffSize *= 2));
        if (!*primes) goto error_noMem1;
      }
      (*primes)[*primesCnt] = m;
      *primesCnt += 1;
    }
  }
  return;

  error_noMem1:
  *primesCnt = 0;
  return;
}



