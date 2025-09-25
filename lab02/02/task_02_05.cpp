#include <iostream>
using namespace std;

int main() {
    float a, b, c;
    cout << "Input a: ";
    cin >> a;
    cout << "Input b: ";
    cin >> b;
    cout << "Input c: ";
    cin >> c;

    // 0 - попадает в [2,7.5], 2 - попадает в [-2,-0.5], -1 - иначе
    int aState = (a >= 2.0 && a <= 7.5) ? 0 : ((a >= -2.0 && a <= -0.5) ? 2 : -1);
    int bState = (b >= 2.0 && b <= 7.5) ? 0 : ((b >= -2.0 && b <= -0.5) ? 2 : -1);
    int cState = (c >= 2.0 && c <= 7.5) ? 0 : ((c >= -2.0 && c <= -0.5) ? 2 : -1);

    if (aState == 0 && bState == 0 && cState == 0) { a = b = c = 0; }
    else if (aState == 0 && bState == 0 && cState == 2) { a = b = 0; c *= 2; }
    else if (aState == 0 && bState == 0 && cState == -1) { a = b = 0; }
    else if (aState == 0 && bState == 2 && cState == 0) { a = c = 0; b *= 2; }
    else if (aState == 0 && bState == -1 && cState == 0) { a = c = 0; }
    else if (aState == 0 && bState == 2 && cState == -1) { a = 0; b *= 2; }
    else if (aState == 0 && bState == -1 && cState == -1) { a = 0; }
    else if (aState == 2 && bState == 0 && cState == 0) { a *= 2; b = c = 0; }
    else if (aState == -1 && bState == 0 && cState == 0) { b = c = 0; }
    else if (aState == 2 && bState == 2 && cState == 2) { a *= 2; b *= 2; c *= 2; }
    else if (aState == 2 && bState == 2 && cState == -1) { a *= 2; b *= 2; }
    else if (aState == 2 && bState == -1 && cState == 2) { a *= 2; c *= 2; }
    else if (aState == -1 && bState == 2 && cState == 2) { b *= 2; c *= 2; }
    else if (aState == 2 && bState == -1 && cState == -1) { a *= 2; }
    else if (aState == -1 && bState == 2 && cState == -1) { b *= 2; }
    else if (aState == -1 && bState == -1 && cState == 2) { c *= 2; }
    else if (aState == 0 && bState == -1 && cState == 2) { a = 0; c *= 2; }
    else if (aState == 0 && bState == 2 && cState == -1) { a = 0; b *= 2; }
    else if (aState == 2 && bState == 0 && cState == -1) { a *= 2; b = 0; }
    else if (aState == -1 && bState == 0 && cState == -1) { b = 0; }
    else if (aState == 2 && bState == -1 && cState == -1) { a *= 2; }
    else if (aState == -1 && bState == 2 && cState == -1) { b *= 2; }
    else if (aState == -1 && bState == -1 && cState == 0) { c = 0; }
    else if (aState == -1 && bState == -1 && cState == 2) { c *= 2; }

    cout << "Output a: " << a << endl;
    cout << "Output b: " << b << endl;
    cout << "Output c: " << c << endl;

    return 0;
}
