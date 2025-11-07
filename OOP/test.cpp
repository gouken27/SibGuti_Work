#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int** createMatrix(int N) {
    int** matrix = new int*[N];
    for (int i = 0; i < N; ++i) {
        matrix[i] = new int[N];
    }
    return matrix;
}

void fillRandom(int** matrix, int N, int min = 1, int max = 99) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = min + rand() % (max - min + 1);
        }
    }
}

void printMatrix(int** matrix, int N, const string& title) {
    cout << title << ":\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void deleteMatrix(int** matrix, int N) {
    for (int i = 0; i < N; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// === ЗАДАНИЕ 1: Транспонирование ===
void task1(int N) {
    cout << "=== ЗАДАНИЕ 1: Транспонирование матрицы ===" << endl;

    // Создание и заполнение исходной матрицы
    int** A = createMatrix(N);
    fillRandom(A, N);
    printMatrix(A, N, "Исходная матрица");

    // Создание транспонированной матрицы
    int** AT = createMatrix(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            AT[i][j] = A[j][i];
        }
    }
    printMatrix(AT, N, "Транспонированная матрица");

    // Освобождение памяти
    deleteMatrix(A, N);
    deleteMatrix(AT, N);
}

// === ЗАДАНИЕ 2: Обмен строк и столбцов ===
void task2(int N) {
    cout << "=== ЗАДАНИЕ 2: Обмен строк и столбцов ===" << endl;

    int** M = createMatrix(N);
    fillRandom(M, N);
    printMatrix(M, N, "Исходная матрица");

    // 1. Поменять местами первую и последнюю строки
    for (int j = 0; j < N; ++j) {
        swap(M[0][j], M[N-1][j]);
    }
    printMatrix(M, N, "После обмена 1-й и последней строк");

    // 2. Поменять местами первый и последний столбцы
    for (int i = 0; i < N; ++i) {
        swap(M[i][0], M[i][N-1]);
    }
    printMatrix(M, N, "После обмена 1-го и последнего столбцов");

    deleteMatrix(M, N);
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    int N;
    cout << "Введите размер матрицы N (N >= 2): ";
    cin >> N;

    if (N < 2) {
        cout << "Ошибка: N должно быть не менее 2!" << endl;
        return 1;
    }

    task1(N);
    task2(N);

    return 0;
}