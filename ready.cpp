#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double A, B, C;

    cout << "������ �� �᫠ A, B, C: ";
    cin >> A >> B >> C;
    
    // ��ࠡ�⪠ �᫠ A
    if (A >= 2.0 && A <= 7.5) {
        A = 0.0;
    } else if (A >= -2.0 && A <= -0.5) {
        A = A * 2;
    }
    
    // ��ࠡ�⪠ �᫠ B
    if (B >= 2.0 && B <= 7.5) {
        B = 0.0;
    } else if (B >= -2.0 && B <= -0.5) {
        B = B * 2;
    }
    
    // ��ࠡ�⪠ �᫠ C
    if (C >= 2.0 && C <= 7.5) {
        C = 0.0;
    } else if (C >= -2.0 && C <= -0.5) {
        C = C * 2;
    }

    cout << A << " " << B << " " << C << endl;
}