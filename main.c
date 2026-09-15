#include "superstring.h"
#include <stdio.h>

int main(void)
{
    // Create new string
    String* str1 = ss_new();
    if (str1 == NULL) {printf("Failed to create string.\n");}

    printf("%d\n", ss_app(str1, "Hello, World!"));

    // Print string contents
    printf("%s\n", str1->data);

    ss_del(str1);

    return 0;
}