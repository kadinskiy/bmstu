// #include <iostream>
// #include <cmath>
//
// using namespace std;
//
// int main() {
//     double e = 0.001;
//     double S = 0.0;
//     int n{};
//
//     cout << "Введите целое число n: " << endl;
//     cin >> n;
//
//     double an = 1.0 / pow(2, n) + 1.0 / pow(3, n);
//
//     while (an >= e) {
//         S += an;
//         n++;
//         an = 1.0 / pow(2, n) + 1.0 / pow(3, n);
//     }
//
//     cout << "Сумма ряда: " << S << endl;
//     return 0;
// }
// #include <iostream>
// #include <cmath>
//
// using namespace std;
//
// int main() {
//     const double e = 0.001;
//     double S = 0.0;
//     int n{};
//     cout << "Введите целое число n: " << endl;
//     cin >> n;
//
//     double prev = 1.0 / pow(2, n) + 1.0 / pow(3, n);
//     S += prev;
//     n++;
//     double curr = 1.0 / pow(2, n) + 1.0 / pow(3, n);
//
//     while (prev - curr > e) {
//         S += curr;
//         prev = curr;
//         n++;
//         curr = 1.0 / pow(2, n) + 1.0 / pow(3, n);
//     }
//
//     cout << "Сумма ряда: " << S << endl;
//     return 0;
// }
// #include <iostream>
// #include <cmath>
//
// using namespace std;
//
// int main()
// {
//     int n{};
//     double curr{}, prev{}, s{}, e = 0.001;
//
//     cout << "Введите целое число n: ";
//     cin >> n;
//     curr = (1.0 / pow(2, n)) + (1.0 / pow(3, n));
//     do {
//         prev = curr;
//         s = s + prev;
//         n = n + 1;
//         curr = (1.0 / pow(2, n)) + (1.0 / pow(3, n));
//     } while (fabs(prev - current) > EPS);
//
//     std::cout << "Cумма ряда с точностью EPS = 0.001: " << s;
//     return 0;
// }
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    double eps = 0.001, sum = 0, prev, curr;

    cout << "Введите целое число n: " << endl;
    cin >> n;

    curr = 1.0 / pow(2, n) + 1.0 / pow(3, n);

    do {
        prev = curr;
        sum += prev;
        n++;
        curr = 1.0 / pow(2, n) + 1.0 / pow(3, n);
    } while (prev - curr > eps);

    cout << "Сумма ряда: " << sum << endl;
    return 0;
}