import time
import serial
ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=0)


while(True):
    x = input()
    print(x)
    if x=="up":
        var = 'a'
        ser.write(bytes(var.encode('ascii')))
    # 	print(bytes(var.encode('ascii')))

    elif x=="down":
        var = 'b'
        ser.write(bytes(var.encode('ascii')))
    elif x=="left":
        var = 'c'
        ser.write(bytes(var.encode('ascii')))
    elif x=="right":
        var = 'd'
        ser.write(bytes(var.encode('ascii')))
    elif x=="light":
        var = 'e'
        ser.write(bytes(var.encode('ascii')))
    elif x=="buzz":
        var = 'f'
        ser.write(bytes(var.encode('ascii')))
    elif x=="angle":
        var = 'g'
        ser.write(bytes(var.encode('ascii')))
