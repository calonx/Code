import sys
from PyQt4 import QtGui, QtCore
from playerControl import Ui_PlayerControl

class MainForm (QtGui.QMainWindow):
	def __init__ (self, parent = None):
		super(MainForm, self).__init__(parent)
		self.ui = Ui_PlayerControl()
		self.ui.setupUi(self)

if __name__ == "__main__":
	app = QtGui.QApplication(sys.argv)
	mainForm = MainForm()
	mainForm.show()
	sys.exit(app.exec_())