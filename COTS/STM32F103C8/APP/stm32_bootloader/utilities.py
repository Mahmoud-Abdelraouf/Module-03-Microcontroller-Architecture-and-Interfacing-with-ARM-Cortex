import struct

def calculate_crc32(buffer, buffer_length):
    crc_value = 0xFFFFFFFF
    for data_elem in buffer[:buffer_length]:
        crc_value ^= data_elem
        for _ in range(32):
            if crc_value & 0x80000000:
                crc_value = (crc_value << 1) ^ 0x04C11DB7
            else:
                crc_value <<= 1
    return crc_value & 0xFFFFFFFF

def word_value_to_byte_value(word_value, byte_index, byte_lower_first):
    return (word_value >> (8 * (byte_index - 1))) & 0x000000FF

def print_banner():
    print("\n" + "="*60)
    print(" ____              _   _                 _           ".center(60))
    print("|  _ \            | | | |               | |          ".center(60))
    print("| |_) | ___   ___ | |_| | ___   __ _  __| | ___ _ __ ".center(60))
    print("|  _ < / _ \ / _ \| __| |/ _ \ / _` |/ _` |/ _ \ '__|".center(60))
    print("| |_) | (_) | (_) | |_| | (_) | (_| | (_| |  __/ |   ".center(60))
    print("|____/ \___/ \___/ \__|_|\___/ \__,_|\__,_|\___|_|   ".center(60))
    print("                                                     ".center(60))
    print("                                                     ".center(60))
    print("="*60)
    print("Welcome to the STM32 Bootloader Tool".center(60))
    print("This tool helps you interact with the STM32 bootloader".center(60))
    print("via serial communication, providing various commands.".center(60))
    print("="*60 + "\n")

def display_menu():
    print("\nSelect the command you want to send to the bootloader:")
    print("   1. Get Bootloader Version           --> 1")
    print("   2. List Supported Commands          --> 2")
    print("   3. Get Chip Identification Number   --> 3")
    print("   4. Get Read Protection Status       --> 4")
    print("   5. Jump to Address                  --> 5")
    print("   6. Erase Flash Memory               --> 6")
    print("   7. Write to Memory                  --> 7")
    print("   8. Enable/Disable Write Protection  --> 8")
    print("   9. Read from Memory                 --> 9")
    print("  10. Read Sector Status               --> 10")
    print("  11. Read OTP (One-Time Programmable) --> 11")
    print("  12. Change Read Protection Level     --> 12")

def print_success(message):
    print(f"\033[92m{message}\033[0m")

def print_error(message):
    print(f"\033[91m{message}\033[0m")

def print_goodbye():
    print("\n" + "-" * 60)
    print(" Thank you for using the STM32 Bootloader Tool ".center(60))
    print(" Goodbye! ".center(60))
    print("-" * 60 + "\n")

