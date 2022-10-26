from PySide6.QtWidgets import QApplication, QWidget
from PySide6.QtCore import QModelIndex
import phone
import widget

class MainWidget(QWidget):
    def __init__(self, ) -> None:
        super().__init__()
        self.stateListLen = 0
        self.ui_form = widget.Ui_widget()
        self.ui_form.setupUi(self)
        self.phone = phone.Phone('123456789')
        # Подключить слоты 
        self.phone.indicateBalance.connect(lambda value_: self.ui_form.balanceLabel.setText(value_))
        self.phone.indicateCurrentState.connect(lambda value_: self.ui_form.currentState.setText(value_))
        self.phone.addCurrentStateToList.connect(lambda value_: self.addToList(value_))
        self.ui_form.callButton.clicked.connect(self.phone.call)
        self.ui_form.answerCallButton.clicked.connect(self.phone.answerCall)
        self.ui_form.endCallButton.clicked.connect(self.phone.endCall)
        self.ui_form.addToBalanceButton.clicked.connect(lambda: self.phone.addMoneyToBalance(50.0))
        # Инициализация данных в виджете
        self.phone.initUIData()

    def addToList(self, value: str):
        self.stateListLen += 1
        self.ui_form.listWidget.addItem(value)
        self.ui_form.listWidget.setCurrentRow(self.stateListLen-1)

if __name__ == "__main__":
    app = QApplication([])

    widget = MainWidget()
    widget.show()

    app.exec()
