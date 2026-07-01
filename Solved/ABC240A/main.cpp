#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a;
    cin >> b;

    if (((b - 1) == a) || ((b + 1) == a)) {
        cout << "Yes\n";
    } else if ((a == 1 && b == 10) || (a == 10 && b == 1)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
