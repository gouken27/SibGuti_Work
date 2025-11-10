// 1. Создание переменных
const name = "Уютное Кафе «Флэт Уайт»";
const averageBill = 780; // Средний чек в рублях
let hasDelivery = true; // Наличие доставки

// Вывод информации о кафе в консоль одной строкой
console.log(`\n--- Информация о Кафе ---`);
console.log(`Кафе "${name}", средний чек: ${averageBill}₽, доставка: ${hasDelivery ? 'есть' : 'нет'}.`);

// ---

// 2. Работа с условиями (if...else) на основе averageBill
console.log(`\n--- Оценка Цены ---`);

if (averageBill < 600) {
    console.log("Категория: Бюджетное.");
} else if (averageBill >= 600 && averageBill <= 1000) {
    console.log("Категория: Средний уровень.");
} else { // averageBill > 1000
    console.log("Категория: Премиум.");
}

// ---

// 3. Создание массива orders и вычисление суммы заказов > 300 с помощью цикла for
const orders = [120, 950, 450, 200, 310, 890, 150];
let totalHighOrders = 0; // Накопитель для суммы

console.log(`\n--- Обработка Заказов ---`);
console.log(`Массив заказов: [${orders.join(', ')}]`);

// Цикл for для перебора массива
for (let i = 0; i < orders.length; i++) {
    // Проверка условия
    if (orders[i] > 300) {
        totalHighOrders += orders[i]; // Добавление к сумме, если > 300
    }
}

console.log(`Сумма заказов, превышающих 300₽: ${totalHighOrders}₽`);

// ---

// 4. Работа с методами массивов (push, удаление первого элемента)
let menuItems = ["кофе", "чай", "капучино", "десерт"];

console.log(`\n--- Работа с Меню ---`);
console.log(`Исходное меню: [${menuItems.join(', ')}]`);

// Добавление элемента в конец с помощью push()
menuItems.push("сэндвич");
console.log(`После push("сэндвич"): [${menuItems.join(', ')}]`);

// Удаление первого элемента с помощью shift()
const removedItem = menuItems.shift();
console.log(`Удален первый элемент (shift()): ${removedItem}`);
console.log(`Финальное меню: [${menuItems.join(', ')}]`);

// ---

// 5. Создание и использование функции calcDiscount(price)
console.log(`\n--- Расчет Скидок ---`);

/*  */
function calcDiscount(price) {
    const discountRate = 0.10; // 10% скидка
    const finalPrice = price * (1 - discountRate);
    return finalPrice.toFixed(2); // Округляем до двух знаков
}

const originalPrice = 1500;
const finalPrice = calcDiscount(originalPrice);

console.log(`Исходная цена: ${originalPrice}₽`);
console.log(`Цена со скидкой 10%: ${finalPrice}₽`);