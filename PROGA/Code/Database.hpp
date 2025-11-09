#ifndef LAB1_HPP
#define LAB1_HPP
#include <vector>
#include <string> // Подключаем для использования std::string

/**
 * @brief Структура для хранения даты Пасхи (месяц и день).
 */
struct EasterDate {
    int day;
    std::string month;
};

/**
 * @brief 1. Вычисляет дату православной Пасхи по алгоритму Гаусса.
 * @param year Год, для которого нужно провести вычисление.
 * @return Структура EasterDate, содержащая день и месяц.
 */
EasterDate calculateEaster(int year);

/**
 * @brief 2. Возводит число x в целую степень n (y = x^n).
 * Использует цикл, работает с положительными и отрицательными степенями.
 * @param x Вещественное число (основание).
 * @param n Целое число (показатель степени).
 * @return Результат x^n.
 */
double customPow(double x, int n);

/**
 * @brief 3. Вычисляет косинус (в радианах) с помощью ряда Тейлора.
 * @param x Угол в радианах.
 * @return Значение cos(x), вычисленное с точностью до 0.0001.
 */
double taylorCos(double x);

// LAB1_HPP

/**
 * @brief 1. Рекурсивно читает числа с клавиатуры, пока не будет введен 0.
 * После ввода 0 выводит на экран только положительные из введенных чисел.
 * Массив не используется.
 */
void readAndPrintPositive();

/**
 * @brief 2. Рекурсивно выводит массив: сначала все отрицательные,
 * затем все положительные.
 * Функция-обертка, которая вызывается один раз.
 * @param arr Массив ненулевых целых чисел.
 * @param n Размер массива.
 */
void printNegPos(int arr[], int n);

/**
 * @brief 3. Рекурсивно переводит и печатает
 * десятичное число в двоичной системе.
 * @param n Целое десятичное число.
 */
void decimalToBinary(int n);

// lab3.hpp

/**
 * @brief 1. Демонстрация работы с malloc и разделением массива на положительные/отрицательные.
 * @return true в случае успеха, false при ошибке выделения памяти.
 */
bool arraySplitMallocDemo();

/**
 * @brief 2. Демонстрация сортировки массива указателей с использованием оператора new.
 */
void pointerSortNewDemo();

/**
 * @brief 3. Вычисление простых чисел с помощью решета Эратосфена.
 * @param n Верхняя граница диапазона.
 */
void sieveOfEratosthenes(int n);

// lab4.hpp

/**
 * @brief Функция для выделения памяти под динамическую матрицу (m x n).
 * @param m Количество строк.
 * @param n Количество столбцов.
 * @return Указатель на указатель (matrix), или nullptr в случае ошибки.
 */
int** allocateMatrix(int m, int n);

/**
 * @brief Функция для освобождения памяти, выделенной под динамическую матрицу (m x n).
 * @param matrix Указатель на указатель на матрицу.
 * @param m Количество строк.
 */
void freeMatrix(int** matrix, int m);

/**
 * @brief 1. Удаление строки и столбца с максимальным элементом.
 */
void removeMaxElementRowColDemo();

/**
 * @brief 2. Создание матрицы с суммами строк и столбцов.
 */
void createSumMatrixDemo();


// lab5.hpp

/**
 * @brief Функция для освобождения памяти, выделенной под динамическую матрицу (m x n).
 * @param matrix Указатель на указатель на матрицу.
 * @param m Количество строк.
 */
void freeMatrix(int** matrix, int m);

/**
 * @brief 1. Преобразование одномерного массива A в двумерный B с заполнением нулями.
 */
void arrayToMatrixPaddingDemo();

/**
 * @brief 2. Создание двумерного массива с переменной длиной строки (таблица умножения).
 */
void createMultiplicationTableDemo();

// lab6.hpp
/**
 * @brief 1. Вычисляет периметр и площадь треугольника по трем сторонам.
 * Результаты возвращаются через параметры-указатели.
 *
 * @param a Длина первой стороны.
 * @param b Длина второй стороны.
 * @param c Длина третьей стороны.
 * @param perimeter_ptr Указатель для сохранения периметра.
 * @param area_ptr Указатель для сохранения площади.
 * @return 1, если треугольник существует; 0, если не существует (ошибка).
 */
int calculateTriangleProps(double a, double b, double c, double *perimeter_ptr, double *area_ptr);

/**
 * @brief 2. Определяет вероятность рождения m девочек или m мальчиков среди n детей.
 *
 * @param n Общее количество детей.
 * @param m Целевое количество (девочек или мальчиков).
 * @param prob_girls Ссылка для сохранения вероятности m девочек.
 * @param prob_boys Ссылка для сохранения вероятности m мальчиков.
 * @return true, если входные данные корректны; false, если некорректны (n < 0, m < 0, m > n).
 */
bool calculateBirthProbability(int n, int m, double &prob_girls, double &prob_boys);

// Вспомогательная функция для вычисления факториала (для C(n,m))
long long factorial(int n);

// lab7.hpp

/**
 * @brief 1. Обнуляет элементы массива, находящиеся между двумя минимальными.
 * Если минимальных элементов меньше двух или они не найдены, массив не изменяется.
 * * @param arr Ссылка на вектор целых чисел, который будет изменен.
 */
void zeroBetweenMin(std::vector<int> &arr);

/**
 * @brief 2. Вычисляет сумму элементов каждой строки двумерного массива 
 * с переменной длиной, где 0-й элемент хранит длину строки.
 * * @param jagged_array Указатель на двумерный массив (массив указателей).
 * @param num_rows Количество строк в массиве.
 * @param sums Ссылка на вектор, куда будут записаны суммы строк.
 */
void calculateJaggedArraySums(int **jagged_array, int num_rows, 
                              std::vector<int> &sums);

/**
 * @brief 3. Сортирует одномерный массив в порядке убывания.
 * * @param arr Ссылка на вектор целых чисел.
 */
void sortDescending(std::vector<int> &arr);

/**
 * @brief 3. Поиск элемента перебором.
 * * @param arr Ссылка на вектор.
 * @param target Искомый элемент.
 * @param iterations Ссылка для записи количества итераций.
 * @return true, если элемент найден; false иначе.
 */
bool linearSearch(const std::vector<int> &arr, int target, int &iterations);

/**
 * @brief 3. Бинарный поиск элемента в отсортированном по убыванию массиве.
 * * @param arr Ссылка на вектор.
 * @param target Искомый элемент.
 * @param iterations Ссылка для записи количества итераций.
 * @return true, если элемент найден; false иначе.
 */
bool binarySearchDescending(const std::vector<int> &arr, int target, int &iterations);

// Вспомогательная функция для печати одномерного вектора
void printVector(const std::vector<int> &arr, const std::string &name);

// Вспомогательная функция для печати двумерного массива
void printJaggedArray(int **jagged_array, int num_rows);

// lab8.hpp

// --- Задача 1: Информация о школах ---

struct SchoolRecord {
    int number;             // Номер школы
    int graduates;          // Количество выпускников
    int admitted;           // Число поступивших в ВУЗ
    double admission_rate;  // Процент поступивших (вычисляется)
};

/**
 * @brief Выполняет все шаги задачи 1: формирует массив, сортирует его
 * по проценту поступивших с помощью индексного массива и выводит результаты.
 */
void schoolAnalysisDemo();


// --- Задача 2: Информация об общежитии и факультетах ---

struct Faculty {
    int id;               // Уникальный ID факультета (ключ справочника)
    std::string name;     // Название факультета
};

struct DormRoom {
    int room_number;      // Номер комнаты
    double area;          // Площадь комнаты
    int faculty_id;       // Номер факультета (ссылка на справочник)
    int residents;        // Количество проживающих
};

/**
 * @brief Выполняет все шаги задачи 2: формирует справочник, базу комнат,
 * и выводит сводную статистику по факультетам.
 */
void dormitoryAnalysisDemo();

// lab9.hpp

// --- Общие структуры данных ---
const int NUM_GRADES = 4;

struct StudentData {
    std::string surname;
    int grades[NUM_GRADES];
};

// --- Задача 1: Односвязный список ---
// Объявление узла должно быть в HPP
struct SinglyNode {
    StudentData data;
    SinglyNode* next;
};

// Функции для односвязного списка
SinglyNode* demoSinglyList();
void printSinglyList(SinglyNode* head);
void freeSinglyList(SinglyNode* head);

// --- Задача 2: Двусвязный список ---
// Объявление узла должно быть в HPP
struct DoublyNode {
    StudentData data;
    DoublyNode* prev;
    DoublyNode* next;
};

// Функции для двусвязного списка
DoublyNode* demoDoublyList();
void printDoublyList(DoublyNode* head);
void freeDoublyList(DoublyNode* head);

// --- Задача 3: Двоичное дерево ---
// Объявление узла должно быть в HPP
struct TreeNode {
    StudentData data;
    TreeNode* left;
    TreeNode* right;
};

// Функции для двоичного дерева
TreeNode* demoBinaryTree();
void printInOrder(TreeNode* root);
void printReverseOrder(TreeNode* root);
void searchStudentInTree(TreeNode* root, const std::string& surname);
void freeTree(TreeNode* root);

// lab10.hpp

/**
 * @brief Создает исходный файл с несколькими строками и словами.
 * @param filename Имя файла для создания.
 * @return true, если файл создан успешно; false иначе.
 */
bool createSourceFile(const std::string& filename);

/**
 * @brief Считывает слова из исходного файла, сортирует их и записывает в целевой файл.
 *
 * @param source_filename Имя исходного файла.
 * @param target_filename Имя целевого файла для записи отсортированных слов.
 * @param all_words Ссылка на вектор, который будет содержать все слова из файла.
 * @return true, если операция выполнена успешно; false иначе.
 */
bool processAndSortWords(const std::string& source_filename, const std::string& target_filename, std::vector<std::string>& all_words);

// lab11.hpp

// --- Структура данных для записи пассажира ---
struct Passenger {
    std::string full_name;       // ФИО пассажира
    int baggage_count;           // Количество занимаемых багажом мест
    double total_weight;         // Общий вес вещей (кг)
};

// --- Функции управления данными (объявления) ---

/**
 * @brief Отображает меню и обрабатывает выбор пользователя.
 */
void runPassengerManager();

/**
 * @brief а) Создает бинарный файл из N записей.
 * @param N Количество записей для создания.
 */
void createFile(int N);

/**
 * @brief б) Просматривает и выводит все записи из файла.
 */
void viewFile();

/**
 * @brief в) Добавляет новую запись в конец файла.
 */
void appendRecord();

/**
 * @brief г) Удаляет записи, общий вес которых меньше заданного лимита (по умолчанию 10 кг).
 * @param min_weight Минимальный вес для сохранения записи.
 */
void deleteRecordsByWeight(double min_weight = 10.0);

/**
 * @brief д) Находит пассажира по фамилии и позволяет изменить общий вес его вещей.
 */
void modifyWeightBySurname();

#endif