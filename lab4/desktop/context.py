import states

class Context:
    __currentState: states.IState

    def setState(self, IState: states.IState) -> None:
        self.__currentState = IState

    def getState(self) -> states.IState:
        return self.__currentState

    def handleCurrentState(self) -> str:
        return self.__currentState.handle()
