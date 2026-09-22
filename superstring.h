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

// Append a string to the end of another string
// The reference to the original append string remains intact and un-freed.
bool ss_apps(String* str, String* app_str);

// Insert a new string literal into a string
bool ss_ins(String* str, char* new_data, size_t index);

// Insert a string into another string
// The reference to the original insert string remains intact and un-freed.
bool ss_inss(String* str, String* ins_str, size_t index);

// Return the character at a specified index
char ss_at(String* str, size_t index);

#endif