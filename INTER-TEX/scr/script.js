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

// Изменение текста элемента на странице
document.getElementById("rating-message").innerText = `Общий рейтинг сайта: ${message}`;