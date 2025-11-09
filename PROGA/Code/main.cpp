#include <stdio.h>


int main() {
    int choice;
    int choice2;
    int choice3;
    int choice4;
    int choice5;
    int choice6;
    int choice7;

    double a, b, result;
    
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
            printf("");
            break;
            
        case 2:
            printf("");
            break;
            
        case 3:
            printf("");
            break;
            
        case 4:
            printf("");
            break;
            
        case 5:
            printf("");
            break;
            
        case 6:
            printf("");
            break;

        case 7:
            printf("");
            break;
            
        case 8:
            printf("");
            break;
        
        case 9:
            printf("");
            break;

        case 10:
            printf("");
            break;

        case 11:
            printf("");
            break;

        case 12:
            printf("");
            break;

        case 13:
            printf("Выбери вариант(от 1 до 31):");
            scanf("%d", &choice2);
            switch (choice2)
            {
            case 1:
                
                break;
            
            default:
                break;
            }
            break;
        default:
            printf("Ошибка ввода. Введите значение от 1 до 13");
            break;
        }
    
    return 0;
}