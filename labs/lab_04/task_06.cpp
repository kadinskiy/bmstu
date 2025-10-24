#include <iostream>

using namespace std;

int main() {
    bool t = true;
    int arr[40] = {};

    cout << "Введите 40 элементов массива:" << endl;
    for (int i = 0; i < 40; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i < 40; i++) {
        if (arr[i] < arr[i - 1]) {
            t = false;
            break;
        }
    }
    cout << "t = " << t << endl;
}
