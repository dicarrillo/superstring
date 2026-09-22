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
String* ss_new(char* data);

// Destroy a string and free its memory
void ss_des(String* str);

// Append a new string literal to the end of a string
bool ss_app(String* str, char* new_data);

// Append a substring to the end of a string
// The reference to the original substring remains intact and un-freed.
bool ss_apps(String* str, String* app_str);



// Return the character at a specified index
char ss_at(String* str, size_t index);

#endif