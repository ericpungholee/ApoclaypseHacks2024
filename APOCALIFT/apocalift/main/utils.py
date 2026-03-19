import time


SPEED_PERCENTAGE = "50"
SERVO_LEFT_BOUND = "135"
SERVO_RIGHT_BOUND = "45"
SERVO_MID = "100"


def init_arduino(port, baudrate, timeout=0.1):
    import serial

    return serial.Serial(port=port, baudrate=baudrate, timeout=timeout)


def write_read(command, arduino):
    arduino.write(command.encode("utf-8"))
    time.sleep(0.05)
    return arduino.readline()
