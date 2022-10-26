class IState:
    _stateType: str

    def getStateType(self) -> str:
        return self._stateType

    def handle(self):
        raise NotImplementedError()

class Call(IState):
    def __init__(self) -> None:
        super().__init__()
        self._stateType = 'Call'

    def handle(self):
        print('Звонок')
        return 'Звонок'

class NegativeBalance(IState):
    def __init__(self) -> None:
        super().__init__()
        self._stateType = 'NegativeBalance'

    def handle(self):
        print('Отрицательный баланс')
        return 'Отрицательный баланс'

class Waiting(IState):
    def __init__(self) -> None:
        super().__init__()
        self._stateType = 'Waiting'

    def handle(self):
        print('Ожидание')
        return 'Ожидание'


class Conversation(IState):
    def __init__(self) -> None:
        super().__init__()
        self._stateType = 'Conversation'

    def handle(self):
        print('Разговор')
        return 'Разговор'




