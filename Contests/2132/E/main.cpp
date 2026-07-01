#include <chrono>
#include <iostream>
using namespace std;

long long find_largest(long long arr[], long long n, int used[]) {
    long long num = -1;
    long long index = -1;
    for (long long i = 0; i < n; i++) {
        if (arr[i] > num && used[i] == 0) {
            num = arr[i];
            index = i;
        }
    }
    return index;
}

int main() {
    // auto start = chrono::high_resolution_clock::now();

    int t;
    cin >> t;

    while (t--) {
        long long n, m, q;
        cin >> n >> m >> q;

        long long x[n];
        int used_x[n];
        long long y[m];
        int used_y[m];

        for (long long i = 0; i < n; i++) {
            long long hehe;
            cin >> hehe;
            x[i] = hehe;
            used_x[i] = 0;
        }

        for (long long i = 0; i < m; i++) {
            long long hehe;
            cin >> hehe;
            y[i] = hehe;
            used_y[i] = 0;
        }

        // each round
        for (long long hehe = 0; hehe < q; hehe++) {
            long long xi, yi, zi;
            cin >> xi >> yi >> zi;
            long long sum = 0;
            long long x_taken = 0;
            long long y_taken = 0;
            for (long long i = 0; i < zi; i++) {
                // check which is greater, select
                long long max_x_index = find_largest(x, n, used_x);
                long long max_x = x[max_x_index];

                long long max_y_index = find_largest(y, m, used_y);
                long long max_y = y[max_y_index];

                if (x_taken < xi && y_taken < yi) {
                    if (max_x >= max_y) {
                        // put x
                        x_taken++;
                        sum += max_x;
                        used_x[max_x_index] = 1;
                    } else {
                        // put y
                        y_taken++;
                        sum += max_y;
                        used_y[max_y_index] = 1;
                    }
                } else if (y_taken < yi) {
                    // put y
                    y_taken++;
                    sum += max_y;
                    used_y[max_y_index] = 1;
                } else if (x_taken < xi) {
                    // put x
                    x_taken++;
                    sum += max_x;
                    used_x[max_x_index] = 1;
                }
            }

            cout << sum << "\n";

            for (long long i = 0; i < n; i++) {
                used_x[i] = 0; 
            }
            for (long long i = 0; i < m; i++) {
                used_y[i] = 0; 
            }
        }
    }

    // auto end = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cout << duration.count() << " ms\n";

    return 0;
}
