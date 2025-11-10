/* Практическое задание: Создание страницы через JavaScript */

document.addEventListener('DOMContentLoaded', () => {
    // 1. Создание заголовок <h1>
    const title = document.createElement('h1');
    title.textContent = "Любимые Аниме-Персонажи (Создано JS)";
    
    // 2. Создание списка <ul> с начальными элементами
    const characterList = document.createElement('ul');
    characterList.id = 'anime-list'; // Присваиваем ID для удобства

    const initialCharacters = ["Леви Аккерман", "Сайтама", "Рем"];
    initialCharacters.forEach(name => {
        const li = document.createElement('li');
        li.textContent = name;
        characterList.appendChild(li);
    });

    // 3. Создание кнопки
    const toggleButton = document.createElement('button');
    toggleButton.textContent = "Добавить / Удалить элемент";
    toggleButton.id = 'toggle-button';
    
    // Дополнительные персонажи для добавления
    const additionalCharacters = ["Спайк Шпигель", "Эдвард Элрик", "Лайт Ягами"];
    let characterIndex = 0; // Индекс для выбора следующего персонажа
    let isAdding = true; // Флаг для чередования действий

    // 4. Реализация логики при нажатии на кнопку
    toggleButton.addEventListener('click', () => {
        
        if (isAdding) {
            // --- ДОБАВЛЕНИЕ ЭЛЕМЕНТА ---
            
            // Если есть еще персонажи для добавления
            if (characterIndex < additionalCharacters.length) {
                const newCharacter = additionalCharacters[characterIndex];
                
                const newLi = document.createElement('li');
                newLi.textContent = newCharacter;
                characterList.appendChild(newLi);
                
                characterIndex++; // Переходим к следующему персонажу
                console.log(`Добавлен: ${newCharacter}`);
            } else {
                console.log("Дополнительные персонажи закончились. Начинаем удаление.");
                // Если персонажи для добавления закончились, сразу переходим к удалению
                isAdding = false;
                // Рекурсивный вызов для выполнения удаления в текущем клике
                // (Этот блок можно убрать, оставив только isAdding = false, если нужно, чтобы удаление сработало только со следующего клика)
                if (characterList.children.length > 0) {
                     characterList.lastElementChild.remove();
                     console.log("Удален последний элемент.");
                } else {
                    console.log("Список пуст.");
                }
            }
        } else {
            // --- УДАЛЕНИЕ ЭЛЕМЕНТА ---
            
            // Проверяем, есть ли что удалять
            if (characterList.children.length > 0) {
                // Удаляем последний элемент списка
                characterList.lastElementChild.remove();
                console.log("Удален последний элемент.");
            } else {
                console.log("Список пуст. Начинаем добавление.");
                // Если список пуст, переключаемся на добавление и сбрасываем индекс
                isAdding = true;
                characterIndex = 0;
            }
        }
        
        // Чередование действий для следующего клика
        // *Если в блоке isAdding не произошло переключения из-за пустого списка, меняем флаг*
        if (!(characterIndex === additionalCharacters.length && isAdding === true)) {
            isAdding = !isAdding; 
        }

        // Обновляем текст кнопки для наглядности
        toggleButton.textContent = isAdding ? "Добавить элемент" : "Удалить элемент";
    });

    // 5. Добавление созданных элементов на страницу (в <body>)
    document.body.appendChild(title);
    document.body.appendChild(toggleButton);
    document.body.appendChild(characterList);
});