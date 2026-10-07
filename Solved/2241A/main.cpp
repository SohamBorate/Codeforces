#include <chrono>
#include <iostream>
using namespace std;

int main() {
    #ifdef DEBUG
        auto start = chrono::high_resolution_clock::now();
    #endif

    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        if (x == y) {
            cout << "YES\n";
            continue;
        }

        if (x < y) {
            cout << "NO\n";
            continue;
        }

        if (x % y == 0) {
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }

    #ifdef DEBUG
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << duration.count() << " ms\n";
    #endif

    return 0;
}
