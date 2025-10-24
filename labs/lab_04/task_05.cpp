#include <iostream>

using namespace std;

int main() {
    int n{}, m{}, uniqs{}, nchs{};
    cout << "Введите числа n, m соответственно:" << endl;
    cin >> n >> m;
    for (int i = n + 1; i < m; ++i) {
        bool is_uniq = true, is_nch = true;
        int ints[10] = {};
        int temp = i;

        while (temp > 0) {
            int curr = temp % 10;

            if (curr % 2 == 0) {
                is_nch = false;
            }

            ints[curr]++;
            if (ints[curr] > 1) {
                is_uniq = false;
            }

            if (!is_uniq && !is_nch) {
                break;
            }

            temp /= 10;
        }

        uniqs += is_uniq;
        nchs += is_nch;
    }
    cout << "Количество чисел с нечетными цифрами:" << endl;
    cout << nchs << endl;
    cout << "Количество чисел с различными цифрами:" << endl;
    cout << uniqs << endl;
}
