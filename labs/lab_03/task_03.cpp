#include <iostream>

using namespace std;

int main() {
    double result = 0.0;

    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 50; ++j) {
            result += (j - i + 1.0) / (i + j);
        }
    }
    cout << "Ответ: " << result << endl;
}