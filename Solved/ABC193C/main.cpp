#include <bits/stdc++.h>
#include <math.h>
using namespace std;

using ll = int64_t;

int found(ll (&arr)[], ll added, ll val) {
    int status = 0;
    for (ll i = 0; i < added; i++) {
        if (arr[i] == val) {
            status = 1;
            break;
        }
    }
    return status;
}

int main() {
    ll N;
    cin >> N;
    // cout << N << "\n";

    ll occured[N];
    ll added = 0;

    for (ll i = 2; i < N + 1; i++) {
        for (ll j = 2; j < N + 1; j++) {
            ll cal = pow(i,j);
            // cout << cal << "\n";
            if (cal > N) {
                break;
            }
            if (found(occured, added, cal) == 0) {
                // cout << i << "^" << j << "\n";
                occured[added] = cal;
                added++;
            }
        }
    }

    cout << N - added << "\n";

    return 0;
}
