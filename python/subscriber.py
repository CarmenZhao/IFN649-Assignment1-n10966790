import serial
import time
import string
import re
import paho.mqtt.client as mqtt

ser = serial.Serial("/dev/rfcomm2", 9600)
def on_connect(client, userdata, flags, rc): # func for making connection
        print("Connected to MQTT")
        print("Connection returned result: " + str(rc) )
        client.subscribe("myFarm/#")
def on_message(client, userdata, msg): # Func for Sending msg
        payload=msg.payload.decode('UTF-8')
        print(msg.topic+" "+payload)
        if "humidity" in msg.topic:
                value=re.search('Humidity:(.*)%',payload).group(1)
                if float(value) >80.00:
                        ser.write(str.encode('LED_ON\r\n'))
                else:
                        ser.write(str.encode('LED_OFF\r\n'))
        elif "soilMoisture" in msg.topic:
                value=re.search('Soil Moisture:(.*)',payload).group(1)                
                if float(value) > 0:
                        ser.write(str.encode('LED2_ON'))
                else:
                        ser.write(str.encode('LED2_OFF'))       
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("13.231.117.247", 1883, 60)
client.loop_forever()
