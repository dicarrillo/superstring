#include "superstring.h"
#include <stdio.h>

int main(void)
{
    // Create new string
    String* str1 = ss_new();
    if (str1 == NULL) {printf("Failed to create string.\n");}

    printf("%d\n", ss_app(str1, "Hello,"));
    printf("%d\n", ss_app(str1, " "));
    printf("%d\n", ss_app(str1, "World!"));

    // Print string contents
    printf("%s\n", str1->data);

    size_t len1 = str1->length;
    for (size_t i = 0; i < len1; ++i)
    {
        printf("%c\n", ss_at(str1, i));
    }

    ss_del(str1);

    return 0;
}