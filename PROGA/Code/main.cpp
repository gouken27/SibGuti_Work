#include <stdio.h>
#include <Database.hpp>

int main() {
    int choice;
    int choice1;
    int choice2;
    int choice3;
    int choice4;
    int choice5;
    int choice6;
    int choice7;
    int choice8;
    int choice9;
    int choice10;
    
    printf("Выберите лабораторные введя цифру:\n");
    printf("1.Лабораторная\n");
    printf("2.Лабораторная\n");
    printf("3.Лабораторная\n");
    printf("4.Лабораторная\n");
    printf("5.Лабораторная\n");
    printf("6.Лабораторная\n");
    printf("7.Лабораторная\n");
    printf("8.Лабораторная\n");
    printf("9.Лабораторная\n");
    printf("10.Лабораторная\n");
    printf("11.Лабораторная\n");
    printf("12.Лабораторная\n");
    printf("13.Расчетно графическая работа\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("1 Лабораторная\n");
            printf("Выберите задание");
            switch(choice1) {
                case 1:
                    void DateEaster();
                    break;
                case 2:
                    int exponentiation(float x ,float n);
                    break;
                case 3:
                    void calculationCosinus();
                    break;
                default:
                printf("Ошибка ввода. Введите значение от 1 до 3");
                break;
            }
            break;
        case 2:
            printf("2 Лабораторная\n");
            printf("Выберите задание");
            switch(choice2) {
                case 1:
                    void inputArrayRecursively();
                    break;
                case 2:
                    void printPlusMinRecursive();
                    break;
                case 3:
                    void convertDecimalToBinary();
                    break;
                default:
                printf("Ошибка ввода. Введите значение от 1 до 3");
                break;
            }
            break;
            
        case 3:
            printf("3 Лабораторная\n");
            printf("Выберите задание");
            switch(choice3) {
                case 1:
                    void createAndSplitRandomArray();
                    break;
                case 2:
                    void sortViaPointerArray();
                    break;
                case 3:
                    void sieveOfEratosthenes();
                    break;
                default:
                printf("Ошибка ввода. Введите значение от 1 до 3");
                break;
            }
            break;
            
        case 4:
            printf("4 Лабораторная\n");
            printf("Выберите задание");
            switch(choice4) {
                case 1:
                    void removeRowAndColWithMaxElement();
                    break;
                case 2:
                    void expandMatrixWithSums();
                    break;
                default:
                printf("Ошибка ввода. Введите значение 1 или 2");
                break;
            }
            break;
            
        case 5:
            printf("5 Лабораторная\n");
            printf("Выберите задание");
            switch(choice5) {
                case 1:
                    void createJaggedMultiplicationTable();
                    break;
                case 2:
                    void convertArrayToMatrixWithPadding();
                    break;
                default:
                printf("Ошибка ввода. Введите значение 1 или 2");
                break;
            }
            break;
            
        case 6:
            printf("6 Лабораторная\n");
            printf("Выберите задание");
            switch(choice6) {
                case 1:
                    int calculateTriangleMetrics(double a, double b, double c, double* perimeter, double* area);
                    break;
                case 2:
                    void calculateGenderProbability(int n, int m, double& probGirls, double& probBoys);
                    break;
                default:
                printf("Ошибка ввода. Введите значение 1 или 2");
                break;
            }
            break;

        case 7:
            printf("7 Лабораторная\n");
            printf("Выберите задание");
            switch(choice7) {
                case 1:
                    void zeroBetweenTwoMins();
                    break;
                case 2:
                    void computeJaggedRowSums();
                    break;
                case 3:
                    void sortDescending();
                    break;
                default:
                printf("Ошибка ввода. Введите значение от 1 до 3");
                break;
            }
            break;
            
        case 8:
            printf("8 Лабораторная\n");
            printf("Выберите задание");
            switch(choice8) {
                case 1:
                    void sortSchoolsByAdmissionRate();
                    break;
                case 2:
                    void calculateFacultyStatistics();
                    break;
                default:
                printf("Ошибка ввода. Введите значение 1 или 2");
                break;
            }
            break;
        
        case 9:
            printf("9 Лабораторная\n");
            printf("Выберите задание\n");
            switch(choice9) {
                case 1:
                    void createAndSortStudentList();
                    break;
                case 2:
                    void createAndFilterStudentDLL();
                    break;
                case 3:
                    void createAndTraverseStudentBST();
                    break;
                default:
                printf("Ошибка ввода. Введите значение от 1 до 3");
                break;
            }
            break;

        case 10:
            printf("10 Лабораторная\n");
            void readSortAndWriteWords();
            break;

        case 11:
            printf("11 Лабораторная\n");
            void fiileWorks();
            break;

        case 12:
            printf("12 Лабораторная\n");
            void createSortingLibrary();
            break;

        case 13:
            int RGRwariantInput();
        default:
            printf("Ошибка ввода. Введите значение от 1 до 13");
            break;
        }
    
    return 0;
}