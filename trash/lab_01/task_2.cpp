#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y;
    bool f;

    cout << "Введите x, y" << endl;
    cin >> x >> y;

    f = ((pow(x, 2) + pow(y, 2) <= 4)
         and x <= 0)
        or (x >= 0 and x <= 2
            and -2 <= y and y <= 2);

    cout << boolalpha << f << endl;
}
