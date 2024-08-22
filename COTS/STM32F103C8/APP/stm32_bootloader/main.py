from serial_communication import SerialPortManager
from bootloader_commands import BootloaderCommands
from utilities import display_menu, print_banner, print_goodbye

def main():
    print_banner()
    
    port_name = input("Enter the Port Name of your device (e.g., /dev/ttyUSB0): ")
    serial_manager = SerialPortManager(port_name)

    if serial_manager.configure_serial_port() == -1:
        return

    bootloader = BootloaderCommands(serial_manager)

    while True:
        display_menu()
        command = input("\nEnter the command code (or '0' or 'exit' to exit): ").strip().lower()

        if command == '0' or command == 'exit':
            print_goodbye()
            break

        if not command.isdigit():
            print("   Error !! Please enter a valid command !! \n")
        else:
            bootloader.decode_command(int(command))

        input("\nPlease press any key to continue ...")
        serial_manager.reset_input_buffer()

if __name__ == "__main__":
    main()

