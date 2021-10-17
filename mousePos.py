import pyautogui
import time

pyautogui.PAUSE = 0

while True:
	print(pyautogui.position())
	time.sleep(0.1)
