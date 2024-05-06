#include <stdio.h>
#include <stdint.h>

void push_up(int l, int *convos);
int search(int l, int *array, int id);
int size(int l, int *array);

int main() {
    // input
    int n;
    int k;
    scanf("%i %i", &n, &k);

    int msgs[n];
    for (int i = 0; i < n; i++) {
        scanf("%i", &msgs[i]);
    }

    // convos
    int convos[k];
    for (int i = 0; i < k; i++) {
        convos[i] = -1;
    }

    // processing
    for (int i = 0; i < n; i++) {
        // check whether id already exist
        if (search(k, convos, msgs[i]) == -1) {
            // id doesnt exist
            push_up(k, convos);
            convos[0] = msgs[i];
        }
    }

    // output
    printf("%i\n", size(k, convos));
    for (int i = 0; i < k; i++) {
        if (convos[i] != -1) {
            printf("%i ", convos[i]);
        }
    }
    printf("\n");

    return 0;
}

void push_up(int l, int *array) {
    // bottom-to-top
    for (int i = l - 1; i > -1; i--) {
        if (i == 0) {
            // put -1 at start
            array[i] = -1;
        } else {
            // bring value 1 step down
            array[i] = array[i - 1];
        }
    }
}

int search(int l, int *array, int id) {
    // top-to-bottom
    int index = -1;
    for (int i = 0; i < l; i++) {
        if (array[i] == id) {
            index = i;
            break;
        }
    }
    return index;
}

int size(int l, int *array) {
    int s = 0;
    // top-to-bottom
    for (int i = 0; i < l; i++) {
        if (array[i] != -1) {
            s++;
        }
    }
    return s;
}