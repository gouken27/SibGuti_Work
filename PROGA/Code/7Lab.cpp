#include "Database.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <climits> // Для INT_MAX
#include <iomanip>

// --- Вспомогательные функции ---

void printVector(const std::vector<int> &arr, const std::string &name) {
    std::cout << name << ": [";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
}

void printJaggedArray(int **jagged_array, int num_rows) {
    std::cout << "\nДвумерный массив с переменной длиной строк:\n";
    std::cout << "Формат: [Длина] Элемент1 Элемент2 ...\n";
    for (int i = 0; i < num_rows; ++i) {
        // Длина строки хранится в 0-м элементе
        int length = jagged_array[i][0];
        std::cout << "Строка " << i << ": ";
        
        // Печатаем длину и элементы (начиная с 1-го индекса)
        for (int j = 0; j <= length; ++j) {
            std::cout << std::setw(3) << jagged_array[i][j];
        }
        std::cout << "\n";
    }
}

// --- Задача 1: Обнуление элементов между минимальными ---

void zeroBetweenMin(std::vector<int> &arr) {
    if (arr.size() < 2) return;

    // 1. Находим минимальный элемент
    int min_val = arr[0];
    for (int val : arr) {
        if (val < min_val) {
            min_val = val;
        }
    }

    // 2. Находим индексы первого и последнего вхождения минимального элемента
    int first_min_idx = -1;
    int last_min_idx = -1;

    // Ищем первый
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == min_val) {
            first_min_idx = (int)i;
            break;
        }
    }
    
    // Ищем последний
    for (int i = arr.size() - 1; i >= 0; --i) {
        if (arr[i] == min_val) {
            last_min_idx = i;
            break;
        }
    }

    // Если минимальных элементов меньше двух (например, массив [5, 6, 7] или [5, 5])
    // или они совпадают (т.е. один минимальный элемент), то не обнуляем.
    if (first_min_idx == last_min_idx || first_min_idx == -1) {
        std::cout << "\n[zeroBetweenMin] Найдено менее двух разных позиций минимального элемента. Обнуление не требуется." << std::endl;
        return;
    }

    // 3. Обнуляем элементы между найденными индексами
    std::cout << "[zeroBetweenMin] Минимальный элемент: " << min_val 
              << ". Обнуление между индексами " << first_min_idx << " и " << last_min_idx << std::endl;
    
    // Обнуляем элементы от (first_min_idx + 1) до (last_min_idx - 1)
    for (int i = first_min_idx + 1; i < last_min_idx; ++i) {
        arr[i] = 0;
    }
}

// --- Задача 2: Сумма элементов строк в массиве с переменной длиной ---

void calculateJaggedArraySums(int **jagged_array, int num_rows, 
                              std::vector<int> &sums) {
    
    sums.clear(); // Очищаем вектор сумм перед началом
    
    for (int i = 0; i < num_rows; ++i) {
        // Длина строки L хранится в 0-м элементе. 
        // Фактическая длина данных = L, общая длина строки = L + 1
        int length = jagged_array[i][0]; 
        int current_sum = 0;
        
        // Суммируем элементы, начиная с 1-го индекса, т.е. L элементов
        for (int j = 1; j <= length; ++j) {
            current_sum += jagged_array[i][j];
        }
        sums.push_back(current_sum);
    }
}

// --- Задача 3: Сортировка и Поиск ---

void sortDescending(std::vector<int> &arr) {
    // Используем стандартную функцию sort с компаратором greater<int>()
    std::sort(arr.begin(), arr.end(), std::greater<int>());
}

// 3.1 Поиск перебором (Линейный поиск)
bool linearSearch(const std::vector<int> &arr, int target, int &iterations) {
    iterations = 0;
    for (int val : arr) {
        iterations++;
        if (val == target) {
            return true;
        }
    }
    return false;
}

// 3.2 Бинарный поиск в отсортированном по убыванию массиве
bool binarySearchDescending(const std::vector<int> &arr, int target, int &iterations) {
    iterations = 0;
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        iterations++;
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return true;
        } 
        
        // В отсортированном по УБЫВАНИЮ массиве:
        // Если элемент в середине МЕНЬШЕ цели, значит цель находится
        // в ЛЕВОЙ (верхней) половине.
        else if (arr[mid] < target) {
            high = mid - 1; // Ищем слева
        } 
        
        // Если элемент в середине БОЛЬШЕ цели, значит цель находится
        // в ПРАВОЙ (нижней) половине.
        else { // arr[mid] > target
            low = mid + 1;  // Ищем справа
        }
    }
    return false;
}