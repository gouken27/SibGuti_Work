#include "Database.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * @brief Функция для создания исходного файла с тестовыми данными.
 */
bool createSourceFile(const std::string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл для записи: " << filename << endl;
        return false;
    }

    file << "Красный это цвет\n";
    file << "Зеленый трава\n";
    file << "А синий небо\n";
    file << "Разные цвета красиво\n";
    
    file.close();
    cout << "Исходный файл \"" << filename << "\" успешно создан." << endl;
    return true;
}

/**
 * @brief Функция для чтения, сортировки и записи слов.
 */
bool processAndSortWords(const std::string& source_filename, 
                         const std::string& target_filename, 
                         std::vector<std::string>& all_words) {
    
    ifstream source_file(source_filename);
    if (!source_file.is_open()) {
        cerr << "Ошибка: Не удалось открыть исходный файл: " << source_filename << endl;
        return false;
    }

    string line;
    all_words.clear(); // Очищаем список слов перед заполнением

    // 1. Считывание строк и разбиение на слова
    while (getline(source_file, line)) {
        stringstream ss(line);
        string word;
        
        // Разбиваем строку на слова с использованием строкового потока
        while (ss >> word) {
            // Удаляем возможные знаки препинания в конце слова, если необходимо
            // В данном примере просто добавляем слово
            all_words.push_back(word); 
        }
    }

    source_file.close();
    
    if (all_words.empty()) {
        cerr << "Предупреждение: Файл не содержит слов." << endl;
        return false;
    }

    // 2. Сортировка слов по алфавиту
    // Используем std::sort для сортировки std::vector<std::string>
    // Сортировка по алфавиту (лексикографический порядок) по умолчанию
    sort(all_words.begin(), all_words.end());

    // 3. Вывод отсортированных слов во второй файл
    ofstream target_file(target_filename);
    if (!target_file.is_open()) {
        cerr << "Ошибка: Не удалось открыть целевой файл для записи: " << target_filename << endl;
        return false;
    }

    for (const string& word : all_words) {
        target_file << word << endl; // Каждое слово на новой строке
    }

    target_file.close();
    cout << "Отсортированные слова успешно записаны в файл \"" << target_filename << "\"." << endl;
    
    return true;
}