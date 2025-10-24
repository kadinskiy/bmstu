#include <climits>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <clocale>
#include <limits>

using namespace std;

struct User {
    string login;
    string password;
    bool is_admin = false;
};

struct Student {
    string surname;
    string name;
    string patronymic;
    int course;
    int admission_year;
    int grades[4];
};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int getValidInt(const string& prompt, int min_value = INT_MIN, int max_value = INT_MAX) {
    int value;
    bool valid = false;

    do {
        cout << prompt;

        if (cin >> value) {
            // �஢�ઠ ���������
            if (value >= min_value && value <= max_value) {
                valid = true;
            }
            else {
                cout << "�訡��: ��᫮ ������ ���� �� " << min_value
                    << " �� " << max_value << endl;
            }
        }
        else {
            // ��ࠡ�⪠ ���᫮��� ������
            cout << "�訡��: ������ ���४⭮� �᫮!" << endl;
            cin.clear(); // ���� 䫠�� �訡��
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���⪠ ����
        }
    } while (!valid);

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���⪠ ���⪮� ����
    return value;
}

// �������� ���� �����⮩ ��ப�
string getValidString(const string& prompt, int min_length = 1, int max_length = 100) {
    string value;
    bool valid = false;

    do {
        cout << prompt;
        getline(cin, value);

        // �஢�ઠ �� ������ ��ப�
        if (value.empty()) {
            cout << "�訡��: ��ப� �� ����� ���� ���⮩!" << endl;
        }
        // �஢�ઠ �������쭮� �����
        else if (value.length() < min_length) {
            cout << "�訡��: �������쭠� ����� " << min_length << " ᨬ�����!" << endl;
        }
        // �஢�ઠ ���ᨬ��쭮� �����
        else if (value.length() > max_length) {
            cout << "�訡��: ���ᨬ��쭠� ����� " << max_length << " ᨬ�����!" << endl;
        }
        else {
            valid = true;
        }
    } while (!valid);

    return value;
}

// �㭪�� ����� ������ ��㤥�� � ���⢥ত�����
void inputStudents(vector<Student>& students) {
    char continue_input = 'y';

    do {
        Student st;
        bool confirmed = false;

        do {
            clearScreen();
            cout << "========================================" << endl;
            cout << "       ���� ������ � ��������          " << endl;
            cout << "   �ᥣ� ��㤥�⮢ � ����: " << students.size() << endl;
            cout << "========================================" << endl;
            cout << endl;

            // ���� ���
            st.surname = getValidString("�������: ", 2, 50);
            st.name = getValidString("���: ", 2, 50);
            st.patronymic = getValidString("����⢮: ", 2, 50);

            // ���� ����
            st.course = getValidInt("���� (1-6): ", 1, 6);

            // ���� ���� ����㯫����
            st.admission_year = getValidInt("��� ����㯫���� (2015-2025): ", 2015, 2025);

            // ���� �業��
            cout << endl << "������ �業�� (2-5):" << endl;
            st.grades[0] = getValidInt("  ��⥬�⨪�: ", 2, 5);
            st.grades[1] = getValidInt("  ������: ", 2, 5);
            st.grades[2] = getValidInt("  ���ଠ⨪�: ", 2, 5);
            st.grades[3] = getValidInt("  ������᪨� ��: ", 2, 5);

            // ����� ��������� ������
            cout << endl;
            cout << "========================================" << endl;
            cout << "         ��������� ������              " << endl;
            cout << "========================================" << endl;
            cout << "���: " << st.surname << " " << st.name << " " << st.patronymic << endl;
            cout << "����: " << st.course << endl;
            cout << "��� ����㯫����: " << st.admission_year << endl;
            cout << "�業��: ";
            for (int i = 0; i < 4; i++) {
                cout << st.grades[i];
                if (i < 3) cout << ", ";
            }
            cout << endl;
            cout << "========================================" << endl;

            // ���⢥ত����
            char choice;
            cout << endl << "���࠭��� �� �����? (y/n): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            choice = tolower(choice);

            if (choice == 'y') {
                students.push_back(st);
                confirmed = true;
                cout << endl << "����� ��࠭���!" << endl;
            }
            else {
                cout << endl << "������ ���� ������." << endl;
                cout << "������ Enter...";
                cin.get();
            }

        } while (!confirmed);

        cout << "�ᥣ� ��㤥�⮢ � ����: " << students.size() << endl;

        // ����� �� �த������� �����
        cout << endl << "�������� �� ������ ��㤥��? (y/n): ";
        cin >> continue_input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        continue_input = tolower(continue_input);

    } while (continue_input == 'y');

    clearScreen();
    cout << "========================================" << endl;
    cout << "���� ������ �����襭." << endl;
    cout << "�ᥣ� ��������� ��㤥�⮢: " << students.size() << endl;
    cout << "========================================" << endl;
}

// �㭪�� �뢮�� ������ � ���� ⠡����
void printStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\n���� ������ ����!" << endl;
        cout << "������� ��㤥�⮢ �१ �㭪� ���� [1]" << endl;
        return;
    }

    cout << "===========================================================================" << endl;
    cout << left << setw(15) << "�������"
        << setw(12) << "���"
        << setw(15) << "����⢮"
        << setw(6) << "����"
        << setw(8) << "���"
        << "�業�� (�/�/�/�)" << endl;
    cout << "===========================================================================" << endl;

    for (const auto& st : students) {
        cout << left << setw(15) << st.surname
            << setw(12) << st.name
            << setw(15) << st.patronymic
            << setw(6) << st.course
            << setw(8) << st.admission_year;

        for (int i = 0; i < 4; i++) {
            cout << st.grades[i];
            if (i < 3) cout << "/";
        }
        cout << endl;
    }

    cout << "===========================================================================" << endl;
    cout << "�ᥣ� ��㤥�⮢: " << students.size() << endl;
}

// �㭪�� ���� �।���� ����� �� ���� ����㯫����
void calculateAverageByYear(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\n���� ������ ����!" << endl;
        cout << "������� ��㤥�⮢ �१ �㭪� ���� [1]" << endl;
        return;
    }

    int year = getValidInt("\n������ ��� ����㯫����: ", 2015, 2025);

    double totalSum = 0;
    int count = 0;

    cout << endl;
    cout << "========================================" << endl;
    cout << "��㤥��� " << year << " ���� ����㯫����:" << endl;
    cout << "========================================" << endl;

    for (const auto& st : students) {
        if (st.admission_year == year) {
            double studentAvg = 0;
            for (int i = 0; i < 4; i++) {
                studentAvg += st.grades[i];
            }
            studentAvg /= 4;

            cout << st.surname << " " << st.name << " - �।��� ����: "
                << fixed << setprecision(2) << studentAvg << endl;

            totalSum += studentAvg;
            count++;
        }
    }

    cout << "========================================" << endl;

    if (count == 0) {
        cout << "��㤥�⮢ � ����� ����㯫���� " << year << " �� �������." << endl;
    }
    else {
        double avgForYear = totalSum / count;
        cout << "�।��� ���� ��� ��㤥�⮢ " << year << " ����: "
            << fixed << setprecision(2) << avgForYear << endl;
        cout << "�ᥣ� ��㤥�⮢: " << count << endl;
    }
}

// ���� � ���⮩ �� ����୮�� �����
void print_menu(vector<Student>& students) {
    int choice;
    bool exit = false;

    do {
        cout << "========================================" << endl;
        cout << "     ���� ���������� ����������        " << endl;
        cout << "========================================" << endl;

        int cmd_width = 5;

        cout << left << setw(cmd_width) << "[1]" << "���� ���ଠ樨 � ��㤥��� � ����������" << endl;
        cout << left << setw(cmd_width) << "[2]" << "�뢮� ������ � ���� ⠡����" << endl;
        cout << left << setw(cmd_width) << "[3]" << "������ �।���� ����� �� ���� ����㯫����" << endl;
        cout << left << setw(cmd_width) << "[0]" << "�����襭�� ࠡ��� �ணࠬ��" << endl;
        cout << "========================================" << endl;

        // �������� ���� � ���������� �� 0 �� 3
        choice = getValidInt("������ ����� �������: ", 0, 3);

        cout << endl;

        switch (choice) {
        case 1:
            clearScreen();
            inputStudents(students);
            break;
        case 2:
            clearScreen();
            printStudents(students);
            break;
        case 3:
            clearScreen();
            calculateAverageByYear(students);
            break;
        case 0:
            clearScreen();
            cout << "========================================" << endl;
            cout << "�����襭�� ࠡ��� �ணࠬ��..." << endl;
            cout << "========================================" << endl;
            exit = true;
            break;
        }

        if (!exit) {
            cout << endl << "������ Enter ��� ������ � ����...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            clearScreen();
        }

    } while (!exit);
}

// ����� � ���⮩ �� ������ �����
bool login_menu(const vector<User>& users) {
    string login_input, password_input;

    // ���� ������ � �஢�મ�
    login_input = getValidString("�����: ", 3, 50);

    // ���� ��஫� � �஢�મ�
    password_input = getValidString("��஫�: ", 1, 50);

    // �஢�ઠ ����� ������
    for (const auto& user : users) {
        if (user.login == login_input && user.password == password_input) {
            cout << "\n�ᯥ�� �室 ��� ������: " << user.login << endl;
            cout << "��� ஫�: " << (user.is_admin ? "�����������" : "���짮��⥫�") << endl;
            cout << endl;
            cout << "========================================" << endl;
            cout << endl;
            return true;
        }
    }

    cout << "\n������ ����� ��� ��஫�!" << endl;
    cout << "���஡�� ᭮��." << endl;
    cout << endl;
    return false;
}

int main() {
    // setlocale(LC_ALL, "Russian");

    cout << "========================================" << endl;
    cout << "        ������� ���������� ��������     " << endl;
    cout << "========================================" << endl;
    cout << endl;

    vector<User> users = {
        {"admin", "1234", true},
        {"user1", "pass1"},
        {"user2", "pass2"}
    };

    bool success = false;

    // ���� ���ਧ�樨
    while (!success) {
        success = login_menu(users);
    }

    cout << "������ Enter ��� �த�������..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    clearScreen();

    // �������� ����� ��� �࠭���� ��㤥�⮢
    vector<Student> students;

    // ����� ����
    print_menu(students);

    return 0;
}
