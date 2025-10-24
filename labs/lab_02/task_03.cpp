#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int m, n;
    double y;

    cout << "Введите целое число M:" << endl;
    cin >> m;
    n = m % 5;

    switch (n) {
        case 1:
            y = n/sqrt(pow(n, 5)) + fabs(pow(n, 8) + 5);
            break;
        case 2:
        case 3:
            y = atan(n + 2);
            break;
        case 4:
            y = sin(n + M_PI/4);
            break;
        case 5:
        case 0:
            y = exp(n);
            break;
    }

    cout << "y=" << y << endl;
}