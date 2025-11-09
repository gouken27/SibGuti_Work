#include "Database.hpp" // Подключаем наш заголовочный файл
#include <cmath>     // Подключаем для std::fabs, std::fmod, INFINITY и M_PI

// Определяем M_PI, если он не определен (актуально для некоторых компиляторов)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/**
 * @brief 1. Реализация вычисления даты Пасхи.
 */
EasterDate calculateEaster(int year) {
    // Алгоритм Гаусса для православной Пасхи
    int a = year % 19;
    int b = year % 4;
    int c = year % 7;
    int d = (19 * a + 15) % 30;
    int e = (2 * b + 4 * c + 6 * d + 6) % 7;
    int f = d + e;

    EasterDate result;
    
    // Этот алгоритм (с 4 апреля) корректно работает
    // для григорианского календаря в XX-XXI веках.
    if (f <= 26) {
        result.day = 4 + f;
        result.month = "Апреля";
    } else {
        result.day = f - 26;
        result.month = "Мая";
    }
    
    return result;
}

/**
 * @brief 2. Реализация функции возведения в степень.
 */
double customPow(double x, int n) {
    // y = x^n
    
    // Любое число (кроме 0) в степени 0 = 1
    if (n == 0) {
        return 1.0;
    }

    // Обработка 0 в основании
    if (x == 0.0) {
        return (n > 0) ? 0.0 : INFINITY; // 0^n = 0; 0^-n = бесконечность
    }

    double result = 1.0;
    int abs_n = n;
    
    // Если степень отрицательная, берем модуль
    if (n < 0) {
        abs_n = -n;
    }

    // Вычисляем x^|n| с помощью цикла
    for (int i = 0; i < abs_n; ++i) {
        result *= x;
    }

    // Если степень была отрицательной, возвращаем 1 / (x^|n|)
    if (n < 0) {
        return 1.0 / result;
    }
    
    // Иначе просто возвращаем результат
    return result;
}

/**
 * @brief 3. Реализация вычисления cos(x) через ряд Тейлора.
 */
double taylorCos(double x) {
    const double EPS = 0.0001;
    
    // cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ...
    // cos(x) = sum [ ((-1)^k * x^(2k)) / (2k)! ] for k = 0 to inf

    // Приведем x к диапазону [-2*PI, 2*PI] для лучшей сходимости
    x = std::fmod(x, 2 * M_PI);

    double sum = 1.0;    // Сумма ряда (начинаем с k=0, где член = 1)
    double term = 1.0;   // Текущий член ряда (k=0)
    int k = 0;

    // Мы вычисляем следующий член на основе предыдущего:
    // term_k+1 = term_k * (-1) * x*x / ((2k+1) * (2k+2))
    
    while (std::fabs(term) > EPS) {
        k++;
        // Вычисляем следующий член
        term = term * (-1) * x * x / ((2 * k - 1) * (2 * k));
        // Добавляем к сумме
        sum = sum + term;
    }
    
    return sum;
}