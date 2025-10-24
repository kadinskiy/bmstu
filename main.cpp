#include <iostream>

using namespace std;

int main() {
    int temp{}, length{};
    cin >> temp;
    while (temp > 0) {
        length++;
        temp /= 10;
    }
    cout << length << endl;

}