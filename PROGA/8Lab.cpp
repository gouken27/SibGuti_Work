#include "Database.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <cmath>

// --- Вспомогательная функция для печати ---
void printSchoolHeader() {
    std::cout << "\n----------------------------------------------------------\n";
    std::cout << "| № Школы | Выпускники | Поступившие | % Поступивших |\n";
    std::cout << "----------------------------------------------------------\n";
}

// --- Задача 1: Анализ школ и сортировка индексным массивом ---

void schoolAnalysisDemo() {
    std::cout << "--- Задача 1: Анализ школ ---\n";

    // 1. Формирование массива из записей (пример данных)
    std::vector<SchoolRecord> schools = {
        {101, 120, 95, 0.0},
        {5, 80, 78, 0.0},
        {45, 150, 100, 0.0},
        {12, 110, 80, 0.0},
        {200, 50, 25, 0.0}
    };

    // Вычисление процента поступивших и заполнение индексного массива
    int N = schools.size();
    std::vector<int> index_array(N);

    for (int i = 0; i < N; ++i) {
        // Вычисление процента
        if (schools[i].graduates > 0) {
            schools[i].admission_rate = 
                (static_cast<double>(schools[i].admitted) / schools[i].graduates) * 100.0;
        } else {
            schools[i].admission_rate = 0.0;
        }
        // Инициализация индексного массива
        index_array[i] = i;
    }

    // 2. Сортировка индексного массива
    // Сортируем индексы так, чтобы при обращении schools[index_array[i]]
    // массив был упорядочен по admission_rate (по убыванию)
    std::sort(index_array.begin(), index_array.end(), 
        [&schools](int a, int b) {
            // Сортировка по убыванию процента поступивших
            return schools[a].admission_rate > schools[b].admission_rate;
        }
    );

    // 3. Вывод данных
    std::cout << "Данные о школах, отсортированные по проценту поступивших (по убыванию):\n";
    printSchoolHeader();
    std::cout << std::fixed << std::setprecision(2);

    for (int idx : index_array) {
        const SchoolRecord& s = schools[idx]; // Доступ к данным через отсортированный индекс
        std::cout << "| " << std::setw(7) << s.number 
                  << " | " << std::setw(10) << s.graduates
                  << " | " << std::setw(11) << s.admitted
                  << " | " << std::setw(14) << s.admission_rate << " |\n";
    }
    std::cout << "----------------------------------------------------------\n";
}

// --- Задача 2: Анализ общежития и факультетов ---

void dormitoryAnalysisDemo() {
    std::cout << "\n--- Задача 2: Анализ общежития ---\n";

    // 1. Формирование справочника факультетов (используем std::map для быстрого поиска по ID)
    std::map<int, Faculty> faculty_directory = {
        {1, {1, "Информационные технологии"}},
        {2, {2, "Экономика и Финансы"}},
        {3, {3, "Юриспруденция"}},
        {4, {4, "Дизайн и Архитектура"}}
    };

    // 2. Формирование базы данных комнат
    std::vector<DormRoom> dorm_rooms = {
        {101, 18.5, 1, 2},
        {102, 18.0, 1, 3},
        {201, 20.0, 2, 2},
        {202, 19.5, 3, 4},
        {203, 21.0, 2, 3},
        {301, 16.0, 1, 1},
        {302, 22.0, 4, 3},
        {303, 20.0, 3, 2},
        {401, 25.0, 4, 4}
    };

    // --- Сводная статистика ---
    struct FacultyStats {
        int room_count = 0;
        int student_count = 0;
        double total_area = 0.0;
    };
    
    // Карта для хранения статистики: Ключ = ID факультета
    std::map<int, FacultyStats> stats_by_faculty;

    // Сбор статистики по комнатам
    for (const auto& room : dorm_rooms) {
        int id = room.faculty_id;
        
        // Убедимся, что ID существует в справочнике, прежде чем обновлять статистику
        if (faculty_directory.count(id)) {
            stats_by_faculty[id].room_count++;
            stats_by_faculty[id].student_count += room.residents;
            stats_by_faculty[id].total_area += room.area;
        } else {
            std::cerr << "Предупреждение: Комната " << room.room_number 
                      << " имеет неизвестный Faculty ID: " << id << std::endl;
        }
    }

    // 3. Вывод данных по каждому факультету
    std::cout << "\nСводная статистика по факультетам:\n";
    std::cout << "----------------------------------------------------------------------------------------------------\n";
    std::cout << "| ID | Факультет                      | Комнат | Студентов | Общая площадь | Средняя площадь на 1 ст. |\n";
    std::cout << "----------------------------------------------------------------------------------------------------\n";

    std::cout << std::fixed << std::setprecision(2);

    for (const auto& pair : stats_by_faculty) {
        int id = pair.first;
        const FacultyStats& stats = pair.second;
        const std::string& name = faculty_directory[id].name;
        
        double avg_area_per_student = 0.0;
        if (stats.student_count > 0) {
            avg_area_per_student = stats.total_area / stats.student_count;
        }

        std::cout << "| " << std::setw(2) << id << " | " 
                  << std::setw(30) << std::left << name << std::right << " | "
                  << std::setw(6) << stats.room_count << " | "
                  << std::setw(9) << stats.student_count << " | "
                  << std::setw(13) << stats.total_area << " | "
                  << std::setw(24) << avg_area_per_student << " |\n";
    }
    std::cout << "----------------------------------------------------------------------------------------------------\n";
}