#include "zadanie1.h"

// Вариант 12

class BallonOfGas {
private:
    double Volume;
    double Mass;
    double Molar;
public: 
    BallonOfGas(double Volume, double Mass, double Molar) {
        this->Volume = Volume;
        this->Mass = Mass;
        this->Molar = Molar;
    }
    double getVolume() {
        return this->Volume;
    }
    void setVolume(double value) {
        this->Volume = value;
    }
    double GetPressure(int T) {
        return this->Volume / (this->AmountOfMatter() * T * 8.314462);
    }
    double AmountOfMatter() {
        return this->Mass / this->Molar;
    }
    std::string ToString() {
        return "Масса:" +  std::to_string(this->Mass) + " Объем:" 
            + std::to_string(this->Volume) + " Мол. масса:" + std::to_string(this->Molar);
    }

};

class RequiredInterface {
public:
    virtual void ModifyVolume(double dV)=0;
    virtual double GetDp(int T0, int T1)=0;
    virtual std::string Passport()=0;
};

class BallonInterfaceAdapter: public RequiredInterface {
private:
    BallonOfGas *ballon;
public:
    BallonInterfaceAdapter(BallonOfGas *ballon) {
        this->ballon = ballon;
    }
    void ModifyVolume(double dV) {
        this->ballon->setVolume(this->ballon->getVolume() + dV);
    }
    double GetDp(int T0, int T1) {
        return this->ballon->GetPressure(T1) - this->ballon->GetPressure(T0);
    }

    std::string Passport() {
        return this->ballon->ToString();
    }
};



