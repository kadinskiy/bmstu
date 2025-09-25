#include <iostream>

int main() {
    double A, B, C;

    std::cout << "Введите A, B, C: ";
    std::cin >> A >> B >> C;

    A = (A >= 2.0 && A <= 7.5) ? 0.0 : (A >= -2.0 && A <= -0.5) ? A * 2 : A;
    B = (B >= 2.0 && B <= 7.5) ? 0.0 : (B >= -2.0 && B <= -0.5) ? B * 2 : B;
    C = (C >= 2.0 && C <= 7.5) ? 0.0 : (C >= -2.0 && C <= -0.5) ? C * 2 : C;

    std::cout << "Обработанные значения:\n";
    std::cout << "A = " << A << "\n";
    std::cout << "B = " << B << "\n";
    std::cout << "C = " << C << "\n";

    return 0;
}