#include <iostream>

using namespace std;

void bubble_sort(int* arr, int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int mod(int num) {
    if (num < 0) {
        return num * -1;
    }
    return num;
}

int find_in_arr(int* arr, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int c;
        cin >> c;
        // cout << n << " " << c << "\n";
        int a[n];
        int b[n];

        int min_a = 501;
        int min_b = 501;

        int cost_1 = c;
        int cost_2 = 0;
        int cost_2_possible = 1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < min_a) {
                min_a = a[i];
            }
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (b[i] < min_b) {
                min_b = b[i];
            }
            if (cost_2_possible == 0) {continue;}
            if (b[i] > a[i]) {
                cost_2_possible = 0;
                continue;
            }
            cost_2 += mod(b[i] - a[i]);
        }

        if (min_b > min_a) {
            cout << "-1\n";
            continue;
        }

        // cost 1
        int cost_1_possible = 1;
        int added[n];
        bubble_sort(&a[0], n);
        bubble_sort(&b[0], n);

        for (int i = 0; i < n; i++) {
            if (b[i] > a[i]) {
                // cout << b[i] << " " << a[i] << "\n";
                cout << "-1\n";
                cost_1_possible = 0;
                cost_2_possible = 0;
                break;
            }
            cost_1 += a[i] - b[i];
        }

        if (cost_2 < cost_1 && cost_2_possible == 1) {
            cout << cost_2 << "\n";
        } else if (cost_1_possible == 1) {
            cout << cost_1 << "\n";
        }
        
    }

    return 0;
}
