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

    String* str4 = ss_new("Hellld!");

    printf("%s\n", str4->data);
    printf("Length: %zu\n", str4->length);

    ss_ins(str4, "o, wor", 4);

    printf("%s\n", str4->data);
    printf("Length: %zu\n", str4->length);

    ss_ins(str4, "!!", str4->length);

    printf("%s\n", str4->data);
    printf("Length: %zu\n", str4->length);

    String* str5 = ss_new("Hellld!");
    String* str6 = ss_new("o, wor");

    printf("%s\n", str5->data);
    printf("Length: %zu\n", str5->length);

    ss_inss(str5, str6, 4);

    printf("%s\n", str5->data);
    printf("Length: %zu\n", str5->length);

    String* str7 = ss_new("!!");

    ss_inss(str5, str7, str5->length);

    printf("%s\n", str5->data);
    printf("Length: %zu\n", str5->length);

    printf("Length: %zu\n", ss_len(str5));

    ss_des(str7);
    ss_des(str6);
    ss_des(str5);
    ss_des(str4);
    ss_des(str3);
    ss_des(str2);
    ss_des(str1);

    return 0;
}