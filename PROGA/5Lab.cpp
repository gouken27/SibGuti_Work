#include "Database.hpp"
#include <iostream>
#include <cstdlib> // Для rand, srand
#include <ctime>   // Для time
#include <cmath>   // Для ceil
#include <iomanip> // Для форматирования

// --- Вспомогательная функция (из предыдущего задания) ---

void freeMatrix(int** matrix, int m) {
    if (matrix == nullptr) return;
    for (int i = 0; i < m; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printMatrix(int** matrix, int m, int n, const std::string& name) {
    std::cout << "\nМатрица " << name << " (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << "\n";
    }
}

// --- Задача 1: Преобразование A в B с заполнением нулями ---

void arrayToMatrixPaddingDemo() {
    std::cout << "\n--- Задача 1: Преобразование A -> B с дополнением нулями ---\n";
    
    int m, k;
    std::cout << "Введите размер одномерного массива M: ";
    if (!(std::cin >> m) || m <= 0) {
        std::cerr << "Некорректное M." << std::endl;
        return;
    }
    std::cout << "Введите K (количество элементов в строке матрицы B, K < M): ";
    if (!(std::cin >> k) || k <= 0 || k >= m) {
        std::cerr << "Некорректное K (K должно быть > 0 и < M)." << std::endl;
        return;
    }

    srand(time(0));

    // 1. Создание и заполнение одномерного массива A
    int *A = new (std::nothrow) int[m];
    if (A == nullptr) {
        std::cerr << "Ошибка выделения памяти для A." << std::endl;
        return;
    }
    
    std::cout << "\nМассив A[" << m << "]:\n";
    for (int i = 0; i < m; ++i) {
        A[i] = rand() % 50 + 1; // Случайные числа [1, 50]
        std::cout << A[i] << " ";
    }
    std::cout << "\n";

    // 2. Вычисление размера матрицы B
    // Количество строк (m_rows) = ceil(m / k)
    int m_rows = (m + k - 1) / k; // Эквивалент ceil(m / k) для целочисленной арифметики
    int n_cols = k;

    // 3. Выделение памяти для двумерной матрицы B[m_rows][n_cols]
    int **B = new (std::nothrow) int*[m_rows];
    if (B == nullptr) {
        std::cerr << "Ошибка выделения памяти для B." << std::endl;
        delete[] A;
        return;
    }
    for (int i = 0; i < m_rows; ++i) {
        B[i] = new (std::nothrow) int[n_cols];
        if (B[i] == nullptr) {
            std::cerr << "Ошибка выделения памяти для B[i]." << std::endl;
            freeMatrix(B, i); // Освобождаем то, что успели выделить
            delete[] A;
            return;
        }
    }

    // 4. Заполнение B из A с дополнением нулями
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            int current_index_in_A = i * k + j;
            
            if (current_index_in_A < m) {
                // Берем элемент из массива A
                B[i][j] = A[current_index_in_A];
            } else {
                // Недостающие элементы последней строки дополняем нулями
                B[i][j] = 0;
            }
        }
    }

    // 5. Вывод и очистка
    printMatrix(B, m_rows, n_cols, "B (результат)");

    delete[] A;
    freeMatrix(B, m_rows);
}

// --- Задача 2: Двумерный массив с переменной длиной строки (таблица умножения) ---

void createMultiplicationTableDemo() {
    std::cout << "\n--- Задача 2: Таблица умножения (переменная длина строки) ---\n";
    
    const int M = 9; // 9 строк для таблицы умножения 1..9

    // 1. Выделение памяти под массив указателей на строки (M строк)
    int **Table = new (std::nothrow) int*[M];
    if (Table == nullptr) {
        std::cerr << "Ошибка выделения памяти для Table." << std::endl;
        return;
    }

    std::cout << "\nТаблица умножения (до 9x9):\n";
    
    // 2. Заполнение: i-я строка имеет i+1 элементов
    for (int i = 0; i < M; ++i) {
        int n_cols = i + 1; // 1-я строка (i=0) имеет 1 столбец, 9-я (i=8) - 9 столбцов
        
        // Выделение памяти под текущую строку (переменная длина)
        Table[i] = new (std::nothrow) int[n_cols];
        if (Table[i] == nullptr) {
            std::cerr << "Ошибка выделения памяти для Table[" << i << "]." << std::endl;
            freeMatrix(Table, i); // Освобождаем то, что успели выделить
            return;
        }

        // Заполнение элементов строки: (i+1) * (j+1)
        for (int j = 0; j < n_cols; ++j) {
            int row_multiplier = i + 1;
            int col_multiplier = j + 1;
            Table[i][j] = row_multiplier * col_multiplier;
            
            // Вывод для наглядности
            std::cout << std::setw(5) << Table[i][j];
        }
        std::cout << "\n";
    }

    // 3. Освобождение памяти
    freeMatrix(Table, M);
}