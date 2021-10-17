import serial
import time
import pyautogui
import sys
ser = serial.Serial('/dev/ttyACM0', 2000000)
pyautogui.PAUSE = 0
pyautogui.FAILSAFE = False
if len(sys.argv) != 5:
	print("Usage: mouse minX minY maxX maxY")
	sys.exit()
MIN_X = int(sys.argv[1])
MIN_Y = int(sys.argv[2])
MAX_X = int(sys.argv[3])
MAX_Y = int(sys.argv[4])

MIN_XV = 78
MAX_XV = 950
MIN_YV = 145
MAX_YV = 905

while True:
	position = str(ser.readline(),'utf-8').rstrip().split(' ')
	#print(ser.readline())
	#print(str(ser.readline(),'utf-8').rstrip().split(' '))
	if len(position) == 2:
		x = int(position[0])
		x = ((x - MIN_XV)*(MAX_X-MIN_X))/(MAX_XV-MIN_XV)+MIN_X
		y = int(position[1])
		y = ((y - MIN_YV)*(MAX_Y-MIN_Y))/(MAX_YV-MIN_YV)+MIN_Y	
		pyautogui.moveTo(x,y)
	
	
