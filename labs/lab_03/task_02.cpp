#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int n{};
    double x{},s{0};

    cout << "Введите действительное число x: " << endl;
    cin >> x;
    cout << "Введите целое число n: " << endl;
    cin >> n;

    for(int i=1; i <= n; i++) {
        s += sin(pow(x, i));
    }
    cout << "s = " << s << endl;
}