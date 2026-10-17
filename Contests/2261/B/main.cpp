#ifdef DEBUG
    #include <chrono>
#endif
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    #ifdef DEBUG
        auto start = chrono::high_resolution_clock::now();
    #endif

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 1) {
            long long x;
            cin >> x;
            cout << x << "\n";
            // cout << "================\n";
            continue;
        }

        long long max = 0;
        long long min = 1e9;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            // cout << i << " " << x << "\n";
            if (x > max) {
                max = x;
            } else if (x < min) {
                min = x;
            }
        }

        if (max <= 1) {
            cout << 1 << "\n";
            // cout << "================\n";
            continue;
        }

        if (min == max) {
            cout << max << "\n";
            // cout << "================\n";
            continue;
        }

        long long tmp = max;
        long long fin = 0;
        int counter = 0;

        // cout << tmp / 2 << "\n";
        while (tmp / 2) {
            tmp /= 2;
            fin += pow(2,counter);
            counter++;
            // cout << tmp / 2 << " " << fin << "\n";
        }

        fin += pow(2,counter);

        // cout << "counter: " << counter << "\n";
        // cout << "max: " << max << "\n";

        cout << fin << "\n";

        // cout << "================\n";
    }

    #ifdef DEBUG
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << duration.count() << " ms\n";
    #endif

    return 0;
}
