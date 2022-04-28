#include <iostream>
#include <cmath>


/* Класс точка на плоскости
Хранятся декартовы координаты. Реализовать следующий функционал:
 Перемещение по оси X
 Перемещение по оси Y
 Определение расстояния до начала координат
 Определение расстояния до произвольной точки
 Преобразование в полярные координаты и из полярных координат
 Проверка на равенство */


// Описание класса точка

class Point {
private:
    double _x;
    double _y;
public:
    void set(int a, int b) {
        _x = a;
        _y = b;
    }

    double getX() {
        return _x;
    }
    double getY() {
        return _y;
    }

    void printPoint() {
        std::cout << "x = " << _x << " y = " << ' ' << _y << std::endl;
    }

    void distance(Point b) {
        std::cout << sqrt((b._x - this->_x) * (b._x - this->_x) + (b._y - this->_y) * (b._y - this->_y));
    }

    void distanceStart() {
        std::cout << sqrt((this->_x) * (this->_x) + (this->_y) * (this->_y));
    }
};

int main() {
    // Выводим их модули
    Point p1;
    p1.set(5, 4);
    p1.printPoint();
}
