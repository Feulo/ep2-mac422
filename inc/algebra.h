// Author: Sergio Rosendo 
#ifndef _algebra_h
#define _algebra_h
#include <stddef.h>

int mod_i(int a, int b);
int abs_i(int n);
float abs_f(float n);
double abs_d(double n);
int pow_i(int n, int p);
int isCoprime(int m, int n);
void getPrimeFactors(int n, int **fac, size_t *facCnt);
int isPrime(int n);
void getPrimeDivisors(int n, int **div, size_t *divCnt);
int eTotient(int n);
void getPrimesUpTo(int n, int **primes, size_t *primesCnt);
void getPrimesFromTo(int m, int n, int **primes, size_t *primesCnt);

#endif