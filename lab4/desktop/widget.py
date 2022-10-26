# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'widget.ui'
##
## Created by: Qt User Interface Compiler version 6.2.4
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QLabel, QLineEdit, QListWidget,
    QListWidgetItem, QPushButton, QSizePolicy, QWidget)

class Ui_widget(object):
    def setupUi(self, widget):
        if not widget.objectName():
            widget.setObjectName(u"widget")
        widget.resize(640, 480)
        self.callButton = QPushButton(widget)
        self.callButton.setObjectName(u"callButton")
        self.callButton.setGeometry(QRect(420, 80, 161, 25))
        self.answerCallButton = QPushButton(widget)
        self.answerCallButton.setObjectName(u"answerCallButton")
        self.answerCallButton.setGeometry(QRect(420, 110, 161, 25))
        self.endCallButton = QPushButton(widget)
        self.endCallButton.setObjectName(u"endCallButton")
        self.endCallButton.setGeometry(QRect(420, 140, 161, 25))
        self.addToBalanceButton = QPushButton(widget)
        self.addToBalanceButton.setObjectName(u"addToBalanceButton")
        self.addToBalanceButton.setGeometry(QRect(420, 170, 161, 25))
        self.listWidget = QListWidget(widget)
        self.listWidget.setObjectName(u"listWidget")
        self.listWidget.setGeometry(QRect(90, 140, 251, 192))
        self.listWidget.setSortingEnabled(False)
        self.currentState = QLineEdit(widget)
        self.currentState.setObjectName(u"currentState")
        self.currentState.setGeometry(QRect(90, 80, 251, 25))
        self.currentState.setReadOnly(True)
        self.label = QLabel(widget)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(420, 60, 61, 17))
        self.balanceLabel = QLabel(widget)
        self.balanceLabel.setObjectName(u"balanceLabel")
        self.balanceLabel.setGeometry(QRect(480, 60, 67, 17))
        self.label_2 = QLabel(widget)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setGeometry(QRect(90, 60, 181, 17))
        self.label_3 = QLabel(widget)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setGeometry(QRect(90, 120, 161, 17))

        self.retranslateUi(widget)

        QMetaObject.connectSlotsByName(widget)
    # setupUi

    def retranslateUi(self, widget):
        widget.setWindowTitle(QCoreApplication.translate("widget", u"\u041b\u0430\u0431\u043e\u0440\u0430\u0442\u043e\u0440\u043d\u0430\u044f \u0440\u0430\u0431\u043e\u0442\u0430 4 - \u0420\u0443\u0434\u044c, \u0418\u0422-621\u043c", None))
        self.callButton.setText(QCoreApplication.translate("widget", u"\u041f\u043e\u0437\u0432\u043e\u043d\u0438\u0442\u044c", None))
        self.answerCallButton.setText(QCoreApplication.translate("widget", u"\u041f\u0440\u0438\u043d\u044f\u0442\u044c ", None))
        self.endCallButton.setText(QCoreApplication.translate("widget", u"\u0421\u0431\u0440\u043e\u0441\u0438\u0442\u044c", None))
        self.addToBalanceButton.setText(QCoreApplication.translate("widget", u"\u041f\u043e\u043f\u043e\u043b\u043d\u0438\u0442\u044c \u043d\u0430 50 \u0443.\u0435.", None))
        self.label.setText(QCoreApplication.translate("widget", u"\u0411\u0430\u043b\u0430\u043d\u0441:", None))
        self.balanceLabel.setText(QCoreApplication.translate("widget", u"0", None))
        self.label_2.setText(QCoreApplication.translate("widget", u"\u041f\u043e\u0441\u043b\u0435\u0434\u043d\u0435\u0435 \u0441\u043e\u0441\u0442\u043e\u044f\u043d\u0438\u0435", None))
        self.label_3.setText(QCoreApplication.translate("widget", u"\u0418\u0441\u0442\u043e\u0440\u0438\u044f \u0441\u043e\u0441\u0442\u043e\u044f\u043d\u0438\u0439", None))
    # retranslateUi

