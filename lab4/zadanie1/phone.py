import context
import states

class Phone:
    __phoneNumber: str
    __balance: float
    def __init__(self, phoneNumber: str) -> None:
        self.__context = context.Context()
        self.__context.setState(states.Waiting())
        self.__context.handleCurrentState()
        self.__balance = 100.0
        self.__phoneNumber = phoneNumber


    def call(self) -> None:
        if self.__context.getState().getStateType() != "NegativeBalance":
            self.__balance -= 15.0;
            self.__context.setState(states.Call())
        else:
            self.__context.setState(states.NegativeBalance())
        self.__context.handleCurrentState()


    def answerCall(self) -> None:
        if (self.__context.getState().getStateType() != "Conversation" or self.__context.getState.getStateType() != "Call"):
            self.__context.setState(states.Conversation())
            self.__context.handleCurrentState()
        else:
            print("Абонент разговаривает")

    def endCall(self) -> None:
        if self.__context.getState().getStateType() == "Conversation" or self.__context.getState().getStateType() == "Call":
            if self.__balance <= 0:
                self.__context.setState(states.NegativeBalance())
            else:
                self.__context.setState(states.Waiting())
        self.__context.handleCurrentState()

    def addMoneyToBalance(self, moneyAmount: float) -> None:
        if moneyAmount > 0:
            self.__balance += moneyAmount
            if self.__context.getState().getStateType() == "NegativeBalance":
                self.__context.setState(states.Waiting())

        self.__context.handleCurrentState()

if __name__ == "__main__":
    phone = Phone('123')
    phone.call()
    phone.answerCall()
    phone.endCall()


        