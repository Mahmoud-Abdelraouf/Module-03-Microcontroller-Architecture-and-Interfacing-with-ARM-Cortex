# Using ST Utilities in Ubuntu CLI

This guide will help you transition from using ST utilities on Windows to utilizing them on Ubuntu. STMicroelectronics provides a variety of tools that are commonly used for programming, debugging, and developing with STM32 microcontrollers. This README will focus on how to set up and use these tools via the terminal on a Linux-based system like Ubuntu.

## Table of Contents
1. [Introduction](#introduction)
2. [Installing ST Utilities via APT](#installing-st-utilities-via-apt)
   - [1. STM32CubeProgrammer](#1-stm32cubeprogrammer)
   - [2. ST-Link Tools](#2-st-link-tools)
   - [3. OpenOCD](#3-openocd)
3. [Using STM32_Programmer_CLI](#using-stm32_programmer_cli)
   - [1. Basic Usage](#1-basic-usage)
   - [2. Flashing Firmware](#2-flashing-firmware)
   - [3. Reading and Writing Memory](#3-reading-and-writing-memory)
   - [4. Erasing Memory](#4-erasing-memory)
   - [5. Resetting the Device](#5-resetting-the-device)
   - [6. Advanced Usage Tips](#6-advanced-usage-tips)
4. [STM32 Debugging Best Practices](#stm32-debugging-best-practices)
   - [1. General Debugging Tips](#1-general-debugging-tips)
   - [2. Using Breakpoints Effectively](#2-using-breakpoints-effectively)
   - [3. Step-by-Step Debugging](#3-step-by-step-debugging)
   - [4. Using Watchpoints and Observing Variables](#4-using-watchpoints-and-observing-variables)
   - [5. Handling Hard Faults](#5-handling-hard-faults)
5. [Automating Tasks with Makefiles](#automating-tasks-with-makefiles)
6. [Troubleshooting](#troubleshooting)
7. [References](#references)

---

## Introduction

ST utilities are essential tools for developing, debugging, and programming STM32 microcontrollers. If you're accustomed to using these tools on Windows, this guide will help you transition to using them in a Linux environment via the terminal.

## Installing ST Utilities via APT

### 1. STM32CubeProgrammer

**STM32CubeProgrammer** is an all-in-one tool for flashing and debugging STM32 microcontrollers. It can be installed on Ubuntu by downloading the package from STMicroelectronics.

#### Installation Steps:

1. **Download STM32CubeProgrammer:**
   - Visit the official [STM32CubeProgrammer download page](https://wiki.stmicroelectronics.cn/stm32mpu/wiki/STM32CubeProgrammer) on the STMicroelectronics wiki.
   - Download the latest ZIP file for Linux: `en.stm32cubeprg-lin-v2-17-0.zip`.

2. **Extract the ZIP file:**
   - Open a terminal and navigate to the directory where the ZIP file was downloaded.
   - Extract the contents using the following command:
     ```sh
     unzip en.stm32cubeprg-lin-v2-17-0.zip
     ```

3. **Install the package:**
   - After extracting, navigate to the extracted directory:
     ```sh
     cd en.stm32cubeprg-lin-v2-17-0/
     ```
   - Run the installer script with `sudo` to install it:
     ```sh
     sudo ./SetupSTM32CubeProgrammer-2.17.0.linux
     ```

4. **Add STM32CubeProgrammer to the PATH:**
   After the installation is complete, you need to add the STM32CubeProgrammer binary to your PATH environment variable so that it can be used from any terminal session.

   - **Temporarily for the current terminal session:**
     ```sh
     export PATH=~/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin:$PATH
     ```

   - **Permanently by creating a symbolic link:**
     First, create the `~/bin` directory if it doesn't exist:
     ```sh
     mkdir -p ~/bin
     ```
     Then, create a symbolic link in the `~/bin` directory:
     ```sh
     ln -s ~/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin/STM32_Programmer_CLI ~/bin/STM32_Programmer_CLI
     ```
     This will allow you to use `STM32_Programmer_CLI` from any terminal without having to modify the PATH in each session.

5. **Install dependencies if needed:**
   - If you encounter dependency issues, resolve them with:
     ```sh
     sudo apt-get install -f
     ```

6. **Verify the installation:**
   - Run the following command to check if the installation was successful:
     ```sh
     STM32_Programmer_CLI --version
     ```

### 2. ST-Link Tools

**ST-Link tools** are available via the `apt` package manager, making them easy to install on Ubuntu.

#### Installation Steps:

1. **Install ST-Link tools:**
   ```sh
   sudo apt-get install stlink-tools
   ```

2. **Verify the installation:**
   - Check if the tools are installed correctly by running:
     ```sh
     st-info --version
     st-flash --version
     ```

These tools include:
- `st-info`: Tool for getting information about connected ST-Link devices.
- `st-flash`: Tool for flashing STM32 microcontrollers.
- `st-util`: GDB server for debugging with ST-Link.

### 3. OpenOCD

**OpenOCD** is widely used for debugging and flashing embedded systems and is available directly via `apt`.

#### Installation Steps:

1. **Install OpenOCD:**
   ```sh
   sudo apt-get install openocd
   ```

2. **Verify the installation:**
   - Check if OpenOCD is installed correctly by running:
     ```sh
     openocd --version
     ```

## Using STM32_Programmer_CLI

### 1. Basic Usage

`STM32_Programmer_CLI` is a versatile command-line tool for interacting with STM32 microcontrollers. Here are some basic commands to get started:

- **Display help:**
  ```sh
  STM32_Programmer_CLI -h
  ```
  This command shows the help menu, listing all available commands and options.

- **Check the connected device:**
  ```sh
  STM32_Programmer_CLI -l
  ```
  This lists all STM32 devices connected to your system, along with their details.

### 2. Flashing Firmware

Flashing firmware is one of the most common tasks. Here are some examples:

- **Flash a binary file to the default address:**
  ```sh
  STM32_Programmer_CLI -c port=SWD -d path/to/firmware.bin -v -rst
  ```
  This flashes the firmware and then verifies it, followed by a device reset.

- **Flash to a specific address:**
  ```sh
  STM32_Programmer_CLI -c port=SWD -d path/to/firmware.bin -a 0x08004000 -v -rst
  ```
  Use this to flash the firmware to the specific address `0x08004000`.

- **Flash an Intel HEX file:**
  ```sh
  STM32_Programmer_CLI -c port=SWD -d path/to/firmware.hex -v -rst
  ```
  This example shows how to flash a firmware file in Intel HEX format.

### 3. Reading and Writing Memory

You can also use `STM32_Programmer_CLI` to read and write directly to memory:

- **Read memory content:**
  ```sh
  STM32_Programmer_CLI -c port=SWD -r8 0x08000000 256
  ```
  This reads 256 bytes from the memory address `0x08000000` and displays them in the terminal.

- **Write a binary file to memory:**
  ```sh
  STM32_Programmer_CLI -c port=SWD -w path/to/data.bin 0x08004000 -v
  ```
  This writes the contents of `data.bin` to memory starting at address `0x08004000`.

### 4. Erasing Memory

You might need to erase memory before flashing new firmware:

- **Erase the entire chip:**
  ```sh
  STM32_Programmer_CLI -c port=SWD -e all
  ```
  This command erases all memory on the microcontroller.

- **Erase a specific sector:**
  ```sh
  STM32_Programmer_CLI -c port=SWD -e sector 1
  ```
  Erases only the specified sector (e.g., sector 1).

### 5. Resetting the Device

Resetting the device is often necessary after flashing or debugging:

- **Reset the microcontroller:**
  ```sh
  STM32_Programmer_CLI -c port=SWD -rst
  ```
  This command resets the connected microcontroller.

- **Reset and halt (useful for debugging):**
  ```sh
  STM32_Programmer_CLI -c port=SWD -rst -halt
  ```
  Resets the microcontroller and then halts it

, useful for debugging.

### 6. Advanced Usage Tips

- **Bootloader operations:**
  You can interact with the bootloader of STM32 devices using UART or USB interfaces.

  ```sh
  STM32_Programmer_CLI -c port=USB1 -d path/to/firmware.bin -v -rst
  ```
  This command uses the USB bootloader interface to flash firmware.

- **Mass erase with automatic chip detection:**
  ```sh
  STM32_Programmer_CLI -c port=SWD -me
  ```
  Automatically detects the chip and performs a mass erase.

- **Reading option bytes:**
  ```sh
  STM32_Programmer_CLI -c port=SWD -ob displ
  ```
  Displays the option bytes of the connected STM32 device.

- **Writing option bytes:**
  ```sh
  STM32_Programmer_CLI -c port=SWD -ob RDP=0xAA
  ```
  Writes option bytes, for example setting the Read Protection Level to 0xAA (level 1).

## STM32 Debugging Best Practices

### 1. General Debugging Tips

- **Plan Before Debugging:** Before you start a debugging session, clearly understand the problem you're trying to solve. Identify symptoms and isolate the problematic areas in your code.
- **Keep Your Code Modular:** Modular code helps in isolating issues quickly. Debugging is easier when you have clear boundaries in your code.
- **Use Debug Messages:** Insert `printf` or similar debug statements to trace code execution and monitor variable values.

### 2. Using Breakpoints Effectively

- **Set Breakpoints Strategically:** Place breakpoints at critical points in your code, such as the beginning of loops, before and after function calls, or at error-handling code.
- **Conditional Breakpoints:** Use conditional breakpoints to pause execution only when specific conditions are met, which can be very useful in tracking down hard-to-find bugs.

### 3. Step-by-Step Debugging

- **Step Into Functions:** Use the "step into" command to debug inside a function call.
- **Step Over Functions:** Use "step over" to execute a function call without stepping into it, useful for skipping standard library functions.
- **Step Out of Functions:** Use "step out" to complete the current function and pause execution at the return point.

### 4. Using Watchpoints and Observing Variables

- **Watchpoints:** Set watchpoints to pause execution when a specific variable changes. This is crucial for tracking down issues related to variable modification.
- **Monitor Variables:** Continuously monitor critical variables during execution to ensure they hold expected values.

### 5. Handling Hard Faults

- **Analyze Hard Faults:** When a hard fault occurs, analyze the stack trace to identify the exact location in the code where the fault occurred.
- **Use Fault Handlers:** Implement fault handlers to capture and log detailed information when faults occur, helping you diagnose the root cause.

## Automating Tasks with Makefiles

To streamline your workflow, you can use Makefiles to automate the build, flash, and debug processes.

### Example Makefile:
```makefile
CC = arm-none-eabi-gcc
CFLAGS = -O2 -mcpu=cortex-m4 -mthumb

TARGET = your_firmware
SRC = main.c startup.c
OBJ = $(SRC:.c=.o)

all: $(TARGET).bin

$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET).bin: $(TARGET).elf
	arm-none-eabi-objcopy -O binary $< $@

flash: $(TARGET).bin
	STM32_Programmer_CLI -c port=SWD -d $(TARGET).bin -v -rst

flash_custom: $(TARGET).bin
	STM32_Programmer_CLI -c port=SWD -d $(TARGET).bin -a 0x08004000 -v -rst

clean:
	rm -f $(OBJ) $(TARGET).elf $(TARGET).bin
```

Run `make flash` to compile and flash the firmware to the default address, or `make flash_custom` to flash to a custom address.

## Troubleshooting

### Common Issues:
- **Permission Denied:** Ensure you have the necessary permissions to access USB devices. You might need to add your user to the `dialout` group:
  ```sh
  sudo usermod -aG dialout $USER
  ```

- **Device Not Found:** Make sure your ST-LINK is connected and recognized by the system. Use `lsusb` to check.

- **Symbolic Link Creation Error:**
  If you encounter an error like `ln: failed to create symbolic link`, ensure that the directory you are linking to (`~/bin/`) exists. You can create it with:
  ```sh
  mkdir -p ~/bin
  ```
  Then, try creating the symbolic link again.

- **OpenOCD Connection Issues:** Ensure that the correct configuration files for your ST-Link and target MCU are being used. The configuration files can usually be found in `/usr/share/openocd/scripts/`.

## References

- [STM32CubeProgrammer Documentation](https://www.st.com/en/development-tools/stm32cubeprog.html)
- [STM32CubeProgrammer Download](https://wiki.stmicroelectronics.cn/stm32mpu/wiki/STM32CubeProgrammer)
- [ST-Link GitHub Repository](https://github.com/stlink-org/stlink)
- [OpenOCD User's Guide](http://openocd.org/documentation)
- [GNU Arm Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm)
