// lab4.cpp
#include "Database.hpp"
#include <iostream>
#include <cstdlib> // Для rand, srand, malloc, free
#include <ctime>   // Для time
#include <iomanip> // Для форматирования

// --- Вспомогательные функции ---

int** allocateMatrix(int m, int n) {
    // 1. Выделение памяти под массив указателей на строки
    int **matrix = new (std::nothrow) int*[m];
    if (matrix == nullptr) return nullptr;

    // 2. Выделение памяти под сами строки
    for (int i = 0; i < m; ++i) {
        matrix[i] = new (std::nothrow) int[n];
        if (matrix[i] == nullptr) {
            // Ошибка: очистить уже выделенную память и вернуть nullptr
            for (int j = 0; j < i; ++j) {
                delete[] matrix[j];
            }
            delete[] matrix;
            return nullptr;
        }
    }
    return matrix;
}

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
            // Выравнивание для красивого вывода
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << "\n";
    }
}

// --- Задача 1: Удаление строки и столбца с максимальным элементом ---

void removeMaxElementRowColDemo() {
    std::cout << "\n--- Задача 1: Удаление строки и столбца с Max ---\n";
    
    int m;
    const int N = 5; // Фиксированный размер столбцов N=5
    
    std::cout << "Введите количество строк M: ";
    if (!(std::cin >> m) || m <= 0) {
        std::cerr << "Некорректное M." << std::endl;
        return;
    }

    if (m == 1 || N == 1) {
        std::cerr << "Матрица слишком мала для удаления строки/столбца (должна быть минимум 2x2)." << std::endl;
        return;
    }

    srand(time(0));
    
    // Выделение памяти для B
    int **B = allocateMatrix(m, N);
    if (B == nullptr) {
        std::cerr << "Ошибка выделения памяти для B." << std::endl;
        return;
    }

    // Заполнение B и поиск Max
    int max_val = B[0][0] = rand() % 100 - 50;
    int max_row = 0;
    int max_col = 0;
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == 0 && j == 0) continue; // 0,0 уже инициализирован

            B[i][j] = rand() % 100 - 50; // Случайные числа [-50, 49]
            
            if (B[i][j] > max_val) {
                max_val = B[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }

    printMatrix(B, m, N, "B (исходная)");
    std::cout << "Максимальный элемент: " << max_val 
              << " в позиции [" << max_row << "][" << max_col << "]" << std::endl;

    // --- Создание новой матрицы C[m-1][n-1] ---
    const int M_NEW = m - 1;
    const int N_NEW = N - 1;
    
    int **C = allocateMatrix(M_NEW, N_NEW);
    if (C == nullptr) {
        std::cerr << "Ошибка выделения памяти для C." << std::endl;
        freeMatrix(B, m);
        return;
    }

    // Копирование элементов в C, пропуская max_row и max_col
    int c_i = 0; // Индекс строки в C
    for (int i = 0; i < m; ++i) {
        // Пропускаем строку с максимальным элементом
        if (i == max_row) continue;

        int c_j = 0; // Индекс столбца в C
        for (int j = 0; j < N; ++j) {
            // Пропускаем столбец с максимальным элементом
            if (j == max_col) continue;

            C[c_i][c_j] = B[i][j];
            c_j++;
        }
        c_i++;
    }

    printMatrix(C, M_NEW, N_NEW, "C (результат)");

    // Освобождение памяти
    freeMatrix(B, m);
    freeMatrix(C, M_NEW);
}

// --- Задача 2: Матрица с суммами строк/столбцов ---

void createSumMatrixDemo() {
    std::cout << "\n--- Задача 2: Матрица с суммами строк и столбцов ---\n";
    
    int m, n;
    std::cout << "Введите M (строки): ";
    if (!(std::cin >> m) || m <= 0) {
        std::cerr << "Некорректное M." << std::endl;
        return;
    }
    std::cout << "Введите N (столбцы): ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Некорректное N." << std::endl;
        return;
    }

    srand(time(0));

    // Выделение памяти для A
    int **A = allocateMatrix(m, n);
    if (A == nullptr) {
        std::cerr << "Ошибка выделения памяти для A." << std::endl;
        return;
    }

    // Заполнение A
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = rand() % 20; // Случайные числа [0, 19]
        }
    }
    printMatrix(A, m, n, "A (исходная)");

    // --- Создание новой матрицы D[m+1][n+1] ---
    const int M_NEW = m + 1;
    const int N_NEW = n + 1;
    
    int **D = allocateMatrix(M_NEW, N_NEW);
    if (D == nullptr) {
        std::cerr << "Ошибка выделения памяти для D." << std::endl;
        freeMatrix(A, m);
        return;
    }

    long long total_sum = 0;

    // 1. Копирование A в D и вычисление сумм строк
    for (int i = 0; i < m; ++i) {
        long long row_sum = 0;
        for (int j = 0; j < n; ++j) {
            D[i][j] = A[i][j];
            row_sum += A[i][j];
        }
        // Запись суммы строки в последний столбец D[i][n]
        D[i][n] = (int)row_sum; 
        total_sum += row_sum;
    }

    // 2. Вычисление сумм столбцов
    for (int j = 0; j < n; ++j) {
        long long col_sum = 0;
        for (int i = 0; i < m; ++i) {
            col_sum += A[i][j];
        }
        // Запись суммы столбца в последнюю строку D[m][j]
        D[m][j] = (int)col_sum; 
    }

    // 3. Запись общей суммы в D[m][n] (последний элемент)
    D[m][n] = (int)total_sum; 

    printMatrix(D, M_NEW, N_NEW, "D (результат с суммами)");

    // Освобождение памяти
    freeMatrix(A, m);
    freeMatrix(D, M_NEW);
}