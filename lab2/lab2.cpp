#include "vector"
#include <iostream>
#include <random>


/*

Вариант 12

Задание:

Вариант №3, 6, 9, 12, 15, 18, 21, 24
Паттерн Factory Method. Фигуры игры «тетрис». 
Реализовать процесс случайного выбора фигуры из конечного набора фигур. 
Предусмотреть появле-ние супер-фигур с большим числом клеток, чем обычные.

Развертка изображения


|---------------------->x
|
|
|
T y

*/

class Figure {
public:
    virtual void show()=0;
};

class Square: public Figure {
private:
    int startX;
    int startY;
    int maxX;
    int maxY;

public:
    Square(int startX, int startY, int maxX, int maxY) {
        this->startX = startX;
        this->startY = startY;
        this->maxX = maxX;
        this->maxY = maxY;
    }
    void show() {
        std::cout << std::endl << "Square" << std::endl;
        for (int y=0; y < this->maxY; y++) {
            for (int x=0; x < this->maxX; x++) {
                if (y >= this->startY && y <= this->startY +1 
                    && x >= this->startX && x <= this->startX +1 ) {
                        std::cout << 1;
                }
                else {
                    std::cout << 0;
                }
            }
            std::cout << std::endl;
        }
    }
};

class HLine: public Figure {
    private:
    int startX;
    int startY;
    int maxX;
    int maxY;

public:
    HLine(int startX, int startY, int maxX, int maxY) {
        this->startX = startX;
        this->startY = startY;
        this->maxX = maxX;
        this->maxY = maxY;
    }
    void show() {
        std::cout << std::endl << "Horizontal Line" << std::endl;
        for (int y=0; y < this->maxY; y++) {
            for (int x=0; x < this->maxX; x++) {
                if (y == this->startY  
                    && x >= this->startX && x <= this->startX + 3 ) {
                        std::cout << 1;
                }
                else {
                    std::cout << 0;
                }
            }
            std::cout << std::endl;
        }
    }
};

class VLine: public Figure {
    private:
    int startX;
    int startY;
    int maxX;
    int maxY;

public:
    VLine(int startX, int startY, int maxX, int maxY) {
        this->startX = startX;
        this->startY = startY;
        this->maxX = maxX;
        this->maxY = maxY;
    }
    void show() {
        std::cout << std::endl << "Vertical Line" << std::endl;
        for (int y=0; y < this->maxY; y++) {
            for (int x=0; x < this->maxX; x++) {
                if (y >= this->startY && y <= this->startY + 3  
                    && x == this->startX ) {
                        std::cout << 1;
                }
                else {
                    std::cout << 0;
                }
            }
            std::cout << std::endl;
        }
    }
};

class SuperVLine: public Figure {
    private:
    int startX;
    int startY;
    int maxX;
    int maxY;

public:
    SuperVLine(int startX, int startY, int maxX, int maxY) {
        this->startX = startX;
        this->startY = startY;
        this->maxX = maxX;
        this->maxY = maxY;
    }
    void show() {
        std::cout << std::endl << "Super Vertical Line" << std::endl;
        for (int y=0; y < this->maxY; y++) {
            for (int x=0; x < this->maxX; x++) {
                if (y >= this->startY && y <= this->startY + 3  
                    && x >= this->startX && x <= this->startX +1 ) {
                        std::cout << 1;
                }
                else {
                    std::cout << 0;
                }
            }
            std::cout << std::endl;
        }
    }
};

class FigureCreator {
public:
    virtual Figure* createFigure()=0;
};

class MyFigureCreator: public FigureCreator {
private:
    int startX;
    int startY;
    int maxX;
    int maxY;
public:
    MyFigureCreator(int startX, int startY, int maxX, int maxY) {
        this->startX = startX;
        this->startY = startY;
        this->maxX = maxX;
        this->maxY = maxY;
    }

    Figure* createFigure() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist4(1, 4);
        auto choice = dist4(rng);

        if (choice == 1) {
            return new Square(startX, startY, maxX, maxY);
        } else if (choice == 2) {
            return new HLine(startX, startY, maxX, maxY);
        } else if (choice == 3) {
            return new VLine(startX, startY, maxX, maxY);
        } else {
            return new SuperVLine(startX, startY, maxX, maxY);
        }
    }
};

int main() {
    auto creator = new MyFigureCreator(2, 1, 10, 8);
    auto figure1 = creator->createFigure();
    auto figure2 = creator->createFigure();


    figure1->show();
    figure2->show();

    delete figure1;
    delete figure2;
    delete creator;

    return 0;
}
