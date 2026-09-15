#ifndef SUPERSTRING_H
#define SUPERSTRING_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

// Append a new string literal to the end of a string
bool ss_app(String* str, char* new_data);

#endif