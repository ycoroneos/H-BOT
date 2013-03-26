import serial

ser=serial.Serial('/dev/ttyACM0', 9600, timeout=1)
inp='null'
forward='510#510\n'
backward='000#000\n'
stop='255#255\n'
while (inp!='bye'):
    inp=raw_input()
    if (inp=='w'):
        ser.write(forward)
    elif (inp=='s'):
        ser.write(backward)
    elif (inp==' '):
        ser.write(stop)
    else:
        ser.write(str(inp)+'\n')
    print 'sent: '+ str(inp)+'\n'
ser.write(stop)
ser.close()
