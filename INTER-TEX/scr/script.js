/* Блок 11: Переключатель темы и localStorage */

document.addEventListener('DOMContentLoaded', () => {
    const themeToggleButton = document.getElementById('theme-toggle');
    const body = document.body;
    
    // --- Шаг 1: Применение сохраненной темы при загрузке ---
    const savedTheme = localStorage.getItem('theme');
    
    if (savedTheme === 'dark') {
        body.classList.add('dark');
        themeToggleButton.textContent = 'Сменить тему (Темная)';
    } else {
        // Устанавливаем светлую тему по умолчанию, если ничего не сохранено
        body.classList.remove('dark');
        themeToggleButton.textContent = 'Сменить тему (Светлая)';
    }

    // --- Шаг 2: Обработчик клика для переключения темы ---
    themeToggleButton.addEventListener('click', () => {
        // Переключаем класс .dark на <body>
        body.classList.toggle('dark');
        
        let currentTheme;
        
        if (body.classList.contains('dark')) {
            currentTheme = 'dark';
            themeToggleButton.textContent = 'Сменить тему (Темная)';
        } else {
            currentTheme = 'light';
            themeToggleButton.textContent = 'Сменить тему (Светлая)';
        }
        
        // --- Шаг 3: Сохранение выбранной темы в localStorage ---
        localStorage.setItem('theme', currentTheme);
        console.log(`Тема сохранена в localStorage: ${currentTheme}`);
    });
});

/* Блок 8: Массивы и Условия */

// 1. Проверка подключения JS
console.log("JavaScript подключен");

// 2. Работа с массивами
let animeList = ["Re:Zero", "Naruto", "One Piece", "Death Note", "Steins;Gate"];
animeList.push("Fullmetal Alchemist");
console.log("Обновленный список аниме:", animeList);

// Фильтрация элементов длиной >5 и приведение к верхнему регистру
let longAnime = animeList.filter(item => item.length > 5);
let upperLongAnime = longAnime.map(item => item.toUpperCase());
console.log("Элементы длиной >5 в верхнем регистре:", upperLongAnime);

// 3. Работа с условиями и изменение текста на странице
let rating = 8;
let message;
if (rating > 7) {
    message = "Отлично";
} else {
    message = "Можно лучше";
}

// Изменение текста элемента на странице (убедитесь, что элемент с ID "rating-message" есть в HTML)
if (document.getElementById("rating-message")) {
    document.getElementById("rating-message").innerText = `Общий рейтинг сайта: ${message}`;
} else {
    console.warn('Элемент с ID "rating-message" не найден в DOM.');
}


/* Блок 9: Объекты, Конструкторы и Коллекции */

console.log("\n--- Задачи Блока 9: Объекты и ООП ---");

// --- 1. Создать объект по теме сайта: Anime с мин. 3 свойствами и 1 методом ---
const favoriteAnime = {
    title: "Re:Zero - Starting Life in Another World",
    genre: "Isekai/Fantasy",
    episodes: 76, // Общее число эпизодов (3 сезона + OVA)
    
    // Метод, выводящий информацию об объекте
    showDetails() {
        console.log(`Объект Аниме: "${this.title}" (${this.genre}), всего эпизодов: ${this.episodes}.`);
    },

    // --- 2. Добавить геттер и сеттер ---
    // Геттер для вычисляемого значения: статус завершенности (если > 70 эпизодов, считаем 'Продолжается')
    get status() {
        if (this.episodes >= 70) {
            return "Продолжается (высокий статус)";
        } else if (this.episodes > 0) {
            return "Завершен/В процессе";
        } else {
            return "Неизвестно";
        }
    },

    // Сеттер для контроля изменения названия
    set title(newTitle) {
        if (typeof newTitle === 'string' && newTitle.length > 2) {
            this._title = newTitle; // Сохраняем во внутреннее свойство
        } else {
            console.error("Ошибка: Название должно быть корректной строкой.");
        }
    },
    // Дополнительное свойство, куда геттер/сеттер будут сохранять данные
    _title: "Re:Zero - Starting Life in Another World" 
};

// Проверка объекта, геттера и сеттера
favoriteAnime.showDetails();
console.log(`Статус (Геттер): ${favoriteAnime.status}`); 

// Проверка сеттера (изменение)
favoriteAnime.title = "Re:Zero 2.0";
console.log(`Новое название после сеттера: ${favoriteAnime._title}`); 
favoriteAnime.title = "А"; // Проверка ошибки сеттера

// --- 3. Создать функцию-конструктор и 4. Добавить метод в прототип ---
function AnimeEntry(title, year, rating) {
    this.title = title;
    this.year = year;
    this.rating = rating;
}

// Добавление метода в прототип
AnimeEntry.prototype.getShortInfo = function() {
    return `${this.title} (${this.year}) - Рейтинг: ${this.rating}`;
};

// Создание объектов через конструктор
const entry1 = new AnimeEntry("Steins;Gate", 2011, 9.1);
const entry2 = new AnimeEntry("Chainsaw Man", 2022, 8.5);

console.log(`\nИнформация из прототипа: ${entry1.getShortInfo()}`);
console.log(`Информация из прототипа: ${entry2.getShortInfo()}`);


// --- 5. Создать коллекцию Map или Set и вывести все элементы ---

// Используем Set для хранения уникальных объектов аниме
const animeCollection = new Set(); 

animeCollection.add(entry1);
animeCollection.add(entry2);
animeCollection.add(new AnimeEntry("Attack on Titan", 2013, 9.0));
animeCollection.add(favoriteAnime); // Добавляем ранее созданный объект

console.log(`\n--- Вывод элементов коллекции Set ---`);
animeCollection.forEach((item) => {
    // Проверяем, есть ли у объекта метод getShortInfo
    if (item.getShortInfo) { 
        console.log(`[Конструктор]: ${item.getShortInfo()}`);
    } else {
        console.log(`[Объект]: ${item.title}`);
    }
});