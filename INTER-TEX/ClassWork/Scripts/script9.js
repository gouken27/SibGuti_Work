const car = {
    brand: "Mazda",
    model: "RX-7",
    year: 1993, // Год выпуска, используем для расчета возраста
    color: "Красный",

    // Метод, выводящий информацию о машине
    getInfo() {
        console.log(`\n--- Информация об объекте Car ---`);
        console.log(`Автомобиль: ${this.brand} ${this.model} (${this.year}), Цвет: ${this.color}.`);
    },

    // 2. Добавить геттер и сеттер age
    
    // Геттер: рассчитывает возраст машины
    get age() {
        // Получаем текущий год
        const currentYear = new Date().getFullYear();
        return currentYear - this.year;
    },

    // Сеттер: устанавливает год выпуска на основе заданного возраста
    set age(newAge) {
        if (typeof newAge === 'number' && newAge >= 0) {
            const currentYear = new Date().getFullYear();
            this.year = currentYear - newAge;
            console.log(`[Set Age]: Год выпуска обновлен на ${this.year} (возраст ${newAge} лет).`);
        } else {
            console.error("[Set Age Error]: Возраст должен быть положительным числом.");
        }
    }
};

// Проверка объекта car, геттера и сеттера
car.getInfo();
console.log(`Возраст машины (Геттер age): ${car.age} лет.`); 

// Используем сеттер для изменения года выпуска
car.age = 5; 
car.getInfo(); 

// --- 3. Создать коллекцию Map для хранения пользователей и 4. Добавить метод в User.prototype ---

// Функция-конструктор User
function User(username, birthYear) {
    this.username = username;
    this.birthYear = birthYear;
    // Свойство, которое будет обновляться
    this.age = new Date().getFullYear() - birthYear; 
}

// Добавление метода increaseAge() в прототип User
User.prototype.increaseAge = function() {
    this.age += 1;
    this.birthYear -= 1; // Обновляем год рождения для соответствия
    console.log(`[${this.username}]: Возраст увеличен до ${this.age}.`);
};

// Создание экземпляров пользователей
const userA = new User("Акира", 2000);
const userB = new User("Нана", 1998);
const userC = new User("Кенджи", 2005);

// Создание коллекции Map
const userMap = new Map();

// Добавление пользователей в Map, где ключ - ID или имя
userMap.set("akira_id", userA);
userMap.set("nana_id", userB);
userMap.set("kenji_id", userC);

console.log(`\n--- Коллекция Map и Прототип User ---`);
console.log(`Размер коллекции Map: ${userMap.size}`);

// Вывод и использование метода прототипа
console.log(`\nИсходный возраст userA: ${userA.age}`);
userA.increaseAge(); // Вызов метода прототипа
userB.increaseAge();

// Вывод всех элементов Map
console.log(`\nСодержимое Map после изменений:`);
userMap.forEach((user, key) => {
    console.log(`Ключ: ${key}, Имя: ${user.username}, Текущий возраст: ${user.age}`);
});