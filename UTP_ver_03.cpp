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

        if (value.empty()) {
            cout << "Ошибка: Строка не может быть пустой!" << endl;
        }
        else if ((int)value.length() < min_length) {
            cout << "Ошибка: Минимальная длина " << min_length << " символов!" << endl;
        }
        else if ((int)value.length() > max_length) {
            cout << "Ошибка: Максимальная длина " << max_length << " символов!" << endl;
        }
        else {
            valid = true;
        }
    } while (!valid);

    return value;
}

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

void loadFromTextFile(vector<Student>&) {
    clearScreen();
    cout << "=== ЗАГРУЗКА ИЗ ТЕКСТОВОГО ФАЙЛА ===" << endl;
    cout << "Функция ещё не реализована." << endl;
}

void loadFromBinaryFile(vector<Student>&) {
    clearScreen();
    cout << "=== ЗАГРУЗКА ИЗ БИНАРНОГО ФАЙЛА ===" << endl;
    cout << "Функция ещё не реализована." << endl;
}

void saveToTextFile(const vector<Student>&) {
    clearScreen();
    cout << "=== ВЫВОД В ТЕКСТОВЫЙ ФАЙЛ ===" << endl;
    cout << "Функция ещё не реализована." << endl;
}

void saveToBinaryFile(const vector<Student>&) {
    clearScreen();
    cout << "=== ВЫВОД В БИНАРНЫЙ ФАЙЛ ===" << endl;
    cout << "Функция ещё не реализована." << endl;
}

void printTableToScreen(const vector<Student>& students) {
    clearScreen();
    cout << "=== ТАБЛИЧНЫЙ ВЫВОД НА ЭКРАН ===" << endl << endl;
    printStudents(students);
}

void printTableToFile(const vector<Student>&) {
    clearScreen();
    cout << "=== ТАБЛИЧНЫЙ ВЫВОД В ФАЙЛ ===" << endl;
    cout << "Функция ещё не реализована." << endl;
}

void textToBinary() {
    clearScreen();
    cout << "=== ПЕРЕВОД ТЕКСТ -> БИНАРНЫЙ ===" << endl;
    cout << "Функция ещё не реализована." << endl;
}

void databaseToText(const vector<Student>&) {
    clearScreen();
    cout << "=== ВЫГРУЗКА БАЗЫ -> ТЕКСТ ===" << endl;
    cout << "Функция ещё не реализована." << endl;
}

void queryByVariant(vector<Student>& students) {
    clearScreen();
    cout << "=== ЗАПРОС/ОТЧЁТ ПО ВАРИАНТУ ===" << endl;
    calculateAverageByYear(students);
}

void addRecord(vector<Student>& students) {
    clearScreen();
    cout << "=== ДОБАВЛЕНИЕ ЗАПИСИ ===" << endl;
    inputStudents(students);
}

void editRecord(vector<Student>&) {
    clearScreen();
    cout << "=== ИЗМЕНЕНИЕ ЗАПИСИ ===" << endl;
    cout << "Функция ещё не реализована." << endl;
}

void deleteRecord(vector<Student>&) {
    clearScreen();
    cout << "=== УДАЛЕНИЕ ЗАПИСИ ===" << endl;
    cout << "Функция ещё не реализована." << endl;
}

enum class SortField { Surname, Name, Patronymic, Course, Year, Math, Physics, CS, English };
enum class SortDir { Asc, Desc };

void sortStudents(vector<Student>&, SortField, SortDir) {
    clearScreen();
    cout << "=== СОРТИРОВКА ===" << endl;
    cout << "Функция ещё не реализована." << endl;
}

void waitEnter() {
    cout << endl << "Нажмите Enter для возврата...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int menuSelect(const string& title, const vector<string>& items) {
    cout << "========================================" << endl;
    cout << " " << title << endl;
    cout << "========================================" << endl;
    int idx = 1;
    for (const auto& s : items) {
        cout << left << setw(5) << ("[" + to_string(idx) + "]") << s << endl;
        ++idx;
    }
    cout << left << setw(5) << "[0]" << "Назад" << endl;
    cout << "========================================" << endl;
    return getValidInt("Введите номер команды: ", 0, static_cast<int>(items.size()));
}

void menuFiles(vector<Student>& students) {
    bool back = false;
    while (!back) {
        clearScreen();
        int ch = menuSelect("ФАЙЛЫ", {
            "Загрузка ->",
            "Вывод ->"
            });
        switch (ch) {
        case 1: {
            bool back2 = false;
            while (!back2) {
                clearScreen();
                int c2 = menuSelect("ФАЙЛЫ -> ЗАГРУЗКА", {
                    "Из текстового файла",
                    "Из бинарного файла"
                    });
                switch (c2) {
                case 1: loadFromTextFile(students); waitEnter(); break;
                case 2: loadFromBinaryFile(students); waitEnter(); break;
                case 0: back2 = true; break;
                }
            }
        } break;
        case 2: {
            bool back2 = false;
            while (!back2) {
                clearScreen();
                int c2 = menuSelect("ФАЙЛЫ -> ВЫВОД", {
                    "На экран (таблица)",
                    "В текстовый файл",
                    "В бинарный файл"
                    });
                switch (c2) {
                case 1: printTableToScreen(students); waitEnter(); break;
                case 2: saveToTextFile(students);     waitEnter(); break;
                case 3: saveToBinaryFile(students);   waitEnter(); break;
                case 0: back2 = true; break;
                }
            }
        } break;
        case 0: back = true; break;
        }
    }
}

void menuConvert(vector<Student>& students) {
    bool back = false;
    while (!back) {
        clearScreen();
        int ch = menuSelect("КОНВЕРТАЦИЯ", {
            "База данных -> текстовый файл",
            "Текстовый файл -> бинарный файл"
            });
        switch (ch) {
        case 1: databaseToText(students); waitEnter(); break;
        case 2: textToBinary();           waitEnter(); break;
        case 0: back = true; break;
        }
    }
}

void menuReports(vector<Student>& students) {
    bool back = false;
    while (!back) {
        clearScreen();
        int ch = menuSelect("ЗАПРОСЫ / ОТЧЁТЫ", {
            "Печать данных по запросу (вариант)",
            "Средний балл по году поступления"
            });
        switch (ch) {
        case 1: queryByVariant(students);         waitEnter(); break;
        case 2: calculateAverageByYear(students); waitEnter(); break;
        case 0: back = true; break;
        }
    }
}

void menuEdit(vector<Student>& students) {
    bool back = false;
    while (!back) {
        clearScreen();
        int ch = menuSelect("РЕДАКТИРОВАНИЕ", {
            "Добавить запись",
            "Изменить запись",
            "Удалить запись"
            });
        switch (ch) {
        case 1: addRecord(students);    waitEnter(); break;
        case 2: editRecord(students);   waitEnter(); break;
        case 3: deleteRecord(students); waitEnter(); break;
        case 0: back = true; break;
        }
    }
}

void menuSort(vector<Student>& students) {
    auto chooseField = []() -> SortField {
        int ch = menuSelect("СОРТИРОВКА -> ПОЛЕ", {
            "Фамилия",
            "Имя",
            "Отчество",
            "Курс",
            "Год поступления",
            "Оценка: Математика",
            "Оценка: Физика",
            "Оценка: Информатика",
            "Оценка: Англ. язык"
            });
        switch (ch) {
        case 1: return SortField::Surname;
        case 2: return SortField::Name;
        case 3: return SortField::Patronymic;
        case 4: return SortField::Course;
        case 5: return SortField::Year;
        case 6: return SortField::Math;
        case 7: return SortField::Physics;
        case 8: return SortField::CS;
        case 9: return SortField::English;
        default: return SortField::Surname;
        }
        };
    auto chooseDir = []() -> SortDir {
        int ch = menuSelect("СОРТИРОВКА -> НАПРАВЛЕНИЕ", {
            "По возрастанию",
            "По убыванию"
            });
        return (ch == 2) ? SortDir::Desc : SortDir::Asc;
        };

    bool back = false;
    while (!back) {
        clearScreen();
        cout << "========================================" << endl;
        cout << " СОРТИРОВКА" << endl;
        cout << "========================================" << endl;
        cout << "[1] Выбрать поле и направление" << endl;
        cout << "[0] Назад" << endl;
        cout << "========================================" << endl;
        int ch = getValidInt("Введите номер команды: ", 0, 1);
        switch (ch) {
        case 1: {
            SortField f = chooseField();
            SortDir   d = chooseDir();
            sortStudents(students, f, d);
            waitEnter();
        } break;
        case 0: back = true; break;
        }
    }
}

void print_menu(vector<Student>& students) {
    bool exit_app = false;
    while (!exit_app) {
        clearScreen();
        cout << "========================================" << endl;
        cout << "       ГЛАВНОЕ МЕНЮ УПРАВЛЕНИЯ          " << endl;
        cout << "========================================" << endl;
        cout << left << setw(5) << "[1]" << "Данные (экран) ->" << endl;
        cout << left << setw(5) << "[2]" << "Файлы ->" << endl;
        cout << left << setw(5) << "[3]" << "Конвертация ->" << endl;
        cout << left << setw(5) << "[4]" << "Запросы/Отчёты ->" << endl;
        cout << left << setw(5) << "[5]" << "Редактирование ->" << endl;
        cout << left << setw(5) << "[6]" << "Сортировка ->" << endl;
        cout << left << setw(5) << "[0]" << "Выход" << endl;
        cout << "========================================" << endl;

        int choice = getValidInt("Введите номер команды: ", 0, 6);
        switch (choice) {
        case 1: {
            bool back = false;
            while (!back) {
                clearScreen();
                int ch = menuSelect("ДАННЫЕ (ЭКРАН)", {
                    "Ввод с клавиатуры",
                    "Вывод таблицы на экран"
                    });
                switch (ch) {
                case 1: inputStudents(students); break;
                case 2: printTableToScreen(students); waitEnter(); break;
                case 0: back = true; break;
                }
            }
        } break;
        case 2: menuFiles(students);    break;
        case 3: menuConvert(students);  break;
        case 4: menuReports(students);  break;
        case 5: menuEdit(students);     break;
        case 6: menuSort(students);     break;
        case 0:
            clearScreen();
            cout << "========================================" << endl;
            cout << "Завершение работы программы..." << endl;
            cout << "========================================" << endl;
            exit_app = true;
            break;
        }
    }
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

    // vector<Student> students = {
    //     {"Ivanov",    "Alexey",   "Sergeevich",     1, 2025, {5, 4, 5, 4}},
    //     {"Petrov",    "Dmitry",   "Ivanovich",      2, 2024, {4, 4, 4, 5}},
    //     {"Sidorova",  "Anna",     "Pavlovna",       3, 2023, {5, 5, 4, 5}},
    //     {"Kuznetsov", "Egor",     "Viktorovich",    4, 2022, {3, 4, 4, 3}},
    //     {"Smirnova",  "Maria",    "Alekseevna",     1, 2021, {5, 5, 5, 4}},
    //     {"Vasiliev",  "Ilya",     "Olegovich",      2, 2020, {4, 3, 4, 4}},
    //     {"Morozova",  "Elena",    "Igorevna",       3, 2019, {5, 4, 5, 5}},
    //     {"Volkov",    "Nikita",   "Denisovich",     4, 2018, {3, 4, 3, 4}},
    //     {"Sokolova",  "Olga",     "Sergeevna",      1, 2025, {4, 5, 4, 5}},
    //     {"Zaytsev",   "Maxim",    "Andreevich",     2, 2024, {5, 5, 5, 5}},
    //     {"Pavlova",   "Darya",    "Mikhailovna",    3, 2023, {4, 4, 5, 4}},
    //     {"Sergeev",   "Arseny",   "Petrovich",      4, 2022, {2, 3, 4, 3}},
    //     {"Fedorova",  "Polina",   "Evgenievna",     1, 2021, {5, 4, 5, 4}},
    //     {"Alekseeva", "Sofya",    "Romanovna",      2, 2020, {4, 5, 4, 5}},
    //     {"Mikhailov", "Timofey",  "Artemovich",     3, 2019, {3, 3, 4, 4}},
    //     {"Nikolaeva", "Ksenia",   "Vladimirovna",   4, 2018, {5, 5, 4, 5}},
    //     {"Egorova",   "Veronika", "Alekseevna",     1, 2024, {4, 4, 4, 4}},
    //     {"Kovalyov",  "Matvey",   "Ilyich",         2, 2023, {5, 4, 3, 4}},
    //     {"Romanov",   "Gleb",     "Stanislavovich", 3, 2022, {4, 5, 5, 4}},
    //     {"Orlova",    "Viktoria", "Konstantinovna", 4, 2021, {5, 5, 4, 5}}
    // };

    print_menu(students);

    return 0;
}
