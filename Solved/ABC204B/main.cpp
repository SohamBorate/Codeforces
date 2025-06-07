#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    int total = 0;
    while (t--) {
        int n;
        cin >> n;
        if (n > 10) {
            total += n - 10;
        }
    }
    cout << total;
    return 0;
}
