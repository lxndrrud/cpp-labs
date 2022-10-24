#include <iostream>
#include <string>


class State {
public:
    virtual void handle()=0;
};

class Waiting: public State {
    void handle() {
        std::cout << "Ожидание" << std::endl;
    }
};

class Call: public State {
    void handle() {
        std::cout << "Звонок" << std::endl;
    }
};

class NegativeBalance: public State {
    void handle() {
        std::cout << "Отрицательный баланс!" << std::endl;
    }
};

