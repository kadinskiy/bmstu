#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    const int m = 6, n = 6;
    double matrix_C[m][n]{};

    for (int j = 0; j < n; ++j) {
        matrix_C[0][j] = j + 1;
        matrix_C[n - 1][j] = n - j;
    }

    for (int i = 0; i < m; ++i) {
        matrix_C[i][0] = i + 1;
        matrix_C[i][m - 1] = n - i;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(3) << matrix_C[i][j];
        }
        cout << endl;
    }
}

