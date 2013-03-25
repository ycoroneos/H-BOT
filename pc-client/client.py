import serial

ser=serial.Serial('/dev/ttyS1', 19200, timeout=1)
inp='null'
forward='120#120\n'
backward='070#070\n'
stop='090#090\n'
while (inp!='bye'):
    inp=raw_input()
    if (inp=='w'):
        ser.write(forward)
    elif (inp=='s'):
        ser.write(backwards)
    elif (inp==' '):
        ser.write(stop)
    else:
        ser.write(str(inp)+'\n')
    print 'sent: '+ str(inp)+'\n'
ser.close()
