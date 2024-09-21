#include <iostream>
using namespace std;

long long power(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        // cout << n << " " << k << "\n";

        long long leaves = 0;

        for (int j = n - k; j < n; j++){
            int num = j + 1;
            leaves += power(num, num);
        }

        // cout << leaves << "\n";

        if ((leaves % 2) == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
