#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int matrix[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        bool done = false;

        do {
            bool greater = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int val = matrix[i][j];
                    // cout << i << " " << j << " " << val << "\n";
                    int cells[4][2] = {
                        {i-1,j},
                        {i,j-1}, {i,j+1},
                        {i+1,j},
                    };

                    int largest_neighbor = 0;

                    for (int k = 0; k < 4; k++) {
                        int x = cells[k][0];
                        int y = cells[k][1];
                        // cout << x << " " << y << "\n";
                        if (x >= 0 && y >= 0 && x < n && y < m) {
                            int neighbor = matrix[x][y];
                            // cout << neighbor << "\n";
                            if (neighbor >= val) {
                                greater = false;
                                // cout << "false\n";
                                break;
                            } else {
                                if (neighbor > largest_neighbor) {
                                    largest_neighbor = neighbor;
                                }
                                greater = true;
                            }
                        }
                        // cout << "\n";
                    }

                    // cout << greater << "\n";

                    if (greater) {
                        matrix[i][j] -= matrix[i][j] - largest_neighbor;
                        break;
                    }

                    // cout << "\n";
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            // cout << matrix[i][j] << " ";
                        }
                        // cout << "\n";
                    }
                    // cout << "\n-----------\n\n";

                    if (greater == false && i == n - 1 && j == m - 1) {
                        done = true;
                        break;
                    }
                }
                if (greater) {break;}
                if (done) {break;}
            }
        } while (done == false);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
        // cout << "\n";

    }

    return 0;
}
