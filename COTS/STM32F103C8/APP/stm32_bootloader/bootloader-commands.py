from utilities import calculate_crc32, word_value_to_byte_value, print_success, print_error
from config import *

class BootloaderCommands:
    def __init__(self, serial_manager):
        self.serial_manager = serial_manager

    def decode_command(self, command):
        if command == 1:
            self.cbl_get_ver_cmd()
        elif command == 2:
            self.cbl_get_help_cmd()
        elif command == 3:
            self.cbl_get_cid_cmd()
        elif command == 4:
            self.cbl_get_rdp_status_cmd()
        elif command == 5:
            self.cbl_go_to_addr_cmd()
        elif command == 6:
            self.cbl_flash_erase_cmd()
        elif command == 7:
            self.cbl_mem_write_cmd()
        elif command == 12:
            self.cbl_change_rop_level_cmd()
        else:
            print_error("Invalid command code!")

    def cbl_get_ver_cmd(self):
        print("Requesting the bootloader version...")
        cbl_get_ver_cmd_len = 6
        bl_host_buffer = [0] * 255
        bl_host_buffer[0] = cbl_get_ver_cmd_len - 1
        bl_host_buffer[1] = CBL_GET_VER_CMD
        crc32_value = calculate_crc32(bl_host_buffer, cbl_get_ver_cmd_len - 4)
        self.update_crc_in_buffer(bl_host_buffer, crc32_value, 2)
        self.send_command_to_bootloader(bl_host_buffer, cbl_get_ver_cmd_len, CBL_GET_VER_CMD)

    def cbl_get_help_cmd(self):
        print("Requesting the list of supported commands...")
        cbl_get_help_cmd_len = 6
        bl_host_buffer = [0] * 255
        bl_host_buffer[0] = cbl_get_help_cmd_len - 1
        bl_host_buffer[1] = CBL_GET_HELP_CMD
        crc32_value = calculate_crc32(bl_host_buffer, cbl_get_help_cmd_len - 4)
        self.update_crc_in_buffer(bl_host_buffer, crc32_value, 2)
        self.send_command_to_bootloader(bl_host_buffer, cbl_get_help_cmd_len, CBL_GET_HELP_CMD)

    def cbl_get_cid_cmd(self):
        print("Requesting the MCU chip identification number...")
        cbl_get_cid_cmd_len = 6
        bl_host_buffer = [0] * 255
        bl_host_buffer[0] = cbl_get_cid_cmd_len - 1
        bl_host_buffer[1] = CBL_GET_CID_CMD
        crc32_value = calculate_crc32(bl_host_buffer, cbl_get_cid_cmd_len - 4)
        self.update_crc_in_buffer(bl_host_buffer, crc32_value, 2)
        self.send_command_to_bootloader(bl_host_buffer, cbl_get_cid_cmd_len, CBL_GET_CID_CMD)

    def cbl_get_rdp_status_cmd(self):
        print("Requesting the FLASH Read Protection level...")
        cbl_get_rdp_status_cmd_len = 6
        bl_host_buffer = [0] * 255
        bl_host_buffer[0] = cbl_get_rdp_status_cmd_len - 1
        bl_host_buffer[1] = CBL_GET_RDP_STATUS_CMD
        crc32_value = calculate_crc32(bl_host_buffer, cbl_get_rdp_status_cmd_len - 4)
        self.update_crc_in_buffer(bl_host_buffer, crc32_value, 2)
        self.send_command_to_bootloader(bl_host_buffer, cbl_get_rdp_status_cmd_len, CBL_GET_RDP_STATUS_CMD)

    def cbl_go_to_addr_cmd(self):
        print("Jumping bootloader to specified address...")
        cbl_go_to_addr_cmd_len = 10
        cbl_jump_address = input("\n   Please Enter the Address in Hex: ")
        cbl_jump_address = int(cbl_jump_address, 16)
        bl_host_buffer = [0] * 255
        bl_host_buffer[0] = cbl_go_to_addr_cmd_len - 1
        bl_host_buffer[1] = CBL_GO_TO_ADDR_CMD
        bl_host_buffer[2] = word_value_to_byte_value(cbl_jump_address, 1, 1)
        bl_host_buffer[3] = word_value_to_byte_value(cbl_jump_address, 2, 1)
        bl_host_buffer[4] = word_value_to_byte_value(cbl_jump_address, 3, 1)
        bl_host_buffer[5] = word_value_to_byte_value(cbl_jump_address, 4, 1)
        crc32_value = calculate_crc32(bl_host_buffer, cbl_go_to_addr_cmd_len - 4)
        self.update_crc_in_buffer(bl_host_buffer, crc32_value, 6)
        self.send_command_to_bootloader(bl_host_buffer, cbl_go_to_addr_cmd_len, CBL_GO_TO_ADDR_CMD)

    def cbl_flash_erase_cmd(self):
        print("Erasing flash memory...")
        cbl_flash_erase_cmd_len = 11
        bl_host_buffer = [0] * 255
        bl_host_buffer[0] = cbl_flash_erase_cmd_len - 1
        bl_host_buffer[1] = CBL_FLASH_ERASE_CMD
        sector_number = input("\n   Please enter start Address: ")
        sector_number = int(sector_number, 16)
        if sector_number != 0xFF:
            number_of_sectors = int(input("\n   Please enter number of sectors to erase (12 Max): "), 16)
        else:
            number_of_sectors = 0xFF
        bl_host_buffer[2] = word_value_to_byte_value(sector_number, 1, 1)
        bl_host_buffer[3] = word_value_to_byte_value(sector_number, 2, 1)
        bl_host_buffer[4] = word_value_to_byte_value(sector_number, 3, 1)
        bl_host_buffer[5] = word_value_to_byte_value(sector_number, 4, 1)
        bl_host_buffer[6] = number_of_sectors
        crc32_value = calculate_crc32(bl_host_buffer, cbl_flash_erase_cmd_len - 4)
        self.update_crc_in_buffer(bl_host_buffer, crc32_value, 7)
        self.send_command_to_bootloader(bl_host_buffer, cbl_flash_erase_cmd_len, CBL_FLASH_ERASE_CMD)

    def cbl_mem_write_cmd(self):
        print("Writing data into memory...")
        global Memory_Write_Is_Active
        global Memory_Write_All
        memory_write_is_active = 1
        memory_write_all = 1
        bin_file_total_len = 0
        bin_file_remaining_bytes = 0
        bin_file_sent_bytes = 0
        base_memory_address = 0
        bin_file_read_length = 0

        bin_file_total_len = self.calculate_bin_file_length("TestBootloader.bin")
        print("   Preparing to write a binary file with length (", bin_file_total_len, ") Bytes")
        bin_file = self.open_bin_file("TestBootloader.bin")
        bin_file_remaining_bytes = bin_file_total_len - bin_file_sent_bytes
        base_memory_address = int(input("\n   Enter the start address: "), 16)

        bl_host_buffer = [0] * 255

        while bin_file_remaining_bytes:
            if bin_file_remaining_bytes >= 64:
                bin_file_read_length = 64
            else:
                bin_file_read_length = bin_file_remaining_bytes

            for i in range(bin_file_read_length):
                bin_file_byte_value = bytearray(bin_file.read(1))
                bl_host_buffer[7 + i] = int(bin_file_byte_value[0])

            bl_host_buffer[1] = CBL_MEM_WRITE_CMD
            bl_host_buffer[2] = word_value_to_byte_value(base_memory_address, 1, 1)
            bl_host_buffer[3] = word_value_to_byte_value(base_memory_address, 2, 1)
            bl_host_buffer[4] = word_value_to_byte_value(base_memory_address, 3, 1)
            bl_host_buffer[5] = word_value_to_byte_value(base_memory_address, 4, 1)
            bl_host_buffer[6] = bin_file_read_length
            cbl_mem_write_cmd_len = (bin_file_read_length + 11)
            bl_host_buffer[0] = cbl_mem_write_cmd_len - 1

            crc32_value = calculate_crc32(bl_host_buffer, cbl_mem_write_cmd_len - 4)
            self.update_crc_in_buffer(bl_host_buffer, crc32_value, 7 + bin_file_read_length)
            base_memory_address += bin_file_read_length

            self.serial_manager.write_data_to_serial_port(bl_host_buffer[0], 1)
            for data in bl_host_buffer[1:cbl_mem_write_cmd_len]:
                self.serial_manager.write_data_to_serial_port(data, cbl_mem_write_cmd_len - 1)

            bin_file_sent_bytes += bin_file_read_length
            bin_file_remaining_bytes = bin_file_total_len - bin_file_sent_bytes
            print("\n   Bytes sent to the bootloader: {0}".format(bin_file_sent_bytes))

            bl_return_value = self.serial_manager.read_serial_port(cbl_mem_write_cmd_len)
            memory_write_is_active = 0

        if memory_write_all == 1:
            print("\n\n Payload Written Successfully")

    def cbl_change_rop_level_cmd(self):
        print("Changing read protection level of the flash memory...")
        protection_level = int(input("\n   Please Enter one of these Protection levels (0, 1): "), 8)
        if protection_level not in [0, 1]:
            print_error("\n   Invalid Protection level !!")
            return

        cbl_change_rop_level_cmd_len = 7
        bl_host_buffer = [0] * 255
        bl_host_buffer[0] = cbl_change_rop_level_cmd_len - 1
        bl_host_buffer[1] = CBL_CHANGE_ROP_Level_CMD
        bl_host_buffer[2] = protection_level
        crc32_value = calculate_crc32(bl_host_buffer, cbl_change_rop_level_cmd_len - 4)
        self.update_crc_in_buffer(bl_host_buffer, crc32_value, 3)
        self.send_command_to_bootloader(bl_host_buffer, cbl_change_rop_level_cmd_len, CBL_CHANGE_ROP_Level_CMD)

    def send_command_to_bootloader(self, buffer, length, command_code):
        self.serial_manager.write_data_to_serial_port(buffer[0], 1)
        for data in buffer[1:length]:
            self.serial_manager.write_data_to_serial_port(data, length - 1)
        self.process_command_response(command_code)

    def process_command_response(self, command_code):
        length_to_follow = 0
        bl_ack = self.serial_manager.read_serial_port(2)
        if len(bl_ack):
            bl_ack_array = bytearray(bl_ack)
            if bl_ack_array[0] == 0xCD:
                print_success("\n   Received Acknowledgement from Bootloader")
                length_to_follow = bl_ack_array[1]
                print("   Preparing to receive (", int(length_to_follow), ") bytes from the bootloader")
                if command_code == CBL_GET_VER_CMD:
                    self.process_cbl_get_ver_cmd(length_to_follow)
                elif command_code == CBL_GET_HELP_CMD:
                    self.process_cbl_get_help_cmd(length_to_follow)
                elif command_code == CBL_GET_CID_CMD:
                    self.process_cbl_get_cid_cmd(length_to_follow)
                elif command_code == CBL_GET_RDP_STATUS_CMD:
                    self.process_cbl_get_rdp_status_cmd(length_to_follow)
                elif command_code == CBL_GO_TO_ADDR_CMD:
                    self.process_cbl_go_to_addr_cmd(length_to_follow)
                elif command_code == CBL_FLASH_ERASE_CMD:
                    self.process_cbl_flash_erase_cmd(length_to_follow)
                elif command_code == CBL_MEM_WRITE_CMD:
                    self.process_cbl_mem_write_cmd(length_to_follow)
                elif command_code == CBL_CHANGE_ROP_Level_CMD:
                    self.process_cbl_change_rop_level_cmd(length_to_follow)
            else:
                print_error("\n   Received Not-Acknowledgement from Bootloader")
                sys.exit()

    def process_cbl_get_ver_cmd(self, data_len):
        serial_data = self.serial_manager.read_serial_port(data_len)
        value = bytearray(serial_data)
        major = value[1]
        minor = value[2]
        patch = value[3]

        # Stylish output with borders and headers
        print("\n" + "="*60)
        print("   Bootloader Version Information")
        print("="*60)
        print(f"   Version: {major}.{minor}.{patch}")
        print("   Versioning Scheme: Semantic Versioning")
        print("="*60 + "\n")

    def process_cbl_get_help_cmd(self, data_len):
        serial_data = self.serial_manager.read_serial_port(data_len)
        value = bytearray(serial_data)

        # Header with improved styling
        print("\n" + "="*60)
        print("   Supported Bootloader Commands".center(60))
        print("="*60)

        # Print each command with aligned formatting
        for command in value:
            hex_cmd = f"0x{command:02X}"  # Format as hex with leading 0x and two uppercase digits
            cmd_name = COMMAND_NAMES.get(command, "UNKNOWN_COMMAND")
            print(f"   {hex_cmd.ljust(10)}: {cmd_name}")

        print("="*60 + "\n")


    def process_cbl_get_cid_cmd(self, data_len):
        serial_data = self.serial_manager.read_serial_port(data_len)
        cid = (serial_data[1] << 8) | serial_data[0]
        print("\n   Chip Identification Number : ", hex(cid))

    def process_cbl_get_rdp_status_cmd(self, data_len):
        serial_data = self.serial_manager.read_serial_port(data_len)
        value = bytearray(serial_data)
        if value[0] == 0xEE:
            print_error("\n   Error While Reading FLASH Protection level !!")
        elif value[0] == 0xAA:
            print("\n   FLASH Protection : LEVEL 0")
        elif value[0] == 0x55:
            print("\n   FLASH Protection : LEVEL 1")
        elif value[0] == 0xCC:
            print("\n   FLASH Protection : LEVEL 2")

    def process_cbl_go_to_addr_cmd(self, data_len):
        serial_data = self.serial_manager.read_serial_port(data_len)
        value = bytearray(serial_data)
        if value[0] == 1:
            print("\n   Address Status is Valid")
        else:
            print_error("\n   Address Status is Invalid")

    def process_cbl_flash_erase_cmd(self, data_len):
        bl_erase_status = 0
        serial_data = self.serial_manager.read_serial_port(data_len)
        if len(serial_data):
            bl_erase_status = bytearray(serial_data)
            if bl_erase_status[0] == INVALID_SECTOR_NUMBER:
                print_error("\n   Erase Status -> Invalid Sector Number")
            elif bl_erase_status[0] == UNSUCCESSFUL_ERASE:
                print_error("\n   Erase Status -> Unsuccessful Erase")
            elif bl_erase_status[0] == SUCCESSFUL_ERASE:
                print_success("\n   Erase Status -> Successful Erase")
            else:
                print_error("\n   Erase Status -> Unknown Error")
        else:
            print_error("Timeout!!, Bootloader is not responding")

    def process_cbl_mem_write_cmd(self, data_len):
        bl_write_status = 0
        serial_data = self.serial_manager.read_serial_port(data_len)
        bl_write_status = bytearray(serial_data)
        if bl_write_status[0] == FLASH_PAYLOAD_WRITE_FAILED:
            print_error("\n   Write Status -> Write Failed or Invalid Address")
        elif bl_write_status[0] == FLASH_PAYLOAD_WRITE_PASSED:
            print_success("\n   Write Status -> Write Successful")
            Memory_Write_All = Memory_Write_All and FLASH_PAYLOAD_WRITE_PASSED
        else:
            print_error("Timeout!!, Bootloader is not responding")

    def process_cbl_change_rop_level_cmd(self, data_len):
        bl_change_rop_level_status = 0
        serial_data = self.serial_manager.read_serial_port(data_len)
        if len(serial_data):
            bl_change_rop_level_status = bytearray(serial_data)
            if bl_change_rop_level_status[0] == 0x01:
                print_success("\n   ROP Level Changed")
            elif bl_change_rop_level_status[0] == 0x00:
                print_error("\n   ROP Level Not Changed")
            else:
                print_error("\n   ROP Level -> Unknown Error")

    def update_crc_in_buffer(self, buffer, crc_value, start_index):
        for i in range(4):
            buffer[start_index + i] = word_value_to_byte_value(crc_value, i + 1, 1)

    def calculate_bin_file_length(self, bin_file_path):
        return os.path.getsize(bin_file_path)

    def open_bin_file(self, bin_file_path):
        return open(bin_file_path, 'rb')

