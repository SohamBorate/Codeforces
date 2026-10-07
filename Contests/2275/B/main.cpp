#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        char s[n];
        cin >> s;
        int m[n];
        int mi = 0;
        int p[n];
        int pi = 0;
        int np[n];
        int npi = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                m[mi] = i + 1;
                mi++;
            } else if (s[i] == '2') {
                if (mi == 0) {
                    p[pi] = i + 1;
                    pi++;
                } else {
                    np[npi] = i + 1;
                    npi++;
                    p[pi] = m[mi];
                    mi--;
                }
            } else {
                p[pi] = i + 1;
                pi++;
            }
        }
        int mii = 0;
        int npii = 0;
        cout << mi + npi << endl;
        while (mii < mi || npii < npi) {
            if (mii < mi && npii < npi) {
                if (m[mii] < np[npii]) {
                    cout << m[mii] << " ";
                    mii++;
                } else {
                    cout << np[npii] << " ";
                    npii++;
                }
            } else if (mii < mi) {
                cout << m[mii] << " ";
                mii++;
            } else {
                cout << np[npii] << " ";
                npii++;
            }
        }
        cout << endl;
    }

    return 0;
}
