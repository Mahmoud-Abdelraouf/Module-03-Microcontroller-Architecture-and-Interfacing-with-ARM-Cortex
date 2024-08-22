import serial
import struct
import glob
from config import BAUD_RATE, TIMEOUT
from utilities import print_error, print_success

class SerialPortManager:
    def __init__(self, port_name):
        self.port_name = port_name
        self.serial_port_obj = None

    def configure_serial_port(self):
        try:
            self.serial_port_obj = serial.Serial(self.port_name, BAUD_RATE, timeout=TIMEOUT)
        except serial.SerialException:
            print_error("\nError !! That was not a valid port")
            available_ports = self.check_serial_ports()
            if not available_ports:
                print_error("\nError !! No ports detected")
            else:
                print("\nHere are some available ports on your PC. Try Again!!")
                print("\n   ", available_ports)
            return -1
        
        if self.serial_port_obj.is_open:
            print_success("Port Open Success \n")
        else:
            print_error("Port Open Failed \n")

    def check_serial_ports(self):
        ports = glob.glob('/dev/tty[A-Za-z]*')
        serial_ports = []

        for port in ports:
            try:
                s = serial.Serial(port)
                s.close()
                serial_ports.append(port)
            except (OSError, serial.SerialException):
                pass

        return serial_ports

    def write_data_to_serial_port(self, value, length):
        data = struct.pack('>B', value)
        print("   "+"0x{:02x}".format(value), end=' ')
        self.serial_port_obj.write(data)

    def read_serial_port(self, data_len):
        serial_value = self.serial_port_obj.read(data_len)
        while len(serial_value) <= 0:
            serial_value = self.serial_port_obj.read(data_len)
            print("Waiting for a reply from the Bootloader")
        return serial_value

    def reset_input_buffer(self):
        if self.serial_port_obj:
            self.serial_port_obj.reset_input_buffer()

