#include <stdio.h>
#include <stdlib.h>

int calculate_points(double d, double *points, int k) {
    int index = 0;

    for (int j = 0; j < (k + 1); j++) {
        if (d == points[j]) {
            index = j;
            break;
        } else if (d > points[j] && d < points[j + 1]) {
            index = j;
            break;
        }
    }

    return index;
}

int main() {
    int t;
    scanf("%i\n", &t);

    for (int i = 0; i < t; i++) {
        int a1, k, q;
        scanf("%i %i %i\n", &a1, &k, &q);
        double n = (double)a1;

        double points[k + 1];
        points[0] = 0.0;
        for (int j = 1; j < (k + 1); j++) {
            int x;
            scanf("%i ", &x);
            points[j] = (double)x;
        }

        double minutes[k + 1];
        minutes[0] = 0.0;
        for (int j = 1; j < (k + 1); j++) {
            int x;
            scanf("%i ", &x);
            minutes[j] = (double)x;
        }

        double queries[q];
        for (int j = 0; j < q; j++) {
            int x;
            scanf("%i ", &x);
            queries[j] = (double)x;
        }

        for (int j = 0; j < q; j++) {
            double query = queries[j];
            double time = 0.0;

            int index = calculate_points(query, points, k);
            double p0 = points[index];
            double p1 = points[index + 1];
            double t0 = minutes[index];
            double t1 = minutes[index + 1];

            time += t0;

            double speed = (p1 - p0) / (t1 - t0);

            time += (query - p0) / speed;

            printf("%i ", (int)time);
        }
        printf("\n");
    }

    return 0;
}
