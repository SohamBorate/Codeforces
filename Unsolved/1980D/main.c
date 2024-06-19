#include <stdio.h>

// calculate gcd
int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// non decreasing
int non_decreasing_gcd(int arr[], int n) {
    int status = 0;
    for (int i = 1; i < n - 1; i++) {
        if (gcd(arr[i - 1], arr[i]) > gcd(arr[i], arr[i + 1])) {
            status = 1;
            break;
        }
    }
    return status;
}

int main() {
    int t;
    scanf("%i", &t);

    while(t--) {
        int n;
        scanf("%i", &n);
        int a[n];
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%i ", &x);
            a[j] = x;
        }

        if (non_decreasing_gcd(a, n) == 0) {
            printf("YES\n");
            continue;
        }

        int not_possible = 1;

        // iterate over removing an element one-by one
        for (int j = 1; j < n - 1; j++) {
            int gcd0 = gcd(a[j - 1], a[j]);
            int gcd1 = gcd(a[j], a[j + 1]);

            // printf("[%i, %i, %i] [%i, %i]\n", a[j - 1], a[j], a[j + 1], gcd0, gcd1);

            if (gcd0 > gcd1) {
                // printf("Issue\n");
                for (int k = -1; k < 2; k++) {
                    // printf("To be ignored: %i: %i\n", j + k, a[j + k]);

                    int a_2[n - 1];
                    int counter = 0;
                    for (int l = 0; l < n; l++) {
                        if (l != j + k) {
                            a_2[counter] = a[l];
                            counter++;
                        }
                    }

                    if (non_decreasing_gcd(a_2, n - 1) == 0) {
                        not_possible = 0;
                        break;
                    }
                }
            }

            if (not_possible == 0) {
                break;
            }
        }

        if (not_possible == 0) {
            printf("YES\n");
        } else if (not_possible == 1) {
            printf("NO\n");
        }
    }

    return 0;
}
