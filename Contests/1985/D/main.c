#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%i", &t);

    for (int i = 0; i < t; i++) {
        int n, m;
        scanf("%i %i\n", &n, &m);

        char map[n][m];

        for (int j = 0; j < n; j++) {
            // row
            for (int k = 0; k < m; k++) {
                // column
                scanf("%c", &map[j][k]);
            }
            getchar();
        }

        // row, column
        int a,b = 0;

        int row_count = 0;

        for (int j = 0; j < n; j++) {
            // row
            int sum = 0;
            for (int k = 0; k < m; k++) {
                // column
                if (map[j][k] == '#') {
                    // printf("T");
                    sum++;
                } else {
                    // printf("F");
                }
            }
            if (sum > row_count) {
                row_count = sum;
                a = j + 1;
            }
            // printf(" %i\n\n", sum);
        }

        int column_count = 0;

        for (int j = 0; j < m; j++) {
            // column
            int sum = 0;
            for (int k = 0; k < n; k++) {
                // row
                if (map[k][j] == '#') {
                    // printf("T");
                    sum++;
                } else {
                    // printf("F");
                }
            }
            if (sum > column_count) {
                column_count = sum;
                b = j + 1;
            }
            // printf(" %i\n\n", sum);
        }

        printf("%i %i\n", a, b);
    }

    return 0;
}
