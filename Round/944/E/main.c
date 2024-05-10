#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int m;
    scanf("%i\n", &m);
  // printf("%i\n\n", m);

    for (int i = 0; i < m; i++) {
        int n, k, q;
        scanf("%i %i %i", &n, &k, &q);
      // printf("%i %i %i\n\n", n, k, q);

        int points[k + 1];
        points[0] = 0;
        for (int j = 0; j < k; j++) {
            scanf("%i", &points[j + 1]);
          // printf("%i ", points[j + 1]);
        }

      // printf("\n\n");

        int mins[k + 1];
        mins[0] = 0;
        for (int j = 0; j < k; j++) {
            scanf("%i", &mins[j + 1]);
          // printf("%i ", mins[j + 1]);
        }

      // printf("\n\n");
        
        int passed[q];
        for (int j = 0; j < q; j++) {
            scanf("%i\n", &passed[j]);
          // printf("%i ", passed[j]);
        }

      // printf("\n\n");

        int calculate_points(int d) {
            int index = 0;

            for (int l = 0; l < k; l++) {
                if (d < points[l + 1] && d >= points[l]) {
                    index = l;
                    break;
                }
            }

            return index;
        }

        for (int j = 0; j < q; j++) {
            if (passed[j] != 0)  {
                int index = calculate_points(passed[j]);
              // printf("%i %i\n", index, passed[j]);
                float time = 0.0;

                for (int l = 0; l < (index); l++) {
                    int t = mins[l + 1] - mins[l];
                    time += (float)t;
                }

              // printf("%.2f\n", time);

                int t = mins[index + 1] - mins[index];
                int d = points[index + 1] - points[index];
                int dt = passed[j] - points[index];
                float speed = (float)d / (float)t;

              // printf("%i %i %.2f %i %.2f\n", t, d, speed, dt, dt/speed);

                if (dt/speed == 99999999) {
                    time += (dt / (int) speed);
                } else {
                                    time += (dt / speed);

                }

              // printf("%i \n\n", (int)time);
                printf("%i ", (int)time);
            } else {
              // printf("%i \n\n", 0);
                printf("%i ", 0);
            }
        }

        printf("\n");

      // printf("\n\n");
    }

    return 0;
}
