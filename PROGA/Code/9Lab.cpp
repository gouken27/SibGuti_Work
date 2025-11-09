#include "Database.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// --- Вспомогательные функции (скрытая реализация) ---

void generateRandomGrades(int grades[]) {
    for (int i = 0; i < NUM_GRADES; ++i) {
        grades[i] = rand() % 4 + 2; // Оценки от 2 до 5
    }
}

void printStudentData(const StudentData& data) {
    cout << setw(15) << data.surname << " | Оценки: [";
    for (int i = 0; i < NUM_GRADES; ++i) {
        cout << data.grades[i] << (i < NUM_GRADES - 1 ? ", " : "]");
    }
    cout << endl;
}

// ==========================================================
//                 ЗАДАЧА 1: Односвязный список
// ==========================================================

// Скрытая функция вставки в начало
SinglyNode* insertSingly(SinglyNode* head, const StudentData& data) {
    SinglyNode* newNode = new SinglyNode{data, head};
    return newNode;
}

// Скрытая функция сортировки (перестройка списка)
SinglyNode* sortSinglyList(SinglyNode* head) {
    if (!head || !head->next) return head;

    // 1. Копируем данные в вектор
    vector<StudentData> data_vector;
    SinglyNode* current = head;
    while (current) {
        data_vector.push_back(current->data);
        current = current->next;
    }

    // 2. Освобождаем старый список
    freeSinglyList(head);

    // 3. Сортируем вектор по фамилии
    sort(data_vector.begin(), data_vector.end(), 
         [](const StudentData& a, const StudentData& b) {
             return a.surname < b.surname;
         });

    // 4. Строим новый отсортированный список
    SinglyNode* new_head = nullptr;
    for (int i = data_vector.size() - 1; i >= 0; --i) {
        new_head = insertSingly(new_head, data_vector[i]);
    }
    return new_head;
}

// Публичная функция для демонстрации (объявлена в HPP)
SinglyNode* demoSinglyList() {
    SinglyNode* head = nullptr;
    vector<string> surnames = {"Иванов", "Петров", "Сидоров", "Абрамов", "Кузнецов"};
    
    for (const auto& name : surnames) {
        StudentData data = {name};
        generateRandomGrades(data.grades);
        head = insertSingly(head, data);
    }
    
    // Сортируем по фамилии (по возрастанию)
    head = sortSinglyList(head);
    return head;
}

// Публичная функция печати
void printSinglyList(SinglyNode* head) {
    if (!head) {
        cout << "Список пуст.\n";
        return;
    }
    SinglyNode* current = head;
    while (current != nullptr) {
        printStudentData(current->data);
        current = current->next;
    }
}

// Публичная функция освобождения памяти
void freeSinglyList(SinglyNode* head) {
    SinglyNode* current = head;
    while (current) {
        SinglyNode* temp = current;
        current = current->next;
        delete temp;
    }
}

// ==========================================================
//                 ЗАДАЧА 2: Двусвязный список
// ==========================================================

// Скрытая функция вставки в начало
DoublyNode* insertDoubly(DoublyNode* head, const StudentData& data) {
    DoublyNode* newNode = new DoublyNode{data, nullptr, head};
    if (head) {
        head->prev = newNode;
    }
    return newNode;
}

// Скрытая функция проверки неудовлетворительной оценки
bool hasUnsatisfactoryGrade(const StudentData& data) {
    for (int i = 0; i < NUM_GRADES; ++i) {
        if (data.grades[i] == 2) {
            return true;
        }
    }
    return false;
}

// Скрытая функция удаления студентов по условию
DoublyNode* removeUnsatisfactory(DoublyNode* head) {
    DoublyNode* current = head;
    while (current) {
        DoublyNode* next_node = current->next; 

        if (hasUnsatisfactoryGrade(current->data)) {
            cout << "  Удаление: " << current->data.surname << endl;

            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next; // Удаляем голову
            }

            if (current->next) {
                current->next->prev = current->prev;
            }
            
            delete current;
        }
        current = next_node; 
    }
    return head;
}

// Публичная функция для демонстрации
DoublyNode* demoDoublyList() {
    DoublyNode* head = nullptr;
    vector<string> surnames = {"Алиев", "Баев", "Галиев", "Денисов", "Егоров"};
    
    for (int i = 0; i < surnames.size(); ++i) {
        StudentData data = {surnames[i]};
        generateRandomGrades(data.grades);
        if (i % 2 == 0) data.grades[0] = 2; // Гарантируем "двойку" для Алиева, Галеева, Егорова
        head = insertDoubly(head, data);
    }
    
    cout << "\nСписок до удаления записей:\n";
    printDoublyList(head);

    cout << "\n--- Запуск процедуры удаления студентов с оценкой 2 ---\n";
    head = removeUnsatisfactory(head);

    return head;
}

// Публичная функция печати
void printDoublyList(DoublyNode* head) {
    if (!head) {
        cout << "Список пуст.\n";
        return;
    }
    DoublyNode* current = head;
    while (current != nullptr) {
        printStudentData(current->data);
        current = current->next;
    }
}

// Публичная функция освобождения памяти
void freeDoublyList(DoublyNode* head) {
    DoublyNode* current = head;
    while (current) {
        DoublyNode* temp = current;
        current = current->next;
        delete temp;
    }
}

// ==========================================================
//                 ЗАДАЧА 3: Двоичное дерево
// ==========================================================

// Скрытая функция вставки в дерево
TreeNode* insertTreeNode(TreeNode* root, const StudentData& data) {
    if (root == nullptr) {
        return new TreeNode{data, nullptr, nullptr};
    }

    if (data.surname < root->data.surname) {
        root->left = insertTreeNode(root->left, data);
    } else if (data.surname > root->data.surname) {
        root->right = insertTreeNode(root->right, data);
    }
    return root;
}

// Публичная функция для демонстрации
TreeNode* demoBinaryTree() {
    TreeNode* root = nullptr;
    vector<string> surnames = {"Орлов", "Никитин", "Смирнов", "Тимофеев", "Крылов"};
    
    for (const auto& name : surnames) {
        StudentData data = {name};
        generateRandomGrades(data.grades);
        root = insertTreeNode(root, data);
    }
    return root;
}

// Публичная функция: Вывод по возрастанию (in-order traversal)
void printInOrder(TreeNode* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        printStudentData(root->data);
        printInOrder(root->right);
    }
}

// Публичная функция: Вывод по убыванию (reverse in-order traversal)
void printReverseOrder(TreeNode* root) {
    if (root != nullptr) {
        printReverseOrder(root->right);
        printStudentData(root->data);
        printReverseOrder(root->left);
    }
}

// Скрытая функция поиска
TreeNode* searchTreeNodeInternal(TreeNode* root, const string& surname) {
    if (root == nullptr || root->data.surname == surname) {
        return root;
    }

    if (surname < root->data.surname) {
        return searchTreeNodeInternal(root->left, surname);
    } else {
        return searchTreeNodeInternal(root->right, surname);
    }
}

// Публичная функция поиска
void searchStudentInTree(TreeNode* root, const string& surname) {
    TreeNode* result = searchTreeNodeInternal(root, surname);
    
    cout << "\nПоиск студента по фамилии \"" << surname << "\":\n";
    if (result) {
        cout << "  Студент найден: ";
        printStudentData(result->data);
    } else {
        cout << "  Студент с фамилией \"" << surname << "\" не найден." << endl;
    }
}

// Публичная функция освобождения памяти
void freeTree(TreeNode* root) {
    if (root != nullptr) {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}