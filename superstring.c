#include "superstring.h"

String* ss_new(void)
{
    // Allocate string struct
    String* new_str = malloc(sizeof(String));
    if (new_str == NULL) {return NULL;}

    size_t initial_capacity = 8;

    // Allocate string character data
    new_str->data = malloc(sizeof(char) * initial_capacity);
    if (new_str->data == NULL) {return NULL;}

    // Set initial string fields
    new_str->length = 0;
    new_str->capacity = initial_capacity;

    return new_str;
}