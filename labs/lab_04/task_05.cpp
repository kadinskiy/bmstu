#include <iostream>

using namespace std;

int main() {
    int n{}, m{}, uniqs{}, nchs{};
    cout << "������ �᫠ n, m ᮮ⢥��⢥���:" << endl;
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
    cout << "������⢮ �ᥫ � ����묨 ��ࠬ�:" << endl;
    cout << nchs << endl;
    cout << "������⢮ �ᥫ � ࠧ���묨 ��ࠬ�:" << endl;
    cout << uniqs << endl;
}
