// тесты

// Импортируем assert из Chai
const assert = require('chai').assert; 
// Импортируем модуль с функциями калькулятора
const calculator = require('./script10_1');
// --- Набор тестов для Калькулятора ---
describe('Тестирование модуля calculator', function() {
    
    // --- Тесты для функции ADD (Сложение) ---
    describe('Функция add()', function() {
        // Проверка корректного результата для положительных чисел
        it('должна корректно складывать 5 и 3, возвращая 8', function() {
            assert.equal(calculator.add(5, 3), 8);
        });
        
        // Проверка с отрицательными числами
        it('должна корректно складывать -5 и 10, возвращая 5', function() {
            assert.equal(calculator.add(-5, 10), 5);
        });

        // Проверка с нулем
        it('должна корректно складывать 0 и 100, возвращая 100', function() {
            assert.equal(calculator.add(0, 100), 100);
        });
    });

    // --- Тесты для функции SUBTRACT (Вычитание) ---
    describe('Функция subtract()', function() {
        // Проверка корректного результата
        it('должна корректно вычитать 10 из 20, возвращая 10', function() {
            assert.equal(calculator.subtract(20, 10), 10);
        });
        
        // Проверка отрицательного результата
        it('должна корректно вычитать 50 из 5, возвращая -45', function() {
            assert.equal(calculator.subtract(5, 50), -45);
        });
    });

    // --- Тесты для функции MULTIPLY (Умножение) ---
    describe('Функция multiply()', function() {
        // Проверка корректного результата
        it('должна корректно умножать 4 на 7, возвращая 28', function() {
            assert.equal(calculator.multiply(4, 7), 28);
        });
        
        // Проверка умножения на ноль
        it('должна возвращать 0 при умножении на ноль (15 * 0)', function() {
            assert.equal(calculator.multiply(15, 0), 0);
        });
    });

    // --- Тесты для функции DIVIDE (Деление) ---
    describe('Функция divide()', function() {
        // Проверка корректного результата
        it('должна корректно делить 10 на 2, возвращая 5', function() {
            assert.equal(calculator.divide(10, 2), 5);
        });

        // Проверка на выброс ошибки при делении на ноль
        it('должна выбрасывать ошибку при делении на ноль', function() {
            // Chai использует функцию assert.throw() для проверки ошибок
            assert.throw(() => calculator.divide(10, 0), Error, "Ошибка: Деление на ноль невозможно.");
        });
    });
});