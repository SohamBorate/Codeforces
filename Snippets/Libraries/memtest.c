#include <stdlib.h>

int main() {
    int *i = malloc(sizeof(int));
    free(i);
}