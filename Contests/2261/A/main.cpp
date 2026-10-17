#ifdef DEBUG
    #include <chrono>
#endif
#include <iostream>
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
        int smin = 1e6;
        int smax = 0;
        int snum = 0;
        for (int i = 1; i < n + 1; i++) {
            char x;
            cin >> x;
            if (x == '1') {
                if (i < smin) {
                    smin = i;
                } else if (i > smax) {
                    smax = i;
                }
                snum++;
            }
        }
        cout << "smin: " << smin << "\n";
        cout << "smax: " << smax << "\n";
        cout << "snum: " << snum << "\n";
        if (snum <= 1) {
            cout << 0 << "\n";
        } else {
            cout << smax - smin << "\n";
        }
        cout << "=======================\n";
    }

    #ifdef DEBUG
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << duration.count() << " ms\n";
    #endif

    return 0;
}
