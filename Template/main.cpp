#include <chrono>
#include <iostream>
using namespace std;

int main() {
    auto start = chrono::high_resolution_clock::now();

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << duration.count() << " ms\n";

    return 0;
}
