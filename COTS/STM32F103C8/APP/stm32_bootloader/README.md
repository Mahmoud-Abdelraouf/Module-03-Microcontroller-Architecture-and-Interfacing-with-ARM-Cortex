# **STM32 Bootloader Command-Line Tool**

This Python-based command-line utility is designed to facilitate communication with the STM32F407 bootloader over a serial interface. The tool allows users to execute a wide range of commands, such as retrieving version information, erasing flash memory, writing to memory, and more. The project is structured for modularity and maintainability, making it easy to extend and customize.

## **Key Features**

- **Comprehensive Bootloader Interaction**: Execute various bootloader commands including version retrieval, flash memory operations, and memory writes.
- **Cross-Platform Serial Communication**: Communicate with STM32 devices over a serial connection, with compatibility for Linux systems.
- **Modular Design for Ease of Maintenance**: The tool is organized into distinct modules, each responsible for specific functionalities such as serial communication, bootloader command processing, utility functions, and configuration.

## **Project Structure**

```plaintext
stm32_bootloader/
├── README.md
├── LICENSE
├── main.py
├── serial_communication.py
├── bootloader_commands.py
├── utilities.py
└── config.py
```

## **Installation Instructions**

### **1. Clone the Repository**

Start by cloning the repository to your local machine:

```bash
git clone https://github.com/Mahmoud-Abdelraouf/Module-03-Microcontroller-Architecture-and-Interfacing-with-ARM-Cortex.git
cd Module-03-Microcontroller-Architecture-and-Interfacing-with-ARM-Cortex/COTS/STM32F103C8/APP/stm32_bootloader
```

### **2. Ensure Python 3 is Installed**

Verify that Python 3 is installed on your system:

```bash
python3 --version
```

If Python 3 is not installed, you can download it from the [official Python website](https://www.python.org/downloads/).

### **3. Install Required Python Packages**

Install the necessary Python packages using `pip`:

```bash
pip install pyserial
```

### **4. Connect Your STM32 Device**

Connect your STM32F407 device to your computer using a USB-to-serial adapter or equivalent interface. Ensure the device is in bootloader mode.

## **Usage Guide**

### **Running the Tool**

To run the tool, navigate to the project directory and execute:

```bash
python3 main.py
```

### **Selecting the Serial Port**

When prompted, enter the serial port name of your connected STM32 device (e.g., `/dev/ttyUSB0` on Linux).

### **Executing Bootloader Commands**

The tool will display a menu of available bootloader commands. Enter the corresponding number to send a command to the bootloader. Follow any additional prompts as required.

### **Examples of Common Commands**

- **Retrieve Bootloader Version**:
  - Select `1` to send the `CBL_GET_VER_CMD` command, which retrieves the bootloader version.

- **Erase Flash Memory**:
  - Select `6` to send the `CBL_FLASH_ERASE_CMD` command, allowing you to erase sectors of the flash memory.

- **Write Data to Memory**:
  - Select `7` to send the `CBL_MEM_WRITE_CMD` command, enabling you to write a binary file to the device’s memory.

## **Configuration**

The `config.py` file allows you to configure various settings for the tool:

- **BAUD_RATE**: Default is `115200`.
- **TIMEOUT**: Default is `2` seconds.

These settings can be adjusted to meet the specific needs of your application.

## **License**

This project is licensed under the MIT License. For more details, refer to the `LICENSE` file.

## **Contributing**

We welcome contributions from the community! If you encounter any issues or have suggestions for improvements, please submit them via issues or pull requests on our [GitHub repository](https://github.com/your-username/stm32_bootloader).

## **Troubleshooting**

- **Serial Port Issues**: Ensure you have entered the correct serial port name and that your STM32 device is in bootloader mode.
- **Permission Errors on Linux**: You may need to run the tool with `sudo` or add your user to the `dialout` group to access serial ports.
- **Timeouts**: If timeouts occur, verify the connection and ensure the STM32 device is correctly configured and powered.

---

This README is designed to provide a clear and professional overview of the STM32 Bootloader Command-Line Tool. By following the detailed installation and usage instructions, you should be able to easily set up and start using the tool to communicate with your STM32 device.


