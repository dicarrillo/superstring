#include "superstring.h"

// Ensure that the string has enough allocated memory for a desired data capacity
bool ensure_capacity(String* str, size_t capacity)
{
    while (str->capacity < capacity)
    {
        // Double capacity (reallocate data to new block)
        char* temp = realloc(str->data, str->capacity * 2 + 1);
        if (temp == NULL) {return false;}
        str->data = temp;
        str->capacity = str->capacity * 2;
    }

    return true;
}

// Append new characters onto the end of a string
bool append(String* str, char* data, size_t app_len)
{
    size_t new_len = str->length + app_len;

    // Ensure string object has capacity for new data
    if (!ensure_capacity(str, new_len)) {return false;}

    char* write_pos = str->data + str->length;

    // Add new characters to string
    for (size_t i = 0; i < app_len; ++i)
    {
        *write_pos = data[i];
        write_pos += 1;
    }

    // Add null terminator to end of new string
    *write_pos = '\0';

    // Update length field
    str->length = new_len;

    return true;
}

bool insert(String* str, char* data, size_t ins_len, size_t index)
{
    if (index > str->length) {return false;}

    size_t new_len = str->length + ins_len;

    // Ensure string object has capacity for new data
    if (!ensure_capacity(str, new_len)) {return false;}

    // Shift items at and beyond insert index to make space for insert string
    memmove(&str->data[index] + ins_len, &str->data[index], ins_len);

    char* write_pos = &str->data[index];

    // Insert new characters in string
    for (size_t i = 0; i < ins_len; ++i)
    {
        *write_pos = data[i];
        write_pos += 1;
    }

    // Add null terminator to end of shifted string
    str->data[new_len] = '\0';

    // Update length field
    str->length = new_len;

    return true;
}

String* ss_new(char* data)
{
    // Allocate string struct
    String* new_str = malloc(sizeof(String));
    if (new_str == NULL) {return NULL;}

    size_t initial_capacity = 1;

    // Allocate string character memory (including null terminator)
    new_str->data = malloc(initial_capacity + 1);
    if (new_str->data == NULL) {
        free(new_str);
        return NULL;
    }

    // Set null terminator
    *new_str->data = '\0';

    // Set initial string fields
    new_str->length = 0;
    new_str->capacity = initial_capacity;

    // Append data to new string
    if (!ss_app(new_str, data)) {
        ss_des(new_str);
        return NULL;
    }

    return new_str;
}

void ss_des(String* str)
{
    // Free string data memory
    free(str->data);

    // Free object memory
    free(str);
}

bool ss_app(String* str, char* new_data)
{
    return append(str, new_data, strlen(new_data));
}

bool ss_apps(String* str, String* app_str)
{
    return append(str, app_str->data, app_str->length);
}

bool ss_ins(String* str, char* new_data, size_t index)
{
    return insert(str, new_data, strlen(new_data), index);
}

bool ss_inss(String* str, String* ins_str, size_t index)
{
    return insert(str, ins_str->data, ins_str->length, index);
}

char ss_at(String* str, size_t index)
{
    return str->data[index];
}

size_t ss_len(String* str)
{
    return str->length;
}