document.addEventListener('DOMContentLoaded', () => {
    // 1. Заголовок h1
    const h1 = document.createElement('h1');
    h1.textContent = 'Мой список';
    document.body.appendChild(h1);

    // 2. Список ul с тремя элементами
    const ul = document.createElement('ul');
    ['Элемент 1', 'Элемент 2', 'Элемент 3'].forEach(text => {
        const li = document.createElement('li');
        li.textContent = text;
        ul.appendChild(li);
    });
    document.body.appendChild(ul);

    // 3. Кнопка
    const button = document.createElement('button');
    button.textContent = 'Добавить / удалить элемент';
    document.body.appendChild(button);

    // 4. Логика чередования
    let counter = 4;       // для новых элементов
    let addNext = true;    // true = добавить, false = удалить

    button.addEventListener('click', () => {
        if (addNext) {
            // Добавляем новый элемент
            const li = document.createElement('li');
            li.textContent = `Элемент ${counter++}`;
            ul.appendChild(li);
        } else {
            // Удаляем последний, если есть
            if (ul.lastElementChild) {
                ul.lastElementChild.remove();
            }
        }
        addNext = !addNext; // чередование
    });
});