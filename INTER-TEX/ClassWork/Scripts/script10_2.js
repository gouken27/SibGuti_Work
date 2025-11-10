const assert = require('assert');
const { add, subtract, multiply, divide } = require('./script10_1');

console.log('Запуск тестов калькулятора...\n');

try {
    assert.strictEqual(add(5, 3), 8);
    assert.strictEqual(add(-5, 10), 5);
    assert.strictEqual(add(0, 100), 100);
    console.log('add(): Все тесты пройдены');
} catch (e) { console.error('add(): ОШИБКА →', e.message); }

try {
    assert.strictEqual(subtract(20, 10), 10);
    assert.strictEqual(subtract(5, 50), -45);
    assert.strictEqual(subtract(0, 7), -7);
    console.log('subtract(): Все тесты пройдены');
} catch (e) { console.error('subtract(): ОШИБКА →', e.message); }

try {
    assert.strictEqual(multiply(4, 7), 28);
    assert.strictEqual(multiply(15, 0), 0);
    assert.strictEqual(multiply(-4, 5), -20);
    console.log('multiply(): Все тесты пройдены');
} catch (e) { console.error('multiply(): ОШИБКА →', e.message); }

try {
    assert.strictEqual(divide(10, 2), 5);
    assert.strictEqual(divide(7, 3), 7/3);
    let threw = false;
    try { divide(10, 0); } catch (e) { threw = true; }
    if (!threw) throw new Error('Не выбросило ошибку при делении на 0');
    console.log('divide(): Все тесты пройдены');
} catch (e) { console.error('divide(): ОШИБКА →', e.message); }

console.log('\nВСЕ ТЕСТЫ ЗАВЕРШЕНЫ!');