#ifdef DEBUG
    #include <chrono>
#endif
#include <iostream>
using namespace std;

typedef long long ll;

ll calculate(ll *a, ll k) {
    ll y = 0;
    y += a[k] + a[k + 2] - a[k + 4];
    return y;
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
        ll a[n];
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll p = 0;
        for (ll x = 0; x <= n - 3; x++) {
            // for (ll y = 0; y <= x - 5; y++) {
            //     if (calculate(&a[0], x) == calculate(&a[0], y)) {
            //         p++;
            //     }
            // }
            for (ll y = x + 5; y <= n - 3; y++) {
                if (calculate(&a[0], x) == calculate(&a[0], y)) {
                    p++;
                }
            }
            // if (x - 1 >= 0 && x - 1 <= n - 3) {
            //     if (calculate(&a[0], x) == calculate(&a[0], x - 1)) {
            //         p++;
            //     }
            // }
            if (x + 1 < n && x + 1 <= n - 3) {
                if (calculate(&a[0], x) == calculate(&a[0], x + 1)) {
                    p++;
                }
            }
            // if (x - 3 >= 0 && x + 3 <= n - 3) {
            //     if (calculate(&a[0], x) == calculate(&a[0], x - 3)) {
            //         p++;
            //     }
            // }
            if (x + 3 < n && x + 3 <= n - 3) {
                if (calculate(&a[0], x) == calculate(&a[0], x + 3)) {
                    p++;
                }
            }
        }
        cout << p << endl;
    }

    #ifdef DEBUG
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << duration.count() << " ms\n";
    #endif

    return 0;
}
