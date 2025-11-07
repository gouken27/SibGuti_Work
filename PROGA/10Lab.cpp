#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ifstream fin("input.txt");
    if (!fin) {
        std::cerr << "Ошибка: не удалось открыть файл input.txt для чтения.\n";
        return 1;
    }

    std::vector<std::string> words;
    std::string line;

    while (std::getline(fin, line)) {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            words.push_back(word);
        }
    }
    fin.close();

    // Сортируем
    std::sort(words.begin(), words.end());

    // Открываем и записываем отсортированные слова
    std::ofstream fout("output.txt");
    if (!fout) {
        std::cerr << "Ошибка: не удалось открыть файл output.txt для записи.\n";
        return 1;
    }

    for (const auto& w : words) {
        fout << w << "\n";
    }
    fout.close();

    std::cout << "Готово! Отсортированные слова записаны в output.txt.\n";
    return 0;
}