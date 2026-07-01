#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int found = -1;
    for (int i = a; i < (b + 1); i++) {
        if ((i % c) == 0) {
            found = i;
            break;
        }
    }

    cout << found << "\n";

    return 0;
}
