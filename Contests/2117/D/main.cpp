#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long a1, a2;
        cin >> a1 >> a2;
        int status = 1;

        // cout << a1 << " " << a2 << " inputs\n";

        long long y = (a2 - (2 * a1)) / (1 - n);

        if ((y % 1) != 0) {
            status = 0;
            cout << "NO\n";
            // continue;
        }
        
        long long x = a1 - (y * (n - 2));

        // cout << x << " " << y << " x and y\n";

        // cout << (x) + (y * (n - 2)) << " " << (x * 2) + (y * (n - 3)) << " x and y results\n";

        if ((x % 1) != 0) {
            status = 0;
            cout << "NO\n";
            // continue;
        }

        if (x > a1 || x > a2 || y > a1 || y > a2) {
            status = 0;
            cout << "NO\n";
            // continue;
        }

        for (int i = 2; i < n; i++) {
            long long k;
            cin >> k;
            if (status == 1) {
            if (k != ( (x * (i + 1)) + (y * (n - i - 2)) )) {
                status = 0;
                cout << "NO\n";
                // break;
            }
            }
        }
        if (status == 1) {
            cout << "YES\n";
        }
    }

    return 0;
}
