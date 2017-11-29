import time
import serial
ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=0)

import curses
def main(win):
    win.nodelay(True)
    key = ""
    win.clear()
    #win.addstr("Detected Key")
    while(1):
        try:
            key = win.getkey()
            win.clear()
            #win.addstr("Detected Key")
            if str(key)== "KEY_UP":
                #win.addstr(str(key))
                var = 'a'
                ser.write(bytes(var.encode('ascii')))
            elif str(key)== "KEY_DOWN":
                #win.addstr(str(key))
                var = 'b'
                ser.write(bytes(var.encode('ascii')))
            elif str(key)== "KEY_LEFT":
                #win.addstr(str(key))
                var = 'c'
                ser.write(bytes(var.encode('ascii')))
            elif str(key)== "KEY_RIGHT":
                #win.addstr(str(key))
                var = 'd'
                ser.write(bytes(var.encode('ascii')))
            elif str(key)== "l":
                #win.addstr(str(key))
                var = 'e'
                ser.write(bytes(var.encode('ascii')))
            elif str(key)== "b":
                #win.addstr(str(key))
                var = 'f'
                ser.write(bytes(var.encode('ascii')))
            elif str(key)== "w":
                #win.addstr(str(key))
                var = 'h'
                ser.write(bytes(var.encode('ascii')))
            elif str(key)== "s":
                #win.addstr(str(key))
                var = 'g'
                ser.write(bytes(var.encode('ascii')))
            elif str(key)== "a":
                #win.addstr(str(key))
                var = 'i'
                ser.write(bytes(var.encode('ascii')))
            else:
                win.addstr("not anything")
        except Exception as e:
            pass
curses.wrapper(main)
