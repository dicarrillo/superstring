#include "superstring.h"
#include <stdio.h>

int main(void)
{
    // Create new string
    String* str1 = ss_new();
    if (str1 == NULL) {printf("Failed to create string.\n");}

    ss_del(str1);

    return 0;
}