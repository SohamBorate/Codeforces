#include <chrono>
#include <iostream>
using namespace std;

#define ll long long

bool check_good(ll x) {
    if (x < 100) {
        return true;
    }
    ll digits[2];
    digits[0] = x % 10;
    x /= 10;

    while (x % 10 == digits[0]) {
        x /= 10;
    }

    digits[1] = x % 10;
    x /= 10;

    ll digit = -1;
    bool flag = true;
    while (x > 0) {
        digit = x % 10;
        x /= 10;

        if (digit != digits[0] && digit != digits[1]) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    #ifdef DEBUG
        auto start = chrono::high_resolution_clock::now();
    #endif

    int t;
    cin >> t;

    while (t--) {
        ll x;
        cin >> x;

        ll i = 2;
        while ((!check_good(x * i)) || (!check_good(i))) {
            i++;
        }

        cout << i << "\n";
    }

    #ifdef DEBUG
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << duration.count() << " ms\n";
    #endif

    return 0;
}
