/*
Задача: создать интерактивную мини-программу «Проверка заказов кафе»
*/

// Функция для запуска всей программы и вывода результатов в HTML и консоль
function runProgram() {
    let output = document.getElementById('output');
    output.innerHTML = ''; // Очистка предыдущего вывода

    // 1. Создание переменных и вывод информации о кафе
    let name = "ВкусноБЕЗточки";
    let averageBill = 500;
    let hasDelivery = true;
    let deliveryText = hasDelivery ? "есть" : "нет";
    let cafeInfo = `Кафе ${name} средний чек ${averageBill}₽ доставка: ${deliveryText}`;
    console.log(cafeInfo);
    output.innerHTML += `<p>${cafeInfo}</p>`;

    // 2. Работа с условиями
    let level;
    if (averageBill < 500) {
        level = "Дешево и сердито";
    } else if (averageBill >= 500 && averageBill <= 1000) {
        level = "Средний уровень";
    } else {
        level = "Премиум кафе";
    }
    console.log(level);
    output.innerHTML += `<p>${level}</p>`;

    // 3. Массив orders и цикл for для суммы заказов > 300
    let orders = [120, 560, 310, 800, 250];
    let sumOver300 = 0;
    for (let i = 0; i < orders.length; i++) {
        if (orders[i] > 300) {
            sumOver300 += orders[i];
        }
    }
    let sumText = `Сумма заказов больше 300: ${sumOver300}₽`;
    console.log(sumText);
    output.innerHTML += `<p>${sumText}</p>`;

    // 4. Массив menu, добавление и удаление элементов
    let menu = ["кофе", "чай", "круассан", "сэндвич"];
    menu.push("десерт"); // Добавить в конец
    menu.shift(); // Удалить первый элемент
    let menuText = `Обновленное меню: ${menu.join(", ")}`;
    console.log(menuText);
    output.innerHTML += `<p>${menuText}</p>`;

    // 5. Функция calcDiscount и проверка
    function calcDiscount(price) {
        return price * 0.85; // Скидка 15%
    }
    let testPrices = [100, 500, 1000];
    let discountText = 'Скидки: ';
    for (let price of testPrices) {
        let discounted = calcDiscount(price);
        console.log(`Цена ${price} со скидкой: ${discounted}`);
        discountText += `Цена ${price} со скидкой: ${discounted}; `;
    }
    output.innerHTML += `<p>${discountText}</p>`;
}