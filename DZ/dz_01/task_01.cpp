#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    const int m = 6, n = 7;
    double matrix_A[m][n]{}, matrix_B[m][n]{}, matrix_C[m][m]{}, matrix_D[m][m]{};

    // for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         double principle = i*i + j/cos(i);
    //         matrix_A[i][j] = principle;
    //     }
    // }
    // cout << "Матрица A:" << endl;
    // for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << setw(15) << matrix_A[i][j];
    //     }
    //     cout << endl;
    // }
    //
    // double min_element{100}; int num_col{};
    //
    // for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         if (matrix_A[i][j] < min_element) {
    //             min_element = matrix_A[i][j];
    //             num_col = j;
    //         }
    //     }
    // }
    //
    // for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         if (j != num_col) {
    //             matrix_B[i][j] = matrix_A[i][j];
    //         }
    //     }
    // }

    // cout << "Матрица B:" << endl;
    //
    // for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << setw(15) << matrix_B[i][j];
    //     }
    //     cout << endl;
    // }

    for (int j = 0; j < m; ++j) {
        matrix_C[0][j] = j + 1;
        matrix_C[m - 1][j] = m - j;
    }

    for (int i = 0; i < m; ++i) {
        matrix_C[i][0] = i + 1;
        matrix_C[i][m - 1] = m - i;
    }

    cout << "Матрица C:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(3) << matrix_C[i][j];
        }
        cout << endl;
    }
    //
    // for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         for (int k = 0; k < m; ++k) {
    //             matrix_D[i][j] += matrix_B[i][k] * matrix_C[k][j];
    //         }
    //     }
    // }
    //
    // for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << setw(20) << matrix_D[i][j];
    //     }
    //     cout << endl;
    // }
    //
    // const int N = 6, B = N/3; // 2
    // double E[N][N];
    // for (int i = 0; i < N; ++i)
    //     for (int j = 0; j < N; ++j) {
    //         int br = i / B, bc = j / B;
    //         int ir = i % B, ic = j % B;
    //         int nbr = (bc == 0 || bc == 2) ? (2 - br) : br;
    //         E[nbr*B + ir][bc*B + ic] = matrix_D[i][j];
    //     }
    //
    // double min_col1 = E[0][0];
    // double min_col6 = E[0][5];                 // индексация с нуля: 6-й столбец ? j=5
    // for (int i = 1; i < 6; ++i) {
    //     if (E[i][0] < min_col1) min_col1 = E[i][0];
    //     if (E[i][5] < min_col6) min_col6 = E[i][5];
    // }
    // cout << "min(1-й столбец) = " << min_col1 << "\n";
    // cout << "min(6-й столбец) = " << min_col6 << "\n";

    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < N; ++j) {
    //         cout << setw(20) << E[i][j];
    //     }
    //     cout << endl;
    // }

}