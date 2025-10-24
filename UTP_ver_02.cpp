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
            if (value >= min_value && value <= max_value) {
                valid = true;
            }
            else {
                cout << "Ошибка: Число должно быть от " << min_value
                    << " до " << max_value << endl;
            }
        }
        else {
            cout << "Ошибка: Введите корректное число!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!valid);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

string getValidString(const string& prompt, int min_length = 1, int max_length = 100) {
    string value;
    bool valid = false;

    do {
        cout << prompt;
        getline(cin, value);

        // Проверка на пустую строку
        if (value.empty()) {
            cout << "Ошибка: Строка не может быть пустой!" << endl;
        }
        // Проверка минимальной длины
        else if (value.length() < min_length) {
            cout << "Ошибка: Минимальная длина " << min_length << " символов!" << endl;
        }
        // Проверка максимальной длины
        else if (value.length() > max_length) {
            cout << "Ошибка: Максимальная длина " << max_length << " символов!" << endl;
        }
        else {
            valid = true;
        }
    } while (!valid);

    return value;
}

// Функция ввода данных студента с подтверждением
void inputStudents(vector<Student>& students) {
    char continue_input = 'y';

    do {
        Student st;
        bool confirmed = false;

        do {
            clearScreen();
            cout << "========================================" << endl;
            cout << "       ВВОД ДАННЫХ О СТУДЕНТЕ          " << endl;
            cout << "   Всего студентов в базе: " << students.size() << endl;
            cout << "========================================" << endl;
            cout << endl;

            st.surname = getValidString("Фамилия: ", 2, 50);
            st.name = getValidString("Имя: ", 2, 50);
            st.patronymic = getValidString("Отчество: ", 2, 50);

            st.course = getValidInt("Курс (1-6): ", 1, 6);

            st.admission_year = getValidInt("Год поступления (2015-2025): ", 2015, 2025);

            cout << endl << "Введите оценки (2-5):" << endl;
            st.grades[0] = getValidInt("  Математика: ", 2, 5);
            st.grades[1] = getValidInt("  Физика: ", 2, 5);
            st.grades[2] = getValidInt("  Информатика: ", 2, 5);
            st.grades[3] = getValidInt("  Английский язык: ", 2, 5);

            cout << endl;
            cout << "========================================" << endl;
            cout << "         ПРОВЕРЬТЕ ДАННЫЕ              " << endl;
            cout << "========================================" << endl;
            cout << "ФИО: " << st.surname << " " << st.name << " " << st.patronymic << endl;
            cout << "Курс: " << st.course << endl;
            cout << "Год поступления: " << st.admission_year << endl;
            cout << "Оценки: ";
            for (int i = 0; i < 4; i++) {
                cout << st.grades[i];
                if (i < 3) cout << ", ";
            }
            cout << endl;
            cout << "========================================" << endl;

            char choice;
            cout << endl << "Сохранить эти данные? (y/n): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            choice = tolower(choice);

            if (choice == 'y') {
                students.push_back(st);
                confirmed = true;
                cout << endl << "Данные сохранены!" << endl;
            }
            else {
                cout << endl << "Повторите ввод данных." << endl;
                cout << "Нажмите Enter...";
                cin.get();
            }

        } while (!confirmed);

        cout << "Всего студентов в базе: " << students.size() << endl;

        cout << endl << "Добавить еще одного студента? (y/n): ";
        cin >> continue_input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        continue_input = tolower(continue_input);

    } while (continue_input == 'y');

    clearScreen();
    cout << "========================================" << endl;
    cout << "Ввод данных завершен." << endl;
    cout << "Всего добавлено студентов: " << students.size() << endl;
    cout << "========================================" << endl;
}

void printStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nБаза данных пуста!" << endl;
        cout << "Добавьте студентов через пункт меню [1]" << endl;
        return;
    }

    cout << "===========================================================================" << endl;
    cout << left << setw(15) << "Фамилия"
        << setw(12) << "Имя"
        << setw(15) << "Отчество"
        << setw(6) << "Курс"
        << setw(8) << "Год"
        << "Оценки (М/Ф/И/А)" << endl;
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
    cout << "Всего студентов: " << students.size() << endl;
}

void calculateAverageByYear(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nБаза данных пуста!" << endl;
        cout << "Добавьте студентов через пункт меню [1]" << endl;
        return;
    }

    int year = getValidInt("\nВведите год поступления: ", 2015, 2025);

    double totalSum = 0;
    int count = 0;

    cout << endl;
    cout << "========================================" << endl;
    cout << "Студенты " << year << " года поступления:" << endl;
    cout << "========================================" << endl;

    for (const auto& st : students) {
        if (st.admission_year == year) {
            double studentAvg = 0;
            for (int i = 0; i < 4; i++) {
                studentAvg += st.grades[i];
            }
            studentAvg /= 4;

            cout << st.surname << " " << st.name << " - средний балл: "
                << fixed << setprecision(2) << studentAvg << endl;

            totalSum += studentAvg;
            count++;
        }
    }

    cout << "========================================" << endl;

    if (count == 0) {
        cout << "Студентов с годом поступления " << year << " не найдено." << endl;
    }
    else {
        double avgForYear = totalSum / count;
        cout << "Средний балл всех студентов " << year << " года: "
            << fixed << setprecision(2) << avgForYear << endl;
        cout << "Всего студентов: " << count << endl;
    }
}

void print_menu(vector<Student>& students) {
    int choice;
    bool exit = false;

    do {
        cout << "========================================" << endl;
        cout << "     МЕНЮ УПРАВЛЕНИЯ СТУДЕНТАМИ        " << endl;
        cout << "========================================" << endl;

        int cmd_width = 5;

        cout << left << setw(cmd_width) << "[1]" << "Ввод информации о студентах с клавиатуры" << endl;
        cout << left << setw(cmd_width) << "[2]" << "Вывод данных в виде таблицы" << endl;
        cout << left << setw(cmd_width) << "[3]" << "Расчёт среднего балла по году поступления" << endl;
        cout << left << setw(cmd_width) << "[0]" << "Завершение работы программы" << endl;
        cout << "========================================" << endl;

        choice = getValidInt("Введите номер команды: ", 0, 3);

        cout << endl;

        switch (choice) {
        case 1:
            clearScreen();
            cout << "=== ВВОД ДАННЫХ ===" << endl << endl;
            inputStudents(students);
            break;
        case 2:
            clearScreen();
            cout << "=== СПИСОК СТУДЕНТОВ ===" << endl << endl;
            printStudents(students);
            break;
        case 3:
            clearScreen();
            cout << "=== РАСЧЁТ СРЕДНЕГО БАЛЛА ===" << endl;
            calculateAverageByYear(students);
            break;
        case 0:
            clearScreen();
            cout << "========================================" << endl;
            cout << "Завершение работы программы..." << endl;
            cout << "========================================" << endl;
            exit = true;
            break;
        }

        if (!exit) {
            cout << endl << "Нажмите Enter для возврата в меню...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            clearScreen();
        }

    } while (!exit);
}

bool login_menu(const vector<User>& users) {
    string login_input, password_input;

    login_input = getValidString("Логин: ", 3, 50);

    password_input = getValidString("Пароль: ", 1, 50);

    for (const auto& user : users) {
        if (user.login == login_input && user.password == password_input) {
            cout << "\nУспешный вход под именем: " << user.login << endl;
            cout << "Ваша роль: " << (user.is_admin ? "Администратор" : "Пользователь") << endl;
            cout << endl;
            cout << "========================================" << endl;
            cout << endl;
            return true;
        }
    }

    cout << "\nНеверный логин или пароль!" << endl;
    cout << "Попробуйте снова." << endl;
    cout << endl;
    return false;
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "========================================" << endl;
    cout << "        СИСТЕМА УПРАВЛЕНИЯ ГРУППАМИ     " << endl;
    cout << "========================================" << endl;
    cout << endl;

    vector<User> users = {
        {"admin", "1234", true},
        {"user1", "pass1"},
        {"user2", "pass2"}
    };

    bool success = false;

    while (!success) {
        success = login_menu(users);
    }

    cout << "Нажмите Enter для продолжения..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    clearScreen();

    vector<Student> students = {
            {"Иванов",    "Алексей",  "Сергеевич", 1, 2025, {5, 4, 5, 4}},
            {"Петров",    "Дмитрий",  "Иванович",  1, 2025, {4, 4, 4, 5}},
            {"Сидорова",  "Анна",     "Павловна",  1, 2025, {5, 5, 4, 5}},
            {"Кузнецов",  "Егор",     "Викторович",1, 2025, {3, 4, 4, 3}},
            {"Смирнова",  "Мария",    "Алексеевна",1, 2025, {5, 5, 5, 4}},
            {"Васильев",  "Илья",     "Олегович",  1, 2025, {4, 3, 4, 4}},
            {"Морозова",  "Елена",    "Игоревна",  1, 2025, {5, 4, 5, 5}},
            {"Волков",    "Никита",   "Денисович", 1, 2025, {3, 4, 3, 4}},
            {"Соколова",  "Ольга",    "Сергеевна", 1, 2025, {4, 5, 4, 5}},
            {"Зайцев",    "Максим",   "Андреевич", 1, 2025, {5, 5, 5, 5}},
            {"Павлова",   "Дарья",    "Михайловна",1, 2025, {4, 4, 5, 4}},
            {"Сергеев",   "Арсений",  "Петрович",  1, 2025, {2, 3, 4, 3}},
            {"Фёдорова",  "Полина",   "Евгеньевна",1, 2025, {5, 4, 5, 4}},
            {"Алексеева", "Софья",    "Романовна", 1, 2025, {4, 5, 4, 5}},
            {"Михайлов",  "Тимофей",  "Артёмович", 1, 2025, {3, 3, 4, 4}},
            {"Николаева", "Ксения",   "Владимировна",1,2025,{5, 5, 4, 5}},
            {"Егорова",   "Вероника", "Алексеевна",1, 2025, {4, 4, 4, 4}},
            {"Ковалёв",   "Матвей",   "Ильич",     1, 2025, {5, 4, 3, 4}},
            {"Романов",   "Глеб",     "Станиславович",1,2025,{4, 5, 5, 4}},
            {"Орлова",    "Виктория", "Константиновна",1,2025,{5, 5, 4, 5}}
    };

    print_menu(students);

    return 0;
}
