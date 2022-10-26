class State:
    _stateType: str

    def getStateType(self) -> str:
        return self._stateType

    def handle(self):
        raise NotImplementedError()

class Call(State):
    def __init__(self) -> None:
        super().__init__()
        self._stateType = 'Call'

    def handle(self):
        print('Звонок')

class NegativeBalance(State):
    def __init__(self) -> None:
        super().__init__()
        self._stateType = 'NegativeBalance'

    def handle(self):
        print('Отрицательный баланс')

class Waiting(State):
    def __init__(self) -> None:
        super().__init__()
        self._stateType = 'Waiting'

    def handle(self):
        print('Ожидание')

class Conversation(State):
    def __init__(self) -> None:
        super().__init__()
        self._stateType = 'Conversation'

    def handle(self):
        print('Разговор')



