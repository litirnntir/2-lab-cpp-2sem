#include <iostream>
#include <cmath>

using namespace std;

int checkNumber() {
    int n;
    char answer[256];
    fgets(answer, sizeof(answer), stdin);
    while (sscanf(answer, "%d", &n) != 1) {
        printf("Incorrect input. Try again:");
        fgets(answer, sizeof(answer), stdin);
    }
    return n;
}

double checkDouble() {
    double n;
    while (!(cin >> n) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Incorrect input. Try again:";
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

    Point() {

    }

    int getX() {
        return this->x;
    }

    int getY() {
        return this->y;
    }

    double getFi() {
        return this->fi;
    }

    double getR() {
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
        cout << newFi << " " << newR << endl;
        return {newFi, newR};
    }

    Point movingY(int newY) {
        return {this->x, this->y + newY};
    }

    Point movingX(int newX) {
        return {this->x + newX, this->y};
    }

    double distanceToOrigin() {
        return sqrt(pow(this->x, 2) + pow(this->y, 2));
    }

    double distanceToAnotherPoint(Point point) {
        return sqrt(pow(this->x - point.x, 2) + pow(this->y - point.y, 2));
    }

    Point toPolar() {
        return {atan((float) y / (float) x), sqrt(pow(x, 2) + pow(y, 2))};
    }

    Point fromPolar() {
        return {r * cos(fi), r * sin(fi)};
    }

    bool equals(Point another) {
        return (this->x == another.x) && (this->y == another.y);
    }

    void printPoint() {
        cout << "Point{" << endl << "x = " << x << "\ny = " << y << endl << "}" << endl;
    }
    void printPolarPoint() {
        cout << "Point{" << endl << "fi = " << fi << "\nr = " << r << endl << "}" << endl;
    }
};

class Menu {
public:
    static int checkNumber() {
        int n;
        char answer[256];
        fgets(answer, sizeof(answer), stdin);
        while (sscanf(answer, "%d", &n) != 1) {
            printf("Incorrect input. Try again: ");
            fgets(answer, sizeof(answer), stdin);
        }
        return n;
    }

    static void mainMenu() {
        bool menu = true;
        while (menu) {
            cout << "LR N2" << endl << "what u want?" << endl << "1) moving along the axis X" << endl
                 << "2) moving along the axis Y" << endl << "3) distance to the origin" << endl <<
                 "4) distance between 2 points" << endl <<
                 "5) transformations to polar coordinates" << endl <<
                 "6) transformations from polar coordinates" << endl <<
                 "7) equality check" << endl <<
                 "8) exit" << endl <<
                 "Enter the number to continue" << endl;
            switch (checkNumber()) {
                case 1: {
                    Point point = Point::initPoint();
                    cout << "how much do you want to move?" << endl;
                    int newX = checkNumber();
                    point = point.movingX(newX);
                    point.printPoint();
                    break;
                }
                case 2: {
                    Point point = Point::initPoint();
                    cout << "how much do you want to move?" << endl;
                    int newY = checkNumber();
                    point = point.movingY(newY);
                    point.printPoint();
                    break;
                }
                case 3: {
                    Point point = Point::initPoint();
                    cout << "distance is: " << point.distanceToOrigin() << endl;
                    break;
                }
                case 4: {
                    Point point = Point::initPoint();
                    cout << "Enter x for second point: " << endl;
                    int newX = checkNumber();
                    cout << "Enter x for second point: " << endl;
                    int newY = checkNumber();
                    cout << "distance is: " << point.distanceToAnotherPoint({newX, newY});
                    break;
                }
                case 5: {
                    Point point = Point::initPoint();
                    point.printPolarPoint();
                    break;
                }
                case 6: {
                    Point point = Point::initPointPolar();
                    cout << "point: x = " << point.fromPolar().getFi() << ", y = " << point.fromPolar().getR() << endl;
                    break;
                }
                case 7: {
                    Point point = Point::initPoint();
                    cout << "for another point" << endl;
                    Point anotherPoint = Point::initPoint();
                    cout << "Points are " << (point.equals(anotherPoint) ? "equals" : "not equals") << endl;
                    break;
                }
                case 8: {
                    cout << "r u sure?\n1) yes\n2)no" << endl;
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
                            cout << "Incorrect! Thy again: " << endl;
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