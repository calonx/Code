import sys
import os
from PyQt4 import QtGui, QtCore
from PyQt4.phonon import Phonon
from playerControl import Ui_PlayerControl

testFile = r"C:\Files\Dropbox\Music\Classical\Pachelbel, Johann\Canon In D.mp3"

class MediaLibrary:
	def __init__ (self):
		self.files = []

	def loadFromDirectory (self, directory):
		for path, dirs, files in os.walk(directory):
			for filePath in [os.path.join(path, f) for f in files]:
				files.append(filePath)

class MediaPlayer:
	def __init__ (self):
		self.library = MediaLibrary()
		self.library.loadFromDirectory(r'C:\files\dropbox\music')
		self.audio = Phonon.createPlayer(Phonon.MusicCategory)
		self.totalTime = 0
		self.audioSource = Phonon.MediaSource(testFile)
		self.audio.setCurrentSource(self.audioSource)
		self.audio.totalTimeChanged.connect(self.onTotalTimeChanged)

	def onTotalTimeChanged (self, time):
		self.totalTime = time

	def play (self):
		if self.audio.state() == Phonon.PlayingState:
			self.audio.pause()
		else:
			self.audio.play()

	def stop (self):
		self.audio.stop()

	def prev (self):
		self.stop()

	def next (self):
		self.stop()

	def getTimeRemaining (self):
		return self.audio.remainingTime() / 1000.0

	def getTimeTotal (self):
		return self.totalTime / 1000.0

	def isStopped (self):
		return self.audio.state() == Phonon.StoppedState

	def getTitle (self):
		title = self.audio.metaData("TITLE")
		if len(title) > 0:
			return title[0]
		return "[not available]"

	def seek (self, time):
		self.audio.seek(time * 1000)


class MainForm (QtGui.QMainWindow):
	def __init__ (self, parent = None):
		super(MainForm, self).__init__(parent)

		self.player = MediaPlayer()

		self.ui = Ui_PlayerControl()
		self.ui.setupUi(self)
		self.ui.btnPlay.clicked.connect(self.player.play)
		self.ui.btnStop.clicked.connect(self.player.stop)
		self.ui.btnPrev.clicked.connect(self.player.prev)
		self.ui.btnNext.clicked.connect(self.player.next)

		self.sliderScale = 1000
		self.ui.sliderTime.setRange(0, self.sliderScale)
		self.ui.sliderTime.setValue(0)
		self.ui.sliderTime.sliderReleased.connect(self.onSliderReleased)

		self.ui.editTitle.setPlainText(self.player.getTitle())

		self.updateTimer = QtCore.QTimer()
		updatesPerSecond = 1
		self.updateTimer.setInterval(1000 / updatesPerSecond)
		self.updateTimer.timeout.connect(self.onTimer)
		self.updateTimer.start()

	def onTimer (self):
		if self.ui.sliderTime.isSliderDown():
			return
			
		self.ui.editTitle.setPlainText(self.player.getTitle())

		pos = 0
		if not self.player.isStopped():
			timeLeft = self.player.getTimeRemaining()
			timeTotal = self.player.getTimeTotal()
			if timeTotal != 0:
				pos = 1 - timeLeft * 1.0 / timeTotal
		self.ui.sliderTime.setSliderPosition(pos * self.sliderScale)

	def onSliderReleased (self):
		pos = self.ui.sliderTime.sliderPosition() * 1.0 / self.sliderScale
		self.player.seek(pos * self.player.getTimeTotal())


if __name__ == "__main__":
	app = QtGui.QApplication(sys.argv)
	mainForm = MainForm()
	mainForm.show()
	sys.exit(app.exec_())
