import states

class Context:
    __currentState: states.State

    def setState(self, state: states.State) -> None:
        self.__currentState = state

    def getState(self) -> states.State:
        return self.__currentState

    def handleCurrentState(self) -> None:
        self.__currentState.handle()
