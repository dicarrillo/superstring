#ifndef SUPERSTRING_H
#define SUPERSTRING_H

#include <stdlib.h>

// String type struct
typedef struct {
    char* data;
    size_t length;
    size_t capacity;
} String;

// Create a new string
String* ss_new(void);

// Delete a string and free its memory
void ss_del(String* str);

#endif