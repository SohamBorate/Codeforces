#ifdef DEBUG
    #include <chrono>
#endif
#include <iostream>
using namespace std;

typedef long long ll;

ll sgn(ll x) {
    if (x > 0) {
        return 1;
    }
    else if (x < 0) {
        return -1;
    }
    return 0;
}

int main() {
    #ifdef DEBUG
        auto start = chrono::high_resolution_clock::now();
    #endif

    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        ll k;
        cin >> k;
        cout << "n: " << n << ", k: " << k << endl;
        ll smin = 1e18;
        for (int i = 0; i < n; i++) {
            ll ai, bi, ci;
            cin >> ai >> bi >> ci;
            ll sum = ai + bi + ci;
            ll c1 = sum + k * sgn(ai - bi);
            ll c2 = sum + k * sgn(bi - ci);
            ll c3 = sum + k * sgn(ai - ci);
            if (c1 < smin) {
                smin = c1;
            }
            if (c2 < smin) {
                smin = c2;
            }
            if (c3 < smin) {
                smin = c3;
            }
            cout << "sum: " << sum << ", c1: " << c1 << ", c2: " << c2 << ", c3: " << c3 << endl;
        }
        cout << smin << endl << "======================" << endl;
    }

    #ifdef DEBUG
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << duration.count() << " ms\n";
    #endif

    return 0;
}
