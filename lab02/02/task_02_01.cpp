#include <iostream>

int main() {
    double A, B, C;

    // Ввод чисел
    std::cout << "Введите три действительных числа A, B, C: ";
    std::cin >> A >> B >> C;

    // Проверка всех комбинаций принадлежности к интервалам
    bool A_in_2_75 = (A >= 2.0 && A <= 7.5);
    bool B_in_2_75 = (B >= 2.0 && B <= 7.5);
    bool C_in_2_75 = (C >= 2.0 && C <= 7.5);

    bool A_in_minus_2_minus_05 = (A >= -2.0 && A <= -0.5);
    bool B_in_minus_2_minus_05 = (B >= -2.0 && B <= -0.5);
    bool C_in_minus_2_minus_05 = (C >= -2.0 && C <= -0.5);

    // Обработка всех возможных комбинаций
    if (A_in_2_75 && B_in_2_75 && C_in_2_75) {
        A = B = C = 0.0;
    }
    else if (A_in_2_75 && B_in_2_75) {
        A = B = 0.0;
        if (C_in_minus_2_minus_05) C *= 2;
    }
    else if (A_in_2_75 && C_in_2_75) {
        A = C = 0.0;
        if (B_in_minus_2_minus_05) B *= 2;
    }
    else if (B_in_2_75 && C_in_2_75) {
        B = C = 0.0;
        if (A_in_minus_2_minus_05) A *= 2;
    }
    else if (A_in_2_75) {
        A = 0.0;
        if (B_in_minus_2_minus_05) B *= 2;
        if (C_in_minus_2_minus_05) C *= 2;
    }
    else if (B_in_2_75) {
        B = 0.0;
        if (A_in_minus_2_minus_05) A *= 2;
        if (C_in_minus_2_minus_05) C *= 2;
    }
    else if (C_in_2_75) {
        C = 0.0;
        if (A_in_minus_2_minus_05) A *= 2;
        if (B_in_minus_2_minus_05) B *= 2;
    }
    else {
        if (A_in_minus_2_minus_05) A *= 2;
        if (B_in_minus_2_minus_05) B *= 2;
        if (C_in_minus_2_minus_05) C *= 2;
    }

    // Вывод результатов
    std::cout << "Результаты после обработки: " << A << ", " << B << ", " << C << std::endl;

    return 0;
}