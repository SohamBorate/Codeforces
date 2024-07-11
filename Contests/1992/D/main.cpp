#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string river;
        cin >> river;
        cout << n << " " << m << " " << k << "\n";
        for (char i : river) {
            cout << i;
        }
        cout << "\n";

        if (m > n) {
            cout << "YES" << "\n\n\n";
            continue;
        }

        int pos = -1;
        int jump = 0;
        for (int i = pos + 1; i < m; i++) {
            if (river[i] == 'L') {
                jump++;
            }
            if (i == n - 1) {
                break;
            }
        }

        int swim = 0;
        for (int i = pos + 1; i < k; i++) {
            if (river[i] == 'L' || river[i] == 'C') {
                break;
            } else {
                swim++;
            }
            if (i == n - 1) {
                break;
            }
        }

        cout << jump << "\n";
        cout << swim << "\n";

        cout << "\n\n";
    }

    return 0;
}
