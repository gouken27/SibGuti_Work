// lab3.cpp
#include "Database.hpp"
#include <iostream>
#include <cstdlib> // Для malloc, free, rand, srand
#include <ctime>   // Для time
#include <iomanip> // Для форматирования вывода

// --- Задача 1 ---
bool arraySplitMallocDemo() {
    int n;
    std::cout << "Введите размер исходного массива n: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Некорректный размер массива." << std::endl;
        return false;
    }

    // Инициализация генератора случайных чисел
    srand(time(0));

    // 1. Выделение памяти под b[n]
    int *b = (int*)malloc(n * sizeof(int));
    if (b == NULL) {
        std::cerr << "Ошибка выделения памяти для массива b." << std::endl;
        return false;
    }

    // 2. Заполнение b и подсчет положительных/отрицательных
    int count_pos = 0;
    int count_neg = 0;
    
    std::cout << "\nИсходный массив b[" << n << "]:\n";
    for (int i = 0; i < n; ++i) {
        // Случайное число в диапазоне [-50, 50]
        b[i] = rand() % 101 - 50; 
        std::cout << b[i] << " ";
        
        if (b[i] > 0) {
            count_pos++;
        } else if (b[i] < 0) {
            count_neg++;
        }
    }
    std::cout << "\n";

    // Размер массивов c и d
    int m = count_pos; // Количество положительных
    int k = count_neg; // Количество отрицательных

    // 3. Выделение памяти под c[m] и d[k]
    int *c = (int*)malloc(m * sizeof(int));
    int *d = (int*)malloc(k * sizeof(int));
    
    if (c == NULL || d == NULL) {
        std::cerr << "Ошибка выделения памяти для массивов c или d." << std::endl;
        free(b);
        return false;
    }

    // 4. Заполнение c и d
    int pos_idx = 0;
    int neg_idx = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] > 0) {
            c[pos_idx++] = b[i];
        } else if (b[i] < 0) {
            d[neg_idx++] = b[i];
        }
    }

    // 5. Вывод полученных массивов
    std::cout << "\nМассив c[m=" << m << "] (положительные):\n";
    for (int i = 0; i < m; ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << "\n";

    std::cout << "\nМассив d[k=" << k << "] (отрицательные):\n";
    for (int i = 0; i < k; ++i) {
        std::cout << d[i] << " ";
    }
    std::cout << "\n";

    // 6. Освобождение памяти
    free(b);
    free(c);
    free(d);
    std::cout << "\nПамять освобождена." << std::endl;
    return true;
}

// --- Задача 2 ---
// Простая функция для обмена указателей
void swapPointers(double **p1, double **p2) {
    double *temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void pointerSortNewDemo() {
    int n;
    std::cout << "\n--- Задача 2: Сортировка указателей ---\n";
    std::cout << "Введите размер массива n: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Некорректный размер массива." << std::endl;
        return;
    }

    // 1. Выделение памяти под a[n] (вещественные) и b[n] (указатели)
    double *a = new (std::nothrow) double[n];
    double **b = new (std::nothrow) double*[n];
    
    if (a == nullptr || b == nullptr) {
        std::cerr << "Ошибка выделения памяти (new)." << std::endl;
        delete[] a;
        delete[] b;
        return;
    }

    // 2. Заполнение a и b
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nИсходный массив a[" << n << "]:\n";
    for (int i = 0; i < n; ++i) {
        // Случайное вещественное число, например, от 0.0 до 100.0
        a[i] = (double)rand() / RAND_MAX * 100.0;
        b[i] = &a[i]; // Заполнение массива указателей адресами элементов 'a'
        std::cout << a[i] << " ";
    }
    std::cout << "\n";

    // 3. Сортировка (методом выбора) массива указателей 'b'
    // Сравнение происходит по значению, на которое указывает указатель (*b[i])
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            // Сравниваем значения, на которые указывают b[min_idx] и b[j]
            if (*b[j] < *b[min_idx]) {
                min_idx = j;
            }
        }
        // Меняем местами указатели в массиве b
        if (min_idx != i) {
            swapPointers(&b[i], &b[min_idx]);
        }
    }

    // 4. Вывод отсортированного массива (через указатели)
    std::cout << "\nОтсортированный массив (по массиву указателей):\n";
    for (int i = 0; i < n; ++i) {
        // Выводим значение, на которое указывает b[i]
        std::cout << *b[i] << " ";
    }
    std::cout << "\n";

    // 5. Вывод исходного массива (чтобы убедиться, что он не изменился)
    std::cout << "\nИсходный массив a (без изменений):\n";
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";

    // 6. Освобождение памяти
    delete[] a;
    delete[] b;
    std::cout << "\nПамять освобождена." << std::endl;
}

// --- Задача 3 ---
void sieveOfEratosthenes(int n) {
    std::cout << "\n--- Задача 3: Решето Эратосфена ---\n";
    if (n < 2) {
        std::cout << "Простые числа в диапазоне [2, " << n << "] отсутствуют." << std::endl;
        return;
    }

    // Динамический массив булевых значений (используем char для экономии памяти)
    // Размер n+1, чтобы использовать индексы от 0 до n
    bool *isPrime = new (std::nothrow) bool[n + 1];
    if (isPrime == nullptr) {
        std::cerr << "Ошибка выделения памяти для решета." << std::endl;
        return;
    }

    // Инициализация: считаем, что все числа простые
    for (int i = 0; i <= n; ++i) {
        isPrime[i] = true;
    }
    
    // Числа 0 и 1 не являются простыми
    isPrime[0] = isPrime[1] = false;

    // Основной алгоритм Решета Эратосфена
    // Начинаем с p=2, идем до sqrt(n)
    for (int p = 2; p * p <= n; ++p) {
        // Если isPrime[p] не изменилось, значит p - простое число
        if (isPrime[p] == true) {
            // Обновляем все кратные числа, начиная с p*p
            // (меньшие кратные уже были помечены предыдущими простыми числами)
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    
    // Вывод простых чисел
    std::cout << "Простые числа в диапазоне от 2 до " << n << ":\n";
    for (int p = 2; p <= n; ++p) {
        if (isPrime[p]) {
            std::cout << p << " ";
        }
    }
    std::cout << "\n";

    // Освобождение памяти
    delete[] isPrime;
    std::cout << "Память освобождена." << std::endl;