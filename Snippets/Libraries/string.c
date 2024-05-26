#include <stdio.h>
#include <string.h>

int ends_with(char *text, char *sub)
{
    int text_len = strlen(text);
    int sub_len = strlen(sub);
    char *sub_text = &text[text_len - sub_len];
    if (strcmp(sub_text, sub) == 0)
    {
        return 1;
    }
    return 0;
}

int starts_with(char *text, char *sub) {
    int text_len = strlen(text);
    int sub_len = strlen(sub);
    char sub_text[sub_len + 1];
    for (int i = 0; i < (sub_len + 1); i++) {
        if (i == (sub_len - 1)) {
            strcpy(sub_text[i], "\0");
        } else {
            strcpy(sub_text[i], text[i]);
        }

    }
    printf("%s\n", &sub_text[0]);
    if (strcmp(sub_text, sub) == 0)
    {
        printf("TRUE\n");
        return 1;
    }
    printf("FALSE\n");
    return 0;
}

int main() {
    // if (ends_with("Hello, World!", "World!") == 1) {
    //     printf("Hello, World! does end with World!\n");
    // }
    // if (ends_with("Hello, World!", "World") == 0) {
    //     printf("Hello, World! does not end with World\n");
    // }

    if (starts_with("Hello, World!", "Hello") == 1) {
        printf("Hello, World! does start with Hello\n");
    }
    if (starts_with("Hello, World!", "World") == 0) {
        printf("Hello, World! does not start with World\n");
    }
}