import context
import states
from PySide6.QtCore import QObject, Signal

class Phone(QObject):
    # Logic properties
    __phoneNumber: str
    __balance: float

    # Signals
    indicateBalance = Signal(str)
    indicateCurrentState = Signal(str)
    addCurrentStateToList = Signal(str)

    def __init__(self, phoneNumber: str) -> None:
        super().__init__()
        self.__context = context.Context()
        self.__context.setState(states.Waiting())
        self.__balance = 100.0
        self.__phoneNumber = phoneNumber
        
    def initUIData(self):
        self.indicateBalance.emit(str(self.__balance))
        self.indicateCurrentState.emit(self.__context.handleCurrentState())


    def __showCurrentState(self):
        value_ = self.__context.handleCurrentState()
        self.indicateCurrentState.emit(value_)
        self.addCurrentStateToList.emit(value_)


    def call(self) -> None:
        if self.__context.getState().getStateType() == "Call":
            return
        if self.__context.getState().getStateType() != "NegativeBalance":
            self.__balance -= 15.0;
            self.indicateBalance.emit(str(self.__balance))
            self.__context.setState(states.Call())
        else:
            self.__context.setState(states.NegativeBalance())
        self.__showCurrentState()


    def answerCall(self) -> None:
        if (self.__context.getState().getStateType() != "Conversation" or self.__context.getState().getStateType() != "Call"):
            self.__context.setState(states.Conversation())
            self.__showCurrentState()
        else:
            print("Абонент разговаривает")

    def endCall(self) -> None:
        if self.__context.getState().getStateType() == "Conversation" or self.__context.getState().getStateType() == "Call":
            if self.__balance <= 0:
                self.__context.setState(states.NegativeBalance())
            else:
                self.__context.setState(states.Waiting())
        self.__showCurrentState()


    def addMoneyToBalance(self, moneyAmount: float) -> None:
        if moneyAmount > 0:
            self.__balance += moneyAmount
            self.indicateBalance.emit(str(self.__balance))
            if self.__context.getState().getStateType() == "NegativeBalance":
                self.__context.setState(states.Waiting())
        self.__showCurrentState()

if __name__ == "__main__":
    phone = Phone('123')
    phone.call()
    phone.answerCall()
    phone.endCall()


        