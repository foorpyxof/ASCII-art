#ifndef FPX_STRING_H
#define FPX_STRING_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// typedef struct string_t {
//   int (*GetLength)(string);
//   int (*SubstringExists)(string);
// } string;

// int string_GetLength(string* this);
// int string_SubstringExists(string* this);

int getstringlength(const char*);
int substringindex(const char*, const char*);
const char* substr_replace(const char*, const char*, const char*);
const char* string_to_lower(const char*);

#endif
