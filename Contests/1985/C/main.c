#include <stdio.h>

int main() {
    int t;
    scanf("%i", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%i", &n);
        long long int a[n];

        for (int j = 0; j < n; j++) {
            long long int x;
            scanf("%lld ", &x);
            a[j] = x;
        }

        int arrs = 0;

        for (int j = 1; j < n + 1; j++) {
            // form sub-array from 0->j-1
            // printf("size 0 -> %i\n", j);
            for (int k = 0; k < j; k++) {
                // printf("to be ignored %i :- %lld\n", k, a[k]);
                long long int sum = 0;
                for (int l = 0; l < j; l++) {
                    if (l != k) {
                        // printf("%i => %lld\n", l, a[l]);
                        sum += a[l];
                    }
                }
                // printf("%lld\n", sum);
                if (sum == a[k]) {
                    // printf("Valid: %lld\n", a[k]);
                    arrs++;
                    break;
                }
            }
            // printf("\n\n");
        }
        printf("%i\n", arrs);
    }

    return 0;
}
