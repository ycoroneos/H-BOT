import serial

ser=serial.Serial('/dev/ttyACM0', 9600, timeout=1)
inp='null'
forward='120#120\n'
backward='070#070\n'
stop='000#000\n'
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
