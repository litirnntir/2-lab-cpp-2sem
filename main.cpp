#include <iostream>
#include <cmath>

using namespace std;

int checkNumber() {
    int n;
    char answer[256];
    fgets(answer, sizeof(answer), stdin);
    while (sscanf(answer, "%d", &n) != 1) {
        printf("Некорректный ввод, попробуйте еще раз: ");
        fgets(answer, sizeof(answer), stdin);
    }
    return n;
}

double checkDouble() {
    double n;
    while (!(cin >> n) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Некорректный ввод, попробуйте еще раз: ";
    }
    return n;
}

class Point {

private:
    int x;
    int y;
    double fi;
    double r;

public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Point(double fi, double r) {
        this->fi = fi;
        this->r = r;
    }

    Point() = default;

    int getX() {
        return this->x;
    }

    int getY() {
        return this->y;
    }

    double getFi() const {
        return this->fi;
    }

    double getR() const {
        return this->r;
    }

    static Point initPoint() {
        cout << "Enter x:";
        const int newX = checkNumber();
        cout << "Enter y:";
        const int newY = checkNumber();
        return {newX, newY};
    }

    static Point initPointPolar() {
        cout << "Enter fi:";
        const double newFi = checkDouble();
        cout << "Enter R:";
        const double newR = checkDouble();
        return {newFi, newR};
    }

    Point movingY(int newY) const {
        return {this->x, this->y + newY};
    }

    Point movingX(int newX) const {
        return {this->x + newX, this->y};
    }

    double distanceToOrigin() const {
        return sqrt(pow(this->x, 2) + pow(this->y, 2));
    }

    double distanceToAnotherPoint(Point point) const {
        return sqrt(pow(this->x - point.x, 2) + pow(this->y - point.y, 2));
    }

    Point toPolar() const {
        return {atan((float) y / (float) x), sqrt(pow(x, 2) + pow(y, 2))};
    }

    Point fromPolar() const {
        return {r * cos(fi), r * sin(fi)};
    }

    bool equals(Point another) const {
        return (this->x == another.x) && (this->y == another.y);
    }

    void printPoint() const {
        cout << "Point{" << endl << "x = " << x << "\ny = " << y << endl << "}" << endl;
    }

    void printPolarPoint() const {
        cout << "Point{" << endl << "fi = " << fi << "\nr = " << r << endl << "}" << endl;
    }
};

class Menu {
public:
    static void mainMenu() {
        bool menu = true;
        while (menu) {
            cout << "Лаборная работа 2. Вариант 12" << endl << "1) Перемещение по оси X" << endl
                 << "2) Перемещение по оси Y" << endl << "3) Расстояние до начала координат" << endl <<
                 "4) Расстояние между двумя точками" << endl <<
                 "5) Преобразование в полярные координаты" << endl <<
                 "6) Преобразование из полярных координат" << endl <<
                 "7) Проверка на равенство" << endl <<
                 "8) ВЫХОД" << endl <<
                 "Введите цифру для продолжения: " << endl;
            switch (checkNumber()) {
                case 1: {
                    Point point = Point::initPoint();
                    cout << "Введите расстояние, на которое нужно переместить точку: " << endl;
                    int newX = checkNumber();
                    point = point.movingX(newX);
                    point.printPoint();
                    break;
                }
                case 2: {
                    Point point = Point::initPoint();
                    cout << "Введите расстояние, на которое нужно переместить точку: " << endl;
                    int newY = checkNumber();
                    point = point.movingY(newY);
                    point.printPoint();
                    break;
                }
                case 3: {
                    Point point = Point::initPoint();
                    cout << "Расстояние до начала координат: " << point.distanceToOrigin() << endl;
                    break;
                }
                case 4: {
                    Point point = Point::initPoint();
                    cout << "Введите x для второй точки: " << endl;
                    int newX = checkNumber();
                    cout << "Введите y для второй точки: " << endl;
                    int newY = checkNumber();
                    cout << "Расстояние до точки: " << point.distanceToAnotherPoint({newX, newY}) << endl;
                    break;
                }
                case 5: {
                    Point point = Point::initPoint();
                    point.toPolar().printPolarPoint();
                    break;
                }
                case 6: {
                    Point point = Point::initPointPolar();
                    cout << "точка: x = " << point.fromPolar().getFi() << ", y = " << point.fromPolar().getR() << endl;
                    break;
                }
                case 7: {
                    Point point = Point::initPoint();
                    cout << "Для второй точки: " << endl;
                    Point anotherPoint = Point::initPoint();
                    cout << "Точки " << (point.equals(anotherPoint) ? "равны" : "не равны") << endl;
                    break;
                }
                case 8: {
                    cout << "Вы действительно хотите выйти?\n1) да\n2)нет" << endl;
                    bool innerMenu = true;
                    while (innerMenu) {
                        int choose = checkNumber();
                        if (choose == 1) {
                            menu = false;
                            innerMenu = false;
                        } else if (choose == 2) {
                            menu = true;
                            innerMenu = false;
                        } else {
                            cout << "Некорректный ввод, попробуйте еще раз: " << endl;
                        }
                    }
                    break;
                }
                default: {
                    break;
                }
            }
        }
    }
};


int main() {
    Menu::mainMenu();
    return 0;
}