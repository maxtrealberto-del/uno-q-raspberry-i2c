from smbus2 import SMBus
import time

ADDRESS = 0x08
bus = SMBus(1)

def encender():
    bus.write_byte(ADDRESS, ord('1'))

def apagar():
    bus.write_byte(ADDRESS, ord('0'))

if __name__ == "__main__":
    encender()
    time.sleep(2)
    apagar()
