#include "Database.hpp"
#include <iostream>
#include <cmath>     // Для sqrt и fabs
#include <algorithm> // Для std::max

// --- Задача 1: Периметр и Площадь Треугольника (Указатели) ---

int calculateTriangleProps(double a, double b, double c, double *perimeter_ptr, double *area_ptr) {
    
    // 1. Контроль входных данных (существование треугольника)
    // Треугольник существует, если сумма любых двух сторон больше третьей.
    // А также все стороны должны быть положительными.
    if (a <= 0 || b <= 0 || c <= 0 ||
        a + b <= c || 
        a + c <= b || 
        b + c <= a) {
        
        // Ошибка: такой треугольник не может существовать
        return 0; 
    }

    // Проверка, что указатели не nullptr
    if (perimeter_ptr == nullptr || area_ptr == nullptr) {
        std::cerr << "Ошибка: Передан нулевой указатель (nullptr)." << std::endl;
        return 0; 
    }

    // 2. Вычисление Периметра (P)
    double P = a + b + c;
    *perimeter_ptr = P;

    // 3. Вычисление Площади (S) по формуле Герона
    double s = P / 2.0; // Полупериметр
    double S = std::sqrt(s * (s - a) * (s - b) * (s - c));
    *area_ptr = S;
    
    // Успех: треугольник существует
    return 1;
}

// --- Вспомогательная функция для Задачи 2 ---

// Вычисление факториала n!
long long factorial(int n) {
    if (n < 0) return 0; // Факториал отрицательного числа не определен
    if (n == 0 || n == 1) return 1;
    
    // Используем цикл для избежания переполнения стека при большой n (хотя n ограничено)
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        // Добавлен примитивный контроль переполнения (хотя для n=30 long long достаточно)
        if (result > LLONG_MAX / i) return 0; // Сигнал переполнения
        result *= i;
    }
    return result;
}

// Вычисление биномиального коэффициента C(n, m)
long double combinations(int n, int m) {
    if (m < 0 || m > n) return 0;
    if (m == 0 || m == n) return 1.0;
    if (m > n / 2) m = n - m; // Оптимизация

    // Используем упрощенную формулу, чтобы избежать больших факториалов
    // C(n, m) = (n * (n-1) * ... * (n-m+1)) / m!
    long double res = 1.0;
    for (int i = 1; i <= m; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

// --- Задача 2: Вероятность (Ссылки) ---

bool calculateBirthProbability(int n, int m, double &prob_girls, double &prob_boys) {
    
    // 1. Контроль входных данных
    if (n < 0 || m < 0 || m > n) {
        std::cerr << "Ошибка: Некорректные входные данные. Должно быть 0 <= m <= n." << std::endl;
        prob_girls = 0.0;
        prob_boys = 0.0;
        return false;
    }

    // 2. Исходные вероятности
    const double P = 0.45; // Вероятность девочки
    const double Q = 1.0 - P; // Вероятность мальчика (0.55)

    // 3. Вычисление C(n, m)
    long double C_nm = combinations(n, m);
    if (C_nm == 0) { // Проверка на переполнение или некорректность (хотя контролируется выше)
        std::cerr << "Ошибка: Слишком большие числа для C(n,m)." << std::endl;
        return false;
    }

    // 4. Вычисление вероятностей (Биномиальное распределение)
    
    // Вероятность m девочек: Pd = C(n,m) * p^m * q^(n-m)
    double Pd = C_nm * std::pow(P, m) * std::pow(Q, n - m);
    prob_girls = Pd;

    // Вероятность m мальчиков: Pm = C(n,m) * q^m * p^(n-m)
    // (По сути это вероятность n-m девочек)
    double Pm = C_nm * std::pow(Q, m) * std::pow(P, n - m);
    prob_boys = Pm;
    
    return true;
}