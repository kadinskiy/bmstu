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
//     cout << "������ 楫�� �᫮ n: " << endl;
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
//     cout << "�㬬� �鸞: " << S << endl;
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
//     cout << "������ 楫�� �᫮ n: " << endl;
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
//     cout << "�㬬� �鸞: " << S << endl;
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
//     cout << "������ 楫�� �᫮ n: ";
//     cin >> n;
//     curr = (1.0 / pow(2, n)) + (1.0 / pow(3, n));
//     do {
//         prev = curr;
//         s = s + prev;
//         n = n + 1;
//         curr = (1.0 / pow(2, n)) + (1.0 / pow(3, n));
//     } while (fabs(prev - current) > EPS);
//
//     std::cout << "C㬬� �鸞 � �筮���� EPS = 0.001: " << s;
//     return 0;
// }
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    double eps = 0.001, sum = 0, prev, curr;

    cout << "������ 楫�� �᫮ n: " << endl;
    cin >> n;

    curr = 1.0 / pow(2, n) + 1.0 / pow(3, n);

    do {
        prev = curr;
        sum += prev;
        n++;
        curr = 1.0 / pow(2, n) + 1.0 / pow(3, n);
    } while (prev - curr > eps);

    cout << "�㬬� �鸞: " << sum << endl;
    return 0;
}