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
int non_decreasing(int arr[], int n) {
    int status = 1;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            status = 0;
        }
    }
    return status;
}

int main() {
    int t;
    scanf("%i", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%i", &n);
        int a[n];
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%i ", &x);
            a[j] = x;
        }


        int possible = 0;

        // iterate over removing an element one-by one
        for (int j = 0; j < n; j++) {
            int to_remove = j;


            int gcd_nums2[n - 2];



            for (int k = 0; k < n - 1; k++) {
                int index_0 = k;
                int index_1 = k + 1;
                if (index_0 == to_remove) {continue;}

                // get index_1 which is not to_remove
                if (index_1 == to_remove) {
                    index_1++;
                    if (index_1 >= (n)) {continue;}
                }

                gcd_nums2[k] = gcd(a[index_0], a[index_1]);
            }


            possible = non_decreasing(gcd_nums, n - 2);
            if (possible == 1) {
                break;
            }
        }

        if (possible == 1) {
            printf("YES\n");
        } else if (possible == 0) {
            printf("NO\n");
        }
    }

    return 0;
}
