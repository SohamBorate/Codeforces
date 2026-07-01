#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    long arr[t] = {};
    long long sum = 0;
    for (long long i = 0; i < t; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    long long x;
    cin >> x;
    long long total = (x / sum) * sum;
    long long index = (x / sum) * t;
    long long i = 0;

    while (total <= x) {
        total += arr[i];
        i++;
        index++;
        if (i >= t) {
            i = 0;
        }
    }

    cout << index << "\n";
    return 0;
}
