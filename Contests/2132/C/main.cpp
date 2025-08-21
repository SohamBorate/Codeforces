#include <chrono>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long money(long long x) {
    return pow(3, x + 1) + (x * pow(3, x - 1));
}

int main() {
    // auto start = chrono::high_resolution_clock::now();

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long x = 0;

        while (pow(3,x) <= n) {
            x++;
        }

        x--;

        if (pow(3,x) == n) {
            cout << money(x) << "\n";
            continue;
        }

        long long cost = 0;
        long long f = pow(3,x);

        // cout << cost << " " << x << " " << f << " " << n << "\n";

        while (f <= n && n != 0) {
            n -= f;
            cost += money(x);
            while (f > n) {
                x--;
                f = pow(3,x);
            }
            // cout << cost << " " << x << " " << f << " " << n << "\n";
        }

        cout << cost << "\n";

    }

    // auto end = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cout << duration.count() << " ms\n";

    return 0;
}
