#include <stdio.h>
#include <stdlib.h>

// Utility function to find GCD of 'a' and 'b'
long long gcd(long long a, long long b) {
    while (b) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Returns LCM of array elements
long long find_lcm(long long arr[], int n) {
    long long ans = arr[0];

    for (int i = 1; i < n; i++) {
        ans = (arr[i] * ans) / gcd(arr[i], ans);
    }

    return ans;
}

// Recursive helper function to generate subsequences
void helper(long long *a, int n, long long **b, int *b_sizes, int *b_count, long long *subsequence, int sub_size, int index) {
    if (index == n) {
        if (sub_size > 0) {
            b[*b_count] = (long long *)malloc(sub_size * sizeof(long long));
            for (int i = 0; i < sub_size; i++) {
                b[*b_count][i] = subsequence[i];
            }
            b_sizes[*b_count] = sub_size;
            (*b_count)++;
        }
        return;
    }

    // Exclude the current element
    helper(a, n, b, b_sizes, b_count, subsequence, sub_size, index + 1);

    // Include the current element
    subsequence[sub_size] = a[index];
    helper(a, n, b, b_sizes, b_count, subsequence, sub_size + 1, index + 1);
}

// Function to generate all subsequences
void generate_subsequences(long long *a, int n, long long **b, int *b_sizes, int *b_count) {
    long long *subsequence = (long long *)malloc(n * sizeof(long long));
    helper(a, n, b, b_sizes, b_count, subsequence, 0, 0);
    free(subsequence);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        long long *a = (long long *)malloc(n * sizeof(long long));
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        long long **b = (long long **)malloc((1 << n) * sizeof(long long *));
        int *b_sizes = (int *)malloc((1 << n) * sizeof(int));
        int b_count = 0;

        generate_subsequences(a, n, b, b_sizes, &b_count);

        int max_length = 0;
        for (int i = 0; i < b_count; i++) {
            if (b_sizes[i] < 1) {
                continue;
            }
            long long lcm = find_lcm(b[i], b_sizes[i]);
            int found = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] == lcm) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                if (b_sizes[i] > max_length) {
                    max_length = b_sizes[i];
                }
            }
            free(b[i]);
        }

        printf("%d\n", max_length);

        free(a);
        free(b);
        free(b_sizes);
    }

    return 0;
}
