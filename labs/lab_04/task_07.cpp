#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int m{};

    cout << "������ �᫮ m:" << endl;
    cin >> m;

    int arr[500];

    srand(time(0));

    cout << "���ᨢ ��砩��� �ᥫ:"  << endl;
    for (int i = 0; i < 15; ++i) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;

    bool found{false};

    for (int i = 0; i < m && !found; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if ((arr[i] + arr[j]) == m) {
                cout << "��� �ᥫ: " << arr[i] << " � " << arr[j] << endl;
                found = true;
                break;
            }
        }
    }
    if (found == false) cout << "��� �ᥫ �� �������." << endl;

    return 0;
}
