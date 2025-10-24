#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Введите число для вычисления факториала:" << endl;
    cin >> n;

    int fact[10000];
    fact[0] = 1;
    int size = 1;

    for (int i = 2; i <= n; ++i) {
        int carry = 0;
        for (int j = 0; j < size; ++j) {
            int prod = fact[j] * i + carry;
            fact[j] = prod % 10;
            carry = prod / 10;
        }
        while (carry) {
            fact[size] = carry % 10;
            carry /= 10;
            size++;
        }
    }

    cout << "Факториал числа " << n << " равен: ";
    for (int i = size - 1; i >= 0; --i)
        cout << fact[i];

    cout << endl;

    return 0;
}
