#include <chrono>
#include <iostream>
using namespace std;

int main() {
    // auto start = chrono::high_resolution_clock::now();

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        string a, b, c;
        cin >> n >> a;
        cin >> m >> b;
        cin >> c;

        string result = a;

        for (int i = 0; i < m; i++) {
            if (c[i] == 'V') {
                result = b[i] + result;
            } else {
                result = result + b[i];
            }
        }

        cout << result << "\n";
    }

    // auto end = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cout << duration.count() << " ms\n";

    return 0;
}
