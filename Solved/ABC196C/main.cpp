#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;

    for (long long i = 1; i < t + 1; i++) {
        if (stoll(to_string(i) + to_string(i)) > t) {
            cout << i - 1 << "\n";
            return 0;
        }
    }

    return 0;
}
