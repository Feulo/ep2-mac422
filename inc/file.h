#ifndef _file_h
#define _file_h
#include <stddef.h>

size_t fCntLines(char fileName[]);
// Returns the amount of '\n' characters in a file 
void freplaceChar(char fileName[], char target, char new);
// Replaces target characters in file with the new character

#endif