// Author: Sergio Rosendo S. Jr. 
#ifndef _error_h
#define _error_h

#define printErrNo() pErrNo(__func__,  __FILE__, __LINE__)
#define printError(errorMsg) pError(errorMsg, __func__, __FILE__, __LINE__)
#define printWarning(warningMsg) pWarning (warningMsg, __func__, __FILE__, __LINE__)

void pErrNo(const char funcName[], const char srcFileName[], int srcLine);
void pError(const char errorMsg[], const char funcName[], const char srcFileName[], int srcLine);
void pWarning(const char warningMsg[], const char funcName[], const char srcFileName[], int srcLine);

#endif