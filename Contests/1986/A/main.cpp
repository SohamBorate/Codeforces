#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        int min = 100;
        for (int i = 0; i < 11; i++) {
            int sum = abs(x1 - i) + abs(x2 - i) + abs(x3 - i);
            if (sum < min) {
                min = sum;
            }
        }
        cout << min << "\n";
    }

    return 0;
}
