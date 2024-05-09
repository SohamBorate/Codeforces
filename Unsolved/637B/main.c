#include <stdio.h>
#include <string.h>

int main() {
    // input
    int n;
    scanf("%i\n", &n);

    char msgs[n][10];
    for (int i = 0; i < n; i++) {
        scanf("%s\n", &msgs[i]);
    }

    // processing
    char printed[n][10];

    // struct data {
    //     char *name;
    //     int index;
    // };

    // struct node {
    //     char *name;
    //     struct node *next;
    // };

    // int search(char *person[10]) {
    //     int len = strlen(person);
    //     for (int i = 0; i < len; i++) {

    //     }
    // }

    for (int i = 0; i < n; i++) {
        strcpy(&printed[i][0], "FALSE");
    }

    int search(char person[10]) {
        // bottom-to-top
        int index = -1;
        for (int i = n - 1; i > -1; i--) {
            //printf("%i ", i);
            if (strcmp(printed[i], "FALSE") != 0) {
                if (strcmp(printed[i], person) == 0) {
                    index = i;
                    break;
                }
            } else {
                break;
            }
        }
        return index;
    }

    // bottom-to-top
    int c = 0;
    for (int i = n - 1; i > -1; i--) {
        if (search(msgs[i]) == -1) {
            strcpy(&printed[i + c][0], &msgs[i][0]);
            printf("%s\n", &msgs[i][0]);
        } else {
            c++;
        }
    }

    return 0;
}
