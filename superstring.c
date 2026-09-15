#include "superstring.h"

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

String* ss_new(void)
{
    // Allocate string struct
    String* new_str = malloc(sizeof(String));
    if (new_str == NULL) {return NULL;}

    size_t initial_capacity = 8;

    // Allocate string character data
    new_str->data = malloc(initial_capacity + 1);
    if (new_str->data == NULL) {
        free(new_str);
        return NULL;
    }

    // Set null terminator at end of string
    *new_str->data = '\0';

    // Set initial string fields
    new_str->length = 0;
    new_str->capacity = initial_capacity;

    return new_str;
}

void ss_del(String* str)
{
    // Free string data memory
    free(str->data);

    // Free object memory
    free(str);
}

bool ss_app(String* str, char* new_data)
{
    size_t added_len = strlen(new_data);
    size_t new_len = str->length + added_len;

    // Ensure string object has capacity for new data
    if (!ensure_capacity(str, new_len)) {return false;}

    char* write_pos = str->data + str->length;

    // Add new characters to string
    for (size_t i = 0; i < added_len; ++i)
    {
        *write_pos = new_data[i];
        write_pos += 1;
    }

    // Add null terminator to end of new string
    *write_pos = '\0';

    // Update length field
    str->length = new_len;

    return true;
}