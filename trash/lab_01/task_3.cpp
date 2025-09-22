#include <iostream>
#include <cmath>
using namespace std;
// Проверена тестами
int main() {
    int m, b;

    cin >> m >> b;


    double firstTerm = (double) (m * m) / (b * b);
    double secondTerm = sqrt(abs((double) m / b));
    double result = firstTerm - secondTerm;

    int integerPart = (int) result;
    int absValue = abs(integerPart);

    int digit1 = absValue % 10;
    int digit2 = (absValue / 10) % 10;
    int digit3 = (absValue / 100) % 10;
    int digit4 = (absValue / 1000) % 10;
    int digit5 = (absValue / 10000) % 10;
    int digit6 = (absValue / 100000) % 10;

    int digitSum = digit1 + digit2 + digit3 + digit4 + digit5 + digit6;

    cout << digitSum << endl;

    return 0;
}
