#include <stdio.h>

double calculate_d1(double h, double d, double h1) {
    return ((h - h1) / h) * d;
}

int main() {
    int m;
    scanf("%i\n", &m);

    for (int i = 0; i < m; i++) {
        int n, a2, a3;
        scanf("%i %i %i\n", &n, &a2, &a3);

        double d, h;
        d = (double)a2;
        h = (double)a3;

        double positions[n];
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%i", &x);
            positions[j] = (double)x;
        }

        // bubble sort
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (positions[j] > positions[k]) {
                    double temp = positions[j];
                    positions[j] = positions[k];
                    positions[k] = temp;
               }
           }
        }

        double area = 0;

        for (int j = 0; j < n; j++) {
            if (j == n - 1) {
                area += 0.5 * d * h;
            } else {
                double y0 = positions[j];
                double y1 = positions[j + 1];
                double h1 = y1 - y0;
                if (h1 >= h) {
                    area += 0.5 * d * h;
                } else {
                    double d1 = calculate_d1(h, d, h1);
                    area += h1 * ((d + d1) / 2.0);
                }
            }
        }

        printf("%lf \n", area);
    }
    return 0;
}