#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Введите число для разбиения: " << endl;
    cin >> n;

    int result[100];
    int size = 0;
    int remaining = n;
    int current = 1;
    bool done = false;

    while (!done) {
        if (remaining == 0 && result[0] != n) {
            for (int i = 0; i < size; i++) {
                cout << result[i];
                if (i != size - 1) cout << " + ";
            }
            cout << endl;

            if (size == 0) {
                done = true;
            } else {
                remaining += result[size - 1];
                current = result[size - 1] + 1;
                size--;
            }
        } else if (current <= remaining) {
            result[size] = current;
            remaining -= current;
            size++;
        } else {
            if (size == 0) {
                done = true;
            } else {
                remaining += result[size - 1];
                current = result[size - 1] + 1;
                size--;
            }
        }
    }

    return 0;
}
