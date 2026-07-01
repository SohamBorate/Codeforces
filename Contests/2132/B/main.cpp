#include <chrono>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // auto start = chrono::high_resolution_clock::now();

    int t;
    cin >> t;

    for (int hehe = 0; hehe < t; hehe++) {
        long double n;
        cin >> n;

        if (fmod(n, 10) == 0) {
            cout << "0\n";
            continue;
        }

        int k = 1;
        long double test = test = n / (1 + pow(10, k));
        // cout << n << ": ";

        int found = 0;

        while (test >= 1) {
            if (fmod(test,1) == 0) {
                found++;
            }
            k++;
            test = n / (1 + pow(10, k));
        }

        k--;
        test = n / (1 + pow(10, k));

        cout << found << "\n";

        while (k >= 1) {
            if (fmod(test,1) == 0) {
                cout << (long long)test << " ";
            }
            k--;
            test = n / (1 + pow(10, k));
        }

        // while (test > 1) {
        //     if (fmod(test, 1.0) == 0.0) {
        //         cout << (long long) test << " ";
        //     }
        //     k++;
        //     test = n / (1 + pow(10, k));
        // }
        if (found > 0) {
            cout << "\n";
        }
    }

    // auto end = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cout << duration.count() << " ms\n";

    return 0;
}
