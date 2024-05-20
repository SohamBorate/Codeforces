#include <stdio.h>
#include <stdint.h>

int count_beautiful(uint64_t pair[3], int num_pairs, uint64_t pairs[num_pairs][3], int start_index) {
    int count = 0;
    for (int i = start_index; i < num_pairs; i++) {
        if (pair[0] != pairs[i][0] && pair[1] == pairs[i][1] && pair[2] == pairs[i][2]) {
            count++;
        } else if (pair[0] == pairs[i][0] && pair[1] != pairs[i][1] && pair[2] == pairs[i][2]) {
            count++;
        } else if (pair[0] == pairs[i][0] && pair[1] == pairs[i][1] && pair[2] != pairs[i][2]) {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    scanf("%i", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%i", &n);

        uint64_t numbers[n];
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%i ", &x);
            numbers[j] = (uint64_t)x;
        }

        int num_pairs = n - 2;
        uint64_t pairs[num_pairs][3];
        int count = 0;

        for (int j = 0; j < num_pairs; j++) {
            pairs[j][0] = numbers[j];
            pairs[j][1] = numbers[j + 1];
            pairs[j][2] = numbers[j + 2];
        }

        for (int j = 0; j < num_pairs; j++) {
            count += count_beautiful(pairs[j], num_pairs, pairs, j + 1);
        }

        printf("%i\n", count);
    }

    return 0;
}
