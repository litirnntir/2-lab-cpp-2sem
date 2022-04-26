#include <iostream>
#include <cmath>

// Описание класса комплексных чисел (объявление нового типа данных Complex)
class Complex {
public:
    // Поля класса (вещественная и мнимая части)
    double _re;
    double _im;
    // Метод класса (вычисление модуля комплексного числа)
    double abs() {
        return sqrt(_re * _re + _im * _im);
    } };
int main() {
    // Создаём первый экземпляр класса: 1 + i
    Complex c1;
    c1._re = 1;
    c1._im = 1;
    // Создаём второй экземпляр класса: 3 + 4 * i
    Complex c2;
    c2._re = 3;
    c2._im = 4;
    // Выводим их модули
    printf("%.2f\n", c1.abs()); // Выведет 1.41
    printf("%.2f\n", c2.abs()); // Выведет 5.00
}
