#include "zadanie2.h"


class Estate {
public:
    double monthCost;
    double squareCost;
    double liverCost;
    double yearCost;
    double stateCost;
};

class TownHouse: public Estate {
public:
    TownHouse() {
        this->monthCost = 100;
        this->squareCost = 50;
        this->liverCost = 200;
        this->yearCost = -100;
        this->stateCost = 100;
    }
};

class Cottage: public Estate {
public:
    Cottage() {
        this->monthCost = 200;
        this->squareCost = 100;
        this->liverCost = 400;
        this->yearCost = -100;
        this->stateCost = 200;
    }
};

class Appartment: public Estate {
public:
    Appartment() {
        this->monthCost = 200;
        this->squareCost = 40;
        this->liverCost = 1500;
        this->yearCost = -50;
        this->stateCost = 80;
    }
};

class EstateFactory {
public:
    Estate* getEstateInfo(int mode) {
        switch ((mode))
        {
        case 1:
            return new Appartment();
        case 2:
            return new TownHouse();
        case 3:
            return new Cottage();
        default:
            return new Appartment();
        }
    }
};

class CalculationFacade {
private:
    Estate *selectedEstate = nullptr;
    EstateFactory *estateFactory = new EstateFactory();

    void selectEstateTypeConsole() {
        int input;
        std::cout << "Введите тип недвижимости: 1-Квартира, 2-Дом в городе, 3-Коттедж"  << std::endl;
        std::cin >> input;
        this->selectedEstate = this->estateFactory->getEstateInfo(input);
    }

    void selectEstateType(int mode) {
        this->selectedEstate = this->estateFactory->getEstateInfo(mode);
    }

    double calcucateCost(
    int monthsToLive,
    double square,
    int livers,
    int yearOfBuilding,
    double stateOfBuilding) {
        return (this->selectedEstate->monthCost * monthsToLive + this->selectedEstate->squareCost * square + 
            this->selectedEstate->liverCost * livers - this->selectedEstate->yearCost * yearOfBuilding - 
            stateOfBuilding * this->selectedEstate->stateCost);  
    }

public: 
    void process(
    int monthsToLive,
    double square,
    int livers,
    int yearOfBuilding,
    double stateOfBuilding,
    int* estateType) {
        if (estateType != nullptr) {
            this->selectEstateType((*estateType));
        } else {
            this->selectEstateTypeConsole();
        }
        std::cout<< "Результат: " << this->calcucateCost(
            monthsToLive,
            square,
            livers,
            yearOfBuilding,
            stateOfBuilding) << " у.е." << std::endl;
    }
};
