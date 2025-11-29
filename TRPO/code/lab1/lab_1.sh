#!/bin/bash

# Запрос подтверждения запуска скрипта
read -p "Запустить выполнение скрипта (Y/N): " answer

# Проверка ответа пользователя
case $answer in
    [Yy]|[Yy][Ee][Ss])
        echo "Выполнение скрипта начато..."
        
        # a. Создание директории info
        mkdir -p info
        
        # b. Переход в директорию info
        cd info
        
        # c. Создание файла system.txt
        touch system.txt
        
        # d. Запись информации в файл system.txt
        {
            # i. Текущая дата и время
            echo "=== Текущая дата и время ==="
            date
            echo
            
            # ii. Имя хоста системы
            echo "=== Имя хоста системы ==="
            hostname
            echo
            
            # iii. Версия ядра Linux
            echo "=== Версия ядра Linux ==="
            uname -r
            echo
            
            # iv. Имя модели процессора
            echo "=== Имя модели процессора ==="
            lscpu | grep "Model name" | awk -F: '{print $2}' | tr -s ' ' | sed 's/^ //'
            echo
            
        } > system.txt
        
        # e. Вывод сообщения об успехе
        echo "Информация о системе записана в файл system.txt."
        
        # f. Возврат в предыдущую директорию
        cd ..
        
        # g. Создание директории bacup
        mkdir -p bacup
        
        # h. Переход в директорию bacup
        cd bacup
        
        # i. Копирование файла system.txt
        cp ../info/system.txt .
        
        # j. Вывод сообщения о создании резервной копии
        echo "Создан каталог bacup и создана копия файла ./info/system.txt."
        
        # k. Возврат в предыдущую директорию
        cd ..
        
        echo "Скрипт завершил работу успешно."
        ;;
    [Nn]|[Nn][Oo])
        # Действия при отказе
        echo "Пока)"
        ;;
    *)
        echo "Некорректный ввод. Скрипт завершен."
        exit 1
        ;;
esac