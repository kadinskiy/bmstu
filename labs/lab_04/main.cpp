#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n{},m{};
    int res1{}, res2{};
    cin >> n >> m;
    for (int i = n + 1; i < m; i++) {
        int test1{}, test2{}, test3{0}, test4{1};
        int nch{}, diff{};
        int test5{0}, test6{0};
        bool ch{false}, uniq{true};
        int tt[10] = {0};
        while (test1 != i) {
            test4 = 10*test4;
            test3++;
            test1 = i % test4;
        }
        cout << i << char(32) << test3 << endl;
        for (int j = 1; j <= test3; j++) {
            if (ch == false) {
                if ((i % 10*j / (int)pow(10, j-1)) % 2 != 0) {
                    test5++;
                }
                else {
                    cout << (i % 10*j / (int)pow(10, j-1)) << endl;
                    ch = true;
                }
            }
            if (uniq == true) {
                if ((tt[i % 10*j / (int)pow(10, j-1)]) > 0) {
                    uniq = false;
                } else {
                    tt[i % 10*j / 10*(j-1)]++;
                }
            }

        }
        if (uniq == true) {
            res1++;
        }
        if (ch == false) {
            res2++;
        }
    }
    cout << res1 << res2 << endl;
}