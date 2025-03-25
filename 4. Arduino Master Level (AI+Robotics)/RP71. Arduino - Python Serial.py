import serial
import time

# Replace 'COMx' with your port (Windows: COM3, COM4... / Linux: /dev/ttyUSB0, /dev/ttyACM0)
arduino = serial.Serial('COM3', 9600, timeout=1)
time.sleep(2)  # Wait for connection to establish

while True:
    command = input("Enter 1 to turn ON LED, 0 to turn OFF, or 'exit' to quit: ")

    if command.lower() == "exit":
        break

    arduino.write(command.encode())  # Send data to Arduino
    time.sleep(0.1)  # Wait for response

    response = arduino.readline().decode().strip()  # Read response
    if response:
        print("Arduino:", response)

arduino.close()  # Close the connection
