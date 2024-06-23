#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int ind[m];
        for (int i = 0; i < m; i++) {
            cin >> ind[i];
        }
        string c;
        cin >> c;

        for (int i = 0; i < m; i++) {
            s[ind[i] - 1] = c[i];
        }

        cout << s << "\n";
    }

    return 0;
}
