#include "zadanie3.h"

class ApplicationConsoleClient {
public:
    virtual void launchSubprocess()=0;
};

class ApplicationFactory {
public:
    virtual void launchProcess()=0;
};


class Zadanie1ConsoleClient: public ApplicationConsoleClient {
public:
    void launchSubprocess() {
        auto ballon = new BallonOfGas(1, 1, 1);
        auto calculationInterface = new BallonInterfaceAdapter(ballon);

        std::cout << "Баллон " << std::endl;
        std::cout << "Количество вещества: " << ballon->AmountOfMatter() << std::endl;
        std::cout << "Давление: " << ballon->GetPressure(2) << std::endl;
        std::cout << "Информация: " << ballon->ToString() << std::endl << std::endl;

        std::cout << "Интерфейс расчета" << std::endl;
        std::cout << "Паспорт: " << calculationInterface->Passport() << std::endl;
        std::cout << "Изменение(1) от Т0 до Т1:" << calculationInterface->GetDp(2, 1) << std::endl;
        calculationInterface->ModifyVolume(2);
        std::cout << "Изменение(2) от Т0 до Т1:" << calculationInterface->GetDp(2, 1) << std::endl;

        delete calculationInterface;
        delete ballon;
    }
};

class Zadanie2ConsoleClient: public ApplicationConsoleClient {
public:
    void launchSubprocess() {
        auto calculationFacade = new CalculationFacade();
        calculationFacade->process(1, 23, 2, 2013, 0.1, nullptr);
        delete calculationFacade;
    }
};

class MyApplicationFactory: public ApplicationFactory {
private:
    ApplicationConsoleClient *zadanie1 = new Zadanie1ConsoleClient();
    ApplicationConsoleClient *zadanie2 = new Zadanie2ConsoleClient();
public:
    void launchProcess() {
        int input;
        std::cout << "Выберите задание (1 или 2):"; 
        std::cin >> input;
        std::cout << std::endl;
        switch (input)
        {
        case 1:
            zadanie1->launchSubprocess();
            break;
        case 2:
            zadanie2->launchSubprocess();
            break;
        default:
            zadanie1->launchSubprocess();
            break;
        }
    }
    ~MyApplicationFactory() {
        delete this->zadanie1;
        delete this->zadanie2;
    }
};


