import serial
import time
import string
import paho.mqtt.publish as publish
# reading and writing data from and to arduino serially.
# rfcomm0 -> this could be different
ser = serial.Serial("/dev/rfcomm0", 9600)
ser.write(str.encode('Start\r\n'))
ser1 = serial.Serial("/dev/rfcomm1", 9600)
ser1.write(str.encode('Start\r\n'))
while True:
        humidity = ser.readline()
        payload1 = humidity.decode('utf-8').strip('\r\n')
        print(payload1)
        soil = ser1.readline()
        payload2 = soil.decode('utf-8').strip('\r\n')
        print(payload2)
        msgs = [{'topic':"myFarm/humidity",'payload':payload1},{'topic':"myFarm/soilMoisture",'payload':payload2}]
        publish.multiple(msgs, hostname="13.231.117.247")