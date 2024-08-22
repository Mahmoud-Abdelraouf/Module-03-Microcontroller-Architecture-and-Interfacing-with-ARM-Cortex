# Configuration for Serial Communication
BAUD_RATE = 115200
TIMEOUT = 2

# Bootloader Commands
CBL_GET_VER_CMD = 0x10
CBL_GET_HELP_CMD = 0x11
CBL_GET_CID_CMD = 0x12
CBL_GET_RDP_STATUS_CMD = 0x13
CBL_GO_TO_ADDR_CMD = 0x14
CBL_FLASH_ERASE_CMD = 0x15
CBL_MEM_WRITE_CMD = 0x16
CBL_ED_W_PROTECT_CMD = 0x17
CBL_MEM_READ_CMD = 0x18
CBL_READ_SECTOR_STATUS_CMD = 0x19
CBL_OTP_READ_CMD = 0x20
CBL_CHANGE_ROP_Level_CMD = 0x21

# Status Codes
INVALID_SECTOR_NUMBER = 0x00
VALID_SECTOR_NUMBER = 0x01
UNSUCCESSFUL_ERASE = 0x02
SUCCESSFUL_ERASE = 0x03

FLASH_PAYLOAD_WRITE_FAILED = 0x00
FLASH_PAYLOAD_WRITE_PASSED = 0x01

# Command Descriptions
COMMAND_NAMES = {
    CBL_GET_VER_CMD: "Get Bootloader Version",
    CBL_GET_HELP_CMD: "Get Supported Commands",
    CBL_GET_CID_CMD: "Get Chip Identification Number",
    CBL_GET_RDP_STATUS_CMD: "Get Read Protection Level",
    CBL_GO_TO_ADDR_CMD: "Jump to Specified Address",
    CBL_FLASH_ERASE_CMD: "Erase Flash Memory",
    CBL_MEM_WRITE_CMD: "Write to Memory",
    CBL_ED_W_PROTECT_CMD: "Enable/Disable Write Protection",
    CBL_MEM_READ_CMD: "Read from Memory",
    CBL_READ_SECTOR_STATUS_CMD: "Get Sector Protection Status",
    CBL_OTP_READ_CMD: "Read from OTP Area",
    CBL_CHANGE_ROP_Level_CMD: "Change Read Protection Level"
}

