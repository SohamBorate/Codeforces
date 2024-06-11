#include <stdio.h>

int main() {
    int t;
    scanf("%i", &t);

    for (int i = 0; i < t; i++) {
        int h, n;
        scanf("%i %i\n", &h, &n);
        printf("%i %i\n", h, n);

        int a[n];
        int c[n];
        int next_attack[n];

        for (int j = 0; j < n; j++) {
            int x;
            scanf("%i ", &x);
            a[j] = x;
            next_attack[j] = 0;
            printf("%i ", a[j]);
        }
        printf("\n");
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%i ", &x);
            c[j] = x;
            printf("%i ", c[j]);
        }
        printf("\n\n");

        long long int turns = 0;

        void calculate() {
            long long int max = 0;
            for (int j = 0; j < n; j++) {
                // printf("%i ", next_attack[j]);
                if (next_attack[j] > max) {
                    max = next_attack[j];
                }
            }

            long long int min = max;
            for (int j = 0; j < n; j++) {
                // printf("%i ", next_attack[j]);
                if (next_attack[j] < min) {
                    min = next_attack[j];
                }
            }

            // printf("\n");

            turns += min;

            // printf("%i %i\n", turns, min);

            for (int j = 0; j < n; j++) {
                if (next_attack[j] <= turns) {
                    // printf("Attack %i: %i\n", j, a[j]);
                    h -= a[j];
                    next_attack[j] = turns + c[j];
                }
            }
            // printf("Turn %i %i\n\n", turns + 1, h);
        }

        while (h > 0) {

            calculate();
        }
        printf("\n%lld\n\n\n", turns);
    }

    return 0;
}
