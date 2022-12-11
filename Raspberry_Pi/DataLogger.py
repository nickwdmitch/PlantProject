import serial
import datetime
import csv
from time import sleep

# Set file name for output spreadsheet data
fileName = 'analog-data.csv'

# Set test time in minutes (1440 = 1 hour)
testTimeValue = 5
testTime = datetime.datetime.now() + datetime.timedelta(minutes=testTimeValue) 

# Connect to to arduino serial port
ser = serial.Serial("/dev/ttyUSB0", 115200)

# Open new blank .csv file to write data to 
file = open(fileName, 'w')

# Create writer object for writing to the .csv file
writer = csv.writer(file)

# Header for .csv file
header = ['Moisture Sensor', 'Light Dependent Resistor']
writer.writerow(header)

while True:
    if datetime.datetime.now() >= testTime:
        break
    r_data = ser.readline()
    tempList = r_data.decode('utf8').split(";")
    tempString = tempList[1]
    tempList[1] = tempString[:-2]
    print(tempList)
    writer.writerow(tempList)
    
print("Data Sampling Complete")
file.close()

