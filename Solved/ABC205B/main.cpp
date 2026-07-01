#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int arr[t] = {};
    for (int i = 0; i < t; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + t);
    string permutation = "Yes";
    for (int i = 1; i < t; i++) {
        if (arr[i] != (arr[i - 1] + 1)) {
            permutation = "No";
            break;
        }
    }
    cout << permutation;
    return 0;
}
