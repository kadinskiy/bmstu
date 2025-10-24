#include <iostream>

using namespace std;

int main() {
    double a, y;
    cout << "Введите действительное число a:" << endl;
    cin >> a;

    if (a <= -1) {
        y = 1;
    }
    else if (a > -1 && a <= 1) {
        y = -a;
    }
    else {
        y = a * a - 2;
    }

    cout << "y=" << y << endl;
    return 0;
}