#include "Database.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits> // Для numeric_limits

using namespace std;

// --- Скрытая константа для имени файла ---
const string FILENAME = "passengers.dat";

// --- Скрытые вспомогательные функции ---

/**
 * @brief Выводит данные одного пассажира в консоль.
 */
void printPassenger(const Passenger& p) {
    cout << "| " << setw(30) << left << p.full_name 
         << " | " << setw(15) << right << p.baggage_count 
         << " | " << setw(15) << fixed << setprecision(2) << p.total_weight << " |\n";
}

/**
 * @brief Выводит заголовок таблицы.
 */
void printHeader() {
    cout << "\n-----------------------------------------------------------------------\n";
    cout << "| " << setw(30) << left << "ФИО ПАССАЖИРА" 
         << " | " << setw(15) << right << "МЕСТ БАГАЖА" 
         << " | " << setw(15) << "ОБЩИЙ ВЕС (кг)" << " |\n";
    cout << "-----------------------------------------------------------------------\n";
}

/**
 * @brief Считывает данные пассажира с консоли.
 */
Passenger getPassengerInput() {
    Passenger p;
    
    cout << "ФИО: ";
    // Очистка буфера перед getline (важно после предыдущего cin >> choice/N)
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, p.full_name);
    
    cout << "Количество мест багажа: ";
    // Проверка ввода числа
    while (!(cin >> p.baggage_count)) {
        cerr << "Некорректный ввод. Введите целое число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Общий вес (кг): ";
    while (!(cin >> p.total_weight)) {
        cerr << "Некорректный ввод. Введите число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return p;
}


// --- Реализация функций меню (объявлены в HPP) ---

// а) Создать файл из N записей
void createFile(int N) {
    ofstream file(FILENAME, ios::binary | ios::trunc); // Очищаем файл перед записью
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл для записи.\n";
        return;
    }

    cout << "\n--- Создание файла из " << N << " записей ---\n";
    for (int i = 0; i < N; ++i) {
        cout << "Введите данные для записи #" << i + 1 << ":\n";
        Passenger p = getPassengerInput();

        // Запись структуры в файл
        file.write(reinterpret_cast<const char*>(&p), sizeof(Passenger));
    }
    file.close();
    cout << "\nФайл успешно создан и заполнен " << N << " записями.\n";
}

// б) Просмотреть файл
void viewFile() {
    ifstream file(FILENAME, ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка: Файл не найден или не удалось открыть.\n";
        return;
    }

    Passenger p;
    printHeader();
    
    // Чтение записей по очереди
    // 
    while (file.read(reinterpret_cast<char*>(&p), sizeof(Passenger))) {
        printPassenger(p);
    }
    
    file.close();
    cout << "-----------------------------------------------------------------------\n";
}

// в) Добавить в конец файла новую запись
void appendRecord() {
    ofstream file(FILENAME, ios::binary | ios::app); // Режим добавления (append)
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл для добавления.\n";
        return;
    }

    cout << "\n--- Добавление новой записи ---\n";
    Passenger p = getPassengerInput();

    // Запись структуры в файл
    file.write(reinterpret_cast<const char*>(&p), sizeof(Passenger));
    file.close();
    cout << "\nНовая запись успешно добавлена.\n";
}

// г) Найти и удалить из файла записи о пассажирах, общий вес вещей которых меньше, чем 10 кг
void deleteRecordsByWeight(double min_weight) {
    ifstream input_file(FILENAME, ios::binary);
    if (!input_file.is_open()) {
        cerr << "Ошибка: Файл не найден или не удалось открыть.\n";
        return;
    }

    // Вектор для временного хранения всех записей
    vector<Passenger> records;
    Passenger p;
    int deleted_count = 0;

    // 1. Считываем все записи и фильтруем их
    while (input_file.read(reinterpret_cast<char*>(&p), sizeof(Passenger))) {
        if (p.total_weight >= min_weight) {
            // Оставляем только те, у кого вес >= min_weight
            records.push_back(p);
        } else {
            deleted_count++;
        }
    }
    input_file.close();

    if (deleted_count == 0) {
        cout << "\nЗаписей с общим весом менее " << min_weight << " кг не найдено.\n";
        return;
    }

    // 2. Перезаписываем файл оставшимися записями
    ofstream output_file(FILENAME, ios::binary | ios::trunc); // Режим перезаписи
    if (!output_file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл для перезаписи.\n";
        return;
    }

    for (const auto& record : records) {
        output_file.write(reinterpret_cast<const char*>(&record), sizeof(Passenger));
    }
    
    output_file.close();
    cout << "\nУспешно удалено " << deleted_count << " записей с весом менее " << min_weight << " кг.\n";
}

// д) Изменить вес вещей пассажира по заданной фамилии
void modifyWeightBySurname() {
    // Режим чтения/записи (in|out) позволяет позиционироваться и перезаписывать
    fstream file(FILENAME, ios::binary | ios::in | ios::out); 
    if (!file.is_open()) {
        cerr << "Ошибка: Файл не найден или не удалось открыть.\n";
        return;
    }

    string target_surname;
    cout << "\n--- Изменение веса вещей ---\n";
    cout << "Введите фамилию пассажира для поиска: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, target_surname); 
    
    Passenger p;
    bool found = false;
    streamoff record_size = sizeof(Passenger);

    // Чтение записей по очереди
    while (file.read(reinterpret_cast<char*>(&p), record_size)) {
        // Проверяем, содержит ли ФИО заданную фамилию (ищем подстроку)
        if (p.full_name.find(target_surname) != string::npos) {
            
            cout << "\nНайдена запись:\n";
            printHeader();
            printPassenger(p);
            cout << "-----------------------------------------------------------------------\n";

            double new_weight;
            cout << "Введите новый общий вес (кг) для " << p.full_name << ": ";
            if (!(cin >> new_weight)) {
                cerr << "Некорректный ввод веса. Операция отменена.\n";
                file.close();
                return;
            }

            p.total_weight = new_weight;
            found = true;

            // Возврат указателя записи на начало текущей структуры, чтобы перезаписать ее
            file.seekp(-record_size, ios::cur); 
            
            // Запись измененной структуры обратно в файл
            file.write(reinterpret_cast<const char*>(&p), record_size);
            
            cout << "\nВес успешно изменен.\n";
            break; 
        }
    }

    if (!found) {
        cout << "\nПассажир с фамилией \"" << target_surname << "\" не найден.\n";
    }

    file.close();
}

// --- Реализация функции меню (объявлена в HPP) ---

void displayMenu() {
    cout << "\n=========================================================\n";
    cout << "                 МЕНЮ УПРАВЛЕНИЯ ЗАПИСЯМИ\n";
    cout << "=========================================================\n";
    cout << " 1/а) Создать файл (ввести N записей)\n";
    cout << " 2/б) Просмотреть файл\n";
    cout << " 3/в) Добавить запись в конец файла\n";
    cout << " 4/г) Удалить записи (общий вес < 10 кг)\n";
    cout << " 5/д) Изменить вес вещей по фамилии\n";
    cout << " 0) Выход\n";
    cout << "=========================================================\n";
    cout << "Ваш выбор: ";
}

void runPassengerManager() {
    int choice_num;
    char choice_char;
    
    do {
        displayMenu();
        
        // Попытка считать число (для 0-5)
        if (cin >> choice_num) {
            // Если считано число, используем его
            choice_char = ' '; 
        } else {
            // Если не число, очищаем ошибку и пытаемся считать букву
            cin.clear();
            cin >> choice_char;
            choice_num = -1; // Сброс числового выбора
        }

        switch (choice_num != -1 ? choice_num : (choice_char == 'а' || choice_char == 'a' ? 1 :
                                                 choice_char == 'б' || choice_char == 'b' ? 2 :
                                                 choice_char == 'в' || choice_char == 'v' ? 3 :
                                                 choice_char == 'г' || choice_char == 'g' ? 4 :
                                                 choice_char == 'д' || choice_char == 'd' ? 5 :
                                                 choice_char == '0' ? 0 : -1)) {
            case 1: { 
                int N;
                cout << "Введите количество записей N: ";
                if (cin >> N && N > 0) {
                    createFile(N);
                } else {
                    cerr << "Некорректный ввод N.\n";
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;
            }
            case 2:
                viewFile();
                break;
            case 3:
                appendRecord();
                break;
            case 4:
                deleteRecordsByWeight();
                break;
            case 5:
                modifyWeightBySurname();
                break;
            case 0:
                cout << "\nЗавершение работы программы.\n";
                break;
            default:
                cerr << "Некорректный выбор. Пожалуйста, введите номер (0-5) или букву (а-д).\n";
        }
        // Очистка буфера после обработки ввода
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (choice_num != 0 && choice_char != '0');
}