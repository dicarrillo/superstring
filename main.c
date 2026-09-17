#include "superstring.h"
#include <stdio.h>

int main(void)
{
    // Create new string
    String* str1 = ss_new("");
    if (str1 == NULL) {printf("Failed to create string 1.\n");}

    printf("Length: %zu\n", str1->length);

    printf("%d\n", ss_app(str1, "Hello,"));
    printf("%d\n", ss_app(str1, " "));
    printf("%d\n", ss_app(str1, "World!"));

    // Print string contents
    printf("%s\n", str1->data);
    printf("Length: %zu\n", str1->length);

    size_t len1 = str1->length;
    for (size_t i = 0; i < len1; ++i)
    {
        printf("%c\n", ss_at(str1, i));
    }

    String* str2 = ss_new("Was it a car or ");
    if (str2 == NULL) {printf("Failed to create string 2.\n");}

    printf("%s\n", str2->data);
    printf("Length: %zu\n", str2->length);

    ss_app(str2, "a cat I saw");
    printf("%s\n", str2->data);
    printf("Length: %zu\n", str2->length);

    ss_app(str2, ".");
    printf("%s\n", str2->data);
    printf("Length: %zu\n", str2->length);

    ss_app(str2, "");
    printf("%s\n", str2->data);
    printf("Length: %zu\n", str2->length);

    ss_apps(str2, str1);
    printf("%s\n", str2->data);
    printf("Length: %zu\n", str2->length);

    ss_apps(str1, str2);
    printf("%s\n", str1->data);
    printf("Length: %zu\n", str1->length);

    String* str3 = ss_new("");

    ss_apps(str3, str1);
    printf("%s\n", str1->data);
    printf("Length: %zu\n", str1->length);

    ss_des(str3);
    ss_des(str2);
    ss_des(str1);

    return 0;
}