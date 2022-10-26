#include <iostream>
#include <string>

class State {
protected:
    std::string stateType;
public:
    std::string getStateType() {
        return this->stateType;
    }
    virtual void handle()=0;
    virtual ~State() {}
};

class Waiting: public State {
public:
    Waiting() {
        this->stateType = "Waiting";
    }
    void handle() {
        std::cout << "Ожидание" << std::endl;
    }
};

class Call: public State {
public:
    Call() {
        this->stateType = "Call";
    }
    void handle() {
        std::cout << "Звонок" << std::endl;
    }
};

class Conversation: public State {
public:
    Conversation() {
        this->stateType = "Conversation";
    }
    void handle() {
        std::cout << "Разговор" << std::endl;
    }
};

class NegativeBalance: public State {
public:
    NegativeBalance() {
        this->stateType = "NegativeBalance";
    }
    void handle() {
        std::cout << "Отрицательный баланс!" << std::endl;
    }
};

class StateContext {
private:
    State *state;
    void clearState() {
        delete this->state;
    }
public:
    StateContext() {
        this->state = new Waiting();
    }
    State* getState() {
        return this->state;
    }
    void setState(State *state) {
        if (state != nullptr) {
            this->clearState();
            this->state = state;
        }
    }
    void handleCurrentState() {
        this->state->handle();
    }
    ~StateContext() {
        delete this->state;
    }
};

class Phone {
private:
    std::string phoneNumber;
    double balance;
    StateContext *stateCtx;
public:
    Phone(std::string phoneNumber) {
        this->balance = 100.0;
        this->phoneNumber = phoneNumber; 
        this->stateCtx = new StateContext();
        this->stateCtx->handleCurrentState();
    }
    ~Phone() {
        delete this->stateCtx;
    }

    void call() {
        if (this->stateCtx->getState()->getStateType() != "NegativeBalance") {
            this->balance -= 15.0;
            this->stateCtx->setState(new Call());
        } else {
            this->stateCtx->setState(new NegativeBalance());
        }
        this->stateCtx->handleCurrentState();
    }
    void answerCall() {
        if (this->stateCtx->getState()->getStateType() != "Conversation" || this->stateCtx->getState()->getStateType() != "Call") {
            this->stateCtx->setState(new Conversation());
            this->stateCtx->handleCurrentState();
        } else {
            std::cout << "Абонент разговаривает" << std::endl;
        }
    }
    void endCall() {
        if (this->stateCtx->getState()->getStateType() == "Conversation"  || this->stateCtx->getState()->getStateType() == "Call") {
            if (this->balance <= 0) {
                this->stateCtx->setState(new NegativeBalance());
            } else {
                this->stateCtx->setState(new Waiting());
            }
        }
        this->stateCtx->handleCurrentState();
    }
    void addMoneyToBalance(double moneyAmount) {
        if (moneyAmount > 0) {
            this->balance += moneyAmount;
            if (this->stateCtx->getState()->getStateType() == "NegativeBalance") {
                this->stateCtx->setState(new Waiting());
            }
        }
        this->stateCtx->handleCurrentState();
    }


};

void test() {
    auto phone = new Phone("123456789");
    phone->call();
    phone->answerCall();
    phone->endCall();
    delete phone;
}

int main() {   
    auto phone = new Phone("123456789");
    phone->call();
    phone->answerCall();
    phone->endCall();
    delete phone;

    return 0;
}


