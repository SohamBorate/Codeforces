#include <stdio.h>

int main() {
    int t;
    scanf("%i", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%i", &n);

        unsigned int a[n];

        for (int j = 0; j < n; j++) {
            unsigned int x;
            scanf("%d ", &x);
            a[j] = x;
        }

        if (a[0] == a[n - 1]) {
            printf("NO\n");
        } else {
            printf("YES\n");

            char s[n + 1];
            s[n] = '\0';

            s[0] = 'R';
            s[n - 1] = 'B';

            for (int j = 1; j < n - 1; j++) {
                if (a[j] == a[0]) {
                    s[j] = 'R';
                } else {
                    s[j] = 'B';
                }
            }

            printf("%s\n", s);
        }

    }

    return 0;
}
