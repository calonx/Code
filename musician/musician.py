import sys
import os
import random
from PyQt4 import QtGui, QtCore
from PyQt4.phonon import Phonon
from playerControl import Ui_PlayerControl

testFile = r"C:\Files\Dropbox\Music\Classical\Pachelbel, Johann\Canon In D.mp3"

class MediaEntry:
	def __init__ (self, path):
		self.path = path

class MediaLibrary:
	def __init__ (self):
		self.entries = []

	def loadFromDirectory (self, directory):
		for path, dirs, files in os.walk(directory):
			for filePath in [os.path.join(path, f) for f in files]:
				self.entries.append(MediaEntry(filePath))

class MediaQueue:
	def __init__ (self, library):
		self.library = library
		self.nextQueue = []
		self.prevQueue = []
		self.current = None

	def moveNext (self):
		# Add current track to the history
		if self.current:
			self.prevQueue.append(self.current)

		# If there's a track queued, use that; otherwise choose a random one
		if len(self.nextQueue) > 0:
			self.current = self.nextQueue.pop(0)
		else:
			self.current = random.choice(self.library.entries)
		return self.current

	def movePrev (self):
		if self.current:
			self.nextQueue.insert(0, self.current)
		if len(self.prevQueue) > 0:
			self.current = self.prevQueue.pop()
		else:
			self.current = None
		return self.current


class MediaPlayer:
	def __init__ (self):
		self.audio = Phonon.createPlayer(Phonon.MusicCategory)
		self.totalTime = 0
		self.audioSource = None
		self.audio.totalTimeChanged.connect(self.onTotalTimeChanged)
		self.nowPlaying = None

		self.library = MediaLibrary()
		self.library.loadFromDirectory(r'C:\files\dropbox\music')
		self.queue = MediaQueue(self.library)

	def onTotalTimeChanged (self, time):
		self.totalTime = time

	def play (self):
		if not self.nowPlaying:
			return
		if self.audio.state() == Phonon.PlayingState:
			print("Paused: " + self.nowPlaying)
			self.audio.pause()
		else:
			print("Playing: " + self.nowPlaying)
			self.audio.play()

	def stop (self):
		if self.nowPlaying:
			print("Stopped: " + self.nowPlaying)
		self.audio.stop()

	def prev (self):
		self.setTrack(self.queue.movePrev().path)

	def next (self):
		self.setTrack(self.queue.moveNext().path)

	def setTrack (self, track):
		wasPlaying = False
		if self.audio.state() != Phonon.StoppedState:
			self.stop()
			wasPlaying = True

		self.nowPlaying = track
		self.audioSource = Phonon.MediaSource(self.nowPlaying)
		self.audio.setCurrentSource(self.audioSource)
		if wasPlaying:
			self.play()

	def getTimeRemaining (self):
		return self.audio.remainingTime() / 1000.0

	def getTimeTotal (self):
		return self.totalTime / 1000.0

	def isStopped (self):
		return self.audio.state() == Phonon.StoppedState

	def getTitle (self):
		if not self.nowPlaying:
			return "[no song playing]"

		title = self.audio.metaData("TITLE")
		if len(title) > 0:
			return title[0]
		
		title = os.path.split(self.nowPlaying)[1]
		return title

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
