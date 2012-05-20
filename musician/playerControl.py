# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'playerControl.ui'
#
# Created: Sat May 19 18:08:46 2012
#      by: PyQt4 UI code generator 4.9.1
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    _fromUtf8 = lambda s: s

class Ui_PlayerControl(object):
    def setupUi(self, PlayerControl):
        PlayerControl.setObjectName(_fromUtf8("PlayerControl"))
        PlayerControl.resize(330, 89)
        self.btnPlay = QtGui.QPushButton(PlayerControl)
        self.btnPlay.setGeometry(QtCore.QRect(90, 60, 75, 23))
        self.btnPlay.setObjectName(_fromUtf8("btnPlay"))
        self.btnStop = QtGui.QPushButton(PlayerControl)
        self.btnStop.setGeometry(QtCore.QRect(170, 60, 75, 23))
        self.btnStop.setObjectName(_fromUtf8("btnStop"))
        self.btnPrev = QtGui.QPushButton(PlayerControl)
        self.btnPrev.setGeometry(QtCore.QRect(10, 60, 75, 23))
        self.btnPrev.setObjectName(_fromUtf8("btnPrev"))
        self.btnNext = QtGui.QPushButton(PlayerControl)
        self.btnNext.setGeometry(QtCore.QRect(250, 60, 75, 23))
        self.btnNext.setObjectName(_fromUtf8("btnNext"))
        self.sliderTime = QtGui.QSlider(PlayerControl)
        self.sliderTime.setGeometry(QtCore.QRect(10, 40, 311, 20))
        self.sliderTime.setOrientation(QtCore.Qt.Horizontal)
        self.sliderTime.setObjectName(_fromUtf8("sliderTime"))
        self.editTitle = QtGui.QPlainTextEdit(PlayerControl)
        self.editTitle.setGeometry(QtCore.QRect(10, 10, 311, 21))
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.editTitle.sizePolicy().hasHeightForWidth())
        self.editTitle.setSizePolicy(sizePolicy)
        self.editTitle.setVerticalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOff)
        self.editTitle.setReadOnly(True)
        self.editTitle.setObjectName(_fromUtf8("editTitle"))

        self.retranslateUi(PlayerControl)
        QtCore.QMetaObject.connectSlotsByName(PlayerControl)

    def retranslateUi(self, PlayerControl):
        PlayerControl.setWindowTitle(QtGui.QApplication.translate("PlayerControl", "Form", None, QtGui.QApplication.UnicodeUTF8))
        self.btnPlay.setText(QtGui.QApplication.translate("PlayerControl", "Play/Pause", None, QtGui.QApplication.UnicodeUTF8))
        self.btnStop.setText(QtGui.QApplication.translate("PlayerControl", "Stop", None, QtGui.QApplication.UnicodeUTF8))
        self.btnPrev.setText(QtGui.QApplication.translate("PlayerControl", "Prev", None, QtGui.QApplication.UnicodeUTF8))
        self.btnNext.setText(QtGui.QApplication.translate("PlayerControl", "Next", None, QtGui.QApplication.UnicodeUTF8))

