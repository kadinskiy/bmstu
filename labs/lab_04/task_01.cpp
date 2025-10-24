#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n{};
    cin >> n;
    int matrix[100][100];
    int num = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    while (num <= n*n) {
        // Слева направо по верхней строке
        for (int i = left; i <= right; ++i) {
            matrix[top][i] = num++;
        }
        ++top;

        // Сверху вниз по правому столбцу
        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = num++;
        }
        --right;

        // Справа налево по нижней строке
        for (int i = right; i >= left; --i) {
            matrix[bottom][i] = num++;
        }
        --bottom;

        // Снизу вверх по левому столбцу
        for (int i = bottom; i >= top; --i) {
            matrix[i][left] = num++;
        }
        ++left;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
