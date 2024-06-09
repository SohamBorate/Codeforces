#include <stdio.h>

long long int modulus(long long int n) {
    if (n < 0) {
        n *= -1;
    }
    return n;
}

int main() {
    int t;
    scanf("%i", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%i", &n);

        long long int c = 0;

        for (int j = 0; j < n; j++) {
            long long int x;
            scanf("%lld ", &x);
            // printf("%lld %lld\n", c, x);
            if (c <= 0 && x < 0) {
                c += x;
            } else if (c <= 0 && x >= 0) {
                c = modulus(c) + x;
            } else if (c >= 0) {
                c += x;
            }
        }

        printf("%lld\n", modulus(c));

    }

    return 0;
}
