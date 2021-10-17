This is a simple project I made to interface a 4-wire resistive touch panel with a computer, using an Arduino.

Files
-----
- touchscreen.ino - Code that runs on the Arduino
- mouse.py - Reads serial data from Arduino and moves the mouse, using pyautogui
- mousePos.py - Simple utility to print the mouse coordinates, which can be passed to mouse.py to map the panel to a portion of the screen.
