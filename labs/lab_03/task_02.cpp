#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int n{};
    double x{},s{0};

    cout << "������ ����⢨⥫쭮� �᫮ x: " << endl;
    cin >> x;
    cout << "������ 楫�� �᫮ n: " << endl;
    cin >> n;

    for(int i=1; i <= n; i++) {
        s += sin(pow(x, i));
    }
    cout << "s = " << s << endl;
}