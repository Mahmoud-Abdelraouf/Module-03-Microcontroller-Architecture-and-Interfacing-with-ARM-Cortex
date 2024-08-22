# Understanding CRC (Cyclic Redundancy Check)

## Table of Contents
1. [Introduction](#introduction)
2. [What is CRC?](#what-is-crc)
3. [How CRC Works](#how-crc-works)
   - [Mathematical Background](#mathematical-background)
   - [CRC Calculation Process](#crc-calculation-process)
   - [Alternative CRC Calculation Methods](#alternative-crc-calculation-methods)
4. [Step-by-Step Explanation of CRC Code](#step-by-step-explanation-of-crc-code)
5. [CRC Algorithms](#crc-algorithms)
6. [CRC Use Cases](#crc-use-cases)
7. [Examples of CRC Implementation](#examples-of-crc-implementation)
   - [Example 1: Basic CRC Calculation](#example-1-basic-crc-calculation)
     - [Manual Calculation](#manual-calculation)
   - [Example 2: 4-Byte CRC in Data Packet](#example-2-4-byte-crc-in-data-packet)
     - [Manual Calculation](#manual-calculation-1)
   - [Example 3: Sender and Receiver Data Integrity Check](#example-3-sender-and-receiver-data-integrity-check)
     - [Manual Calculation](#manual-calculation-2)
   - [Example 4: CRC Calculation with Polynomial](#example-4-crc-calculation-with-polynomial)
     - [Manual Calculation](#manual-calculation-3)
   - [Example 5: CRC-8 Calculation with Different Polynomials](#example-5-crc-8-calculation-with-different-polynomials)
   - [Example 6: CRC-16 Calculation for Modbus](#example-6-crc-16-calculation-for-modbus)
   - [Example 7: CRC-32 Calculation for Ethernet](#example-7-crc-32-calculation-for-ethernet)
8. [Conclusion](#conclusion)
9. [References](#references)

## Introduction

Cyclic Redundancy Check (CRC) is a widely used error-detecting code commonly used in digital networks and storage devices to detect accidental changes to raw data. CRCs are designed to detect common types of errors in data transmission, such as single-bit errors or burst errors.

This guide will explain how CRC works, the mathematical concepts behind it, how to calculate it, and provide examples of its application in ensuring data integrity.

## What is CRC?

CRC stands for Cyclic Redundancy Check, a technique used to ensure the integrity of data by generating a short, fixed-size checksum or hash value based on the contents of a block of data. This checksum, called the CRC, is then sent along with the data. The receiver can recalculate the CRC using the same algorithm and compare it with the received CRC to verify data integrity.

### Key Concepts:

- **Data Integrity**: Ensures that data has not been altered during transmission or storage.
- **Error Detection**: Identifies errors in the data, such as flipped bits or corrupt data blocks.
- **Checksum**: A value computed from the data to detect errors.

## How CRC Works

### Mathematical Background

CRC is based on polynomial division over a binary (GF(2)) field. The data is treated as a binary number and divided by a predefined polynomial, known as the generator polynomial, to produce a remainder. This remainder is the CRC checksum.

#### Example:

- **Data**: `11010011101100`
- **Generator Polynomial**: `1011`

The data is divided by the polynomial, and the remainder is the CRC.

### CRC Calculation Process

1. **Append Zeros**: Append the number of zeros equal to the length of the CRC to the end of the data.
2. **Binary Division**: Divide the data by the generator polynomial using binary division (no carry in subtraction).
3. **Remainder**: The remainder after division is the CRC.

The CRC is appended to the data before transmission. The receiver uses the same polynomial to divide the received data (including the CRC). If the remainder is zero, the data is considered valid.

### Alternative CRC Calculation Methods

While the traditional method involves polynomial division, CRC can also be calculated using:

1. **Lookup Tables**: Precomputed tables that map data to CRC values, significantly speeding up the calculation.
2. **Bitwise Operations**: Shifting and XOR operations can be used to calculate CRC without division.
3. **Mathematical Equations**: In some simple cases, CRC can be calculated using algebraic equations based on the properties of binary numbers.

#### Example (Equation-Based CRC):

- **Data**: `1101`
- **Polynomial**: `1011`
  
Using bitwise XOR and shifts, CRC can be manually calculated without performing long division, leveraging the properties of binary arithmetic.

## Step-by-Step Explanation of CRC Code

Let's take a closer look at how a typical CRC calculation function works, using the following basic CRC-8 example:

```c
#include <stdint.h>
#include <stdio.h>

uint8_t calculate_crc8(uint8_t data[], size_t len) {
    uint8_t crc = 0x00;
    for (size_t i = 0; i < len; i++) {
        crc ^= data[i];              // XOR the data byte with the current CRC value
        for (uint8_t j = 0; j < 8; j++) {
            if (crc & 0x80) {         // Check if the highest bit (bit 7) is set
                crc = (crc << 1) ^ 0x07;  // Shift left and XOR with the polynomial (0x07)
            } else {
                crc <<= 1;            // If the highest bit is not set, just shift left
            }
        }
    }
    return crc;
}
```

### Step-by-Step Breakdown

1. **Initialization**:
   - The `crc` variable is initialized to `0x00`.
   - This will hold the CRC value as it is calculated.

2. **Loop through each byte of data**:
   - The outer loop iterates through each byte in the data array.
   - The CRC is XORed with the current byte of data. This operation combines the data into the CRC.

3. **Bitwise Operations**:
   - The inner loop processes each bit of the current data byte.
   - If the highest bit (`0x80`) of the CRC is set, it indicates that the current CRC value must be modified. The CRC is shifted left by one bit and XORed with the polynomial (`0x07`).
   - If the highest bit is not set, the CRC is simply shifted left by one bit.

4. **Return the final CRC value**:
   - After processing all the data, the final CRC value is returned.

This algorithm essentially simulates the polynomial division used in CRC by performing a series of shifts and XORs.

## CRC Algorithms

Different CRC algorithms are defined by the length of the CRC and the polynomial used:

- **CRC-8**: 8-bit CRC with a simple polynomial.
- **CRC-16**: 16-bit CRC with a standard polynomial.
- **CRC-32**: 32-bit CRC commonly used in network communications.

The choice of polynomial affects the error detection capabilities. The most commonly used CRC polynomials are carefully selected to maximize error detection while minimizing computational complexity.

## CRC Use Cases

- **Data Transmission**: Used in communication protocols like Ethernet, USB, and CAN to ensure data integrity.
- **Storage Devices**: Used in hard drives, SSDs, and memory cards to detect data corruption.
- **File Formats**: Common in file formats like ZIP and PNG to check file integrity.

## Examples of CRC Implementation

### Example 1: Basic CRC Calculation

This example demonstrates the basic calculation of a CRC for a given data block using a simple polynomial.

```c
#include <stdint.h>
#include <stdio.h>

uint8_t calculate_crc8(uint8_t data[], size_t len) {
    uint8_t crc = 0x00;
    for (size_t i = 0; i < len; i++) {
        crc ^= data[i];
        for (uint8_t j = 0; j < 8; j++) {
            if (crc & 0x80) {
                crc = (crc << 1) ^ 0x07; // Example polynomial 0x07
            } else {
                crc <<= 1;
            }
        }
    }
    return crc;
}

int main() {
    uint8_t data[] = {0x31, 0x32, 0x33, 0x34}; // ASCII for "1234"
    uint8_t crc = calculate_crc8(data, sizeof(data));
    printf("CRC-8: 0x%02X\n", crc);
    return 0;
}
```

#### Manual Calculation

1. **Data**: `0x31, 0x32, 0x33, 0x34`
2. **Polynomial**: `0x07` (Binary: `0000 0111`)

**Step-by-Step**:
- Convert each byte to binary and perform bitwise XOR with the initial CRC value.
- Apply the polynomial using bitwise shifts and XOR for each bit.
- The final value is the CRC.

### Example 2: 4-Byte CRC in Data Packet

This example demonstrates the calculation and verification of a 4-byte CRC (CRC-32) within a data packet.

```c
#include <stdint.h>
#include <

stdio.h>
#include <string.h>

uint32_t calculate_crc32(uint8_t data[], size_t len) {
    uint32_t crc = 0xFFFFFFFF;
    for (size_t i = 0; i < len; i++) {
        crc ^= data[i];
        for (uint8_t j = 0; j < 8; j++) {
            if (crc & 0x80000000) {
                crc = (crc << 1) ^ 0x04C11DB7; // Polynomial used in Ethernet
            } else {
                crc <<= 1;
            }
        }
    }
    return ~crc;
}

int main() {
    uint8_t data[] = {0x12, 0x34, 0x56, 0x78};
    uint32_t crc = calculate_crc32(data, sizeof(data));
    printf("CRC-32: 0x%08X\n", crc);

    // Append CRC to the data packet
    uint8_t packet[sizeof(data) + sizeof(crc)];
    memcpy(packet, data, sizeof(data));
    memcpy(packet + sizeof(data), &crc, sizeof(crc));

    // Verify CRC at the receiver
    uint32_t received_crc = calculate_crc32(packet, sizeof(packet) - 4);
    if (received_crc == crc) {
        printf("CRC Verification Passed\n");
    } else {
        printf("CRC Verification Failed\n");
    }

    return 0;
}
```

#### Manual Calculation

1. **Data**: `0x12, 0x34, 0x56, 0x78`
2. **Polynomial**: `0x04C11DB7` (Binary: `0000 0100 1100 0001 0001 1101 1011 0111`)

**Step-by-Step**:
- Start with an initial CRC value of `0xFFFFFFFF`.
- For each byte of data, XOR with the CRC and apply the polynomial.
- The final remainder is the CRC-32.

### Example 3: Sender and Receiver Data Integrity Check

This example simulates data transmission with CRC calculation and verification.

```c
#include <stdint.h>
#include <stdio.h>
#include <string.h>

uint16_t calculate_crc16(uint8_t data[], size_t len) {
    uint16_t crc = 0xFFFF;
    for (size_t i = 0; i < len; i++) {
        crc ^= (uint16_t)data[i];
        for (uint8_t j = 0; j < 8; j++) {
            if (crc & 0x0001) {
                crc = (crc >> 1) ^ 0xA001; // Polynomial used in Modbus
            } else {
                crc >>= 1;
            }
        }
    }
    return crc;
}

void sender() {
    uint8_t data[] = "Hello, CRC!";
    uint16_t crc = calculate_crc16(data, strlen((char *)data));
    
    // Simulate sending data and CRC
    printf("Sending Data: %s\n", data);
    printf("Sending CRC: 0x%04X\n", crc);
}

void receiver(uint8_t *received_data, size_t len, uint16_t received_crc) {
    uint16_t crc = calculate_crc16(received_data, len);
    if (crc == received_crc) {
        printf("Received Data: %s\n", received_data);
        printf("CRC Verified: 0x%04X\n", crc);
    } else {
        printf("CRC Verification Failed!\n");
    }
}

int main() {
    sender();
    
    // Simulate receiving the same data
    uint8_t received_data[] = "Hello, CRC!";
    uint16_t received_crc = calculate_crc16(received_data, strlen((char *)received_data));
    
    receiver(received_data, strlen((char *)received_data), received_crc);
    
    return 0;
}
```

#### Manual Calculation

1. **Data**: `"Hello, CRC!"`
2. **Polynomial**: `0xA001` (Binary: `1010 0000 0000 0001`)

**Step-by-Step**:
- Convert each character to its ASCII value and process it with CRC-16.
- XOR each byte with the CRC and shift, applying the polynomial.
- The final CRC value is transmitted with the data.

### Example 4: CRC Calculation with Polynomial

This example demonstrates CRC calculation using a specific polynomial and error checking in a communication system.

```c
#include <stdint.h>
#include <stdio.h>

uint8_t calculate_crc8(uint8_t data[], size_t len, uint8_t polynomial) {
    uint8_t crc = 0xFF;
    for (size_t i = 0; i < len; i++) {
        crc ^= data[i];
        for (uint8_t j = 0; j < 8; j++) {
            if (crc & 0x80) {
                crc = (crc << 1) ^ polynomial;
            } else {
                crc <<= 1;
            }
        }
    }
    return crc;
}

int main() {
    uint8_t data[] = {0xDE, 0xAD, 0xBE, 0xEF};
    uint8_t polynomial = 0x07; // Example polynomial

    uint8_t crc = calculate_crc8(data, sizeof(data), polynomial);
    printf("Calculated CRC: 0x%02X\n", crc);

    // Simulate sending and checking CRC at receiver
    uint8_t received_crc = calculate_crc8(data, sizeof(data), polynomial);
    if (crc == received_crc) {
        printf("CRC check passed.\n");
    } else {
        printf("CRC check failed.\n");
    }

    return 0;
}
```

#### Manual Calculation

1. **Data**: `0xDE, 0xAD, 0xBE, 0xEF`
2. **Polynomial**: `0x07` (Binary: `0000 0111`)

**Step-by-Step**:
- XOR each byte with an initial CRC value.
- Apply the polynomial for each bit by shifting and XORing.
- The remainder is the CRC, which is checked by the receiver.

### Example 5: CRC-8 Calculation with Different Polynomials

This example demonstrates how to calculate a CRC-8 using different polynomials, showcasing how the choice of polynomial affects the result.

```c
#include <stdint.h>
#include <stdio.h>

// CRC-8 calculation with a generic polynomial
uint8_t calculate_crc8_generic(uint8_t data[], size_t len, uint8_t polynomial) {
    uint8_t crc = 0x00;
    for (size_t i = 0; i < len; i++) {
        crc ^= data[i];              // XOR the data byte with the current CRC value
        for (uint8_t j = 0; j < 8; j++) {
            if (crc & 0x80) {         // Check if the highest bit (bit 7) is set
                crc = (crc << 1) ^ polynomial;  // Shift left and XOR with the polynomial
            } else {
                crc <<= 1;            // If the highest bit is not set, just shift left
            }
        }
    }
    return crc;
}

int main() {
    uint8_t data[] = {0xAB, 0xCD, 0xEF};

    // Using different polynomials
    uint8_t crc1 = calculate_crc8_generic(data, sizeof(data), 0x07); // CRC-8-ATM
    uint8_t crc2 = calculate_crc8_generic(data, sizeof(data), 0x1D); // CRC-8-SAE J1850

    printf("CRC-8-ATM: 0x%02X\n", crc1);
    printf("CRC-8-SAE J1850: 0x%02X\n", crc2);

    return 0;
}
```

### Example 6: CRC-16 Calculation for Modbus

This example demonstrates a CRC-16 calculation specifically for the Modbus protocol, which uses the polynomial `0xA001`.

```c
#include <stdint.h>
#include <stdio.h>

uint16_t calculate_crc16_modbus(uint8_t data[], size_t len) {
    uint16_t crc = 0xFFFF;
    for (size_t i = 0; i < len; i++) {
        crc ^= data[i];
        for (uint8_t j = 0; j < 8; j++) {
            if (crc & 0x0001) {
                crc = (crc >> 1) ^ 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc;
}

int main() {
    uint8_t data[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x0A};
    uint16_t crc = calculate_crc16_modbus(data, sizeof(data));
    printf("CRC-16-Modbus: 0x%04X\n", crc);
    return 0;
}
```

### Example 7: CRC-32 Calculation for Ethernet

This example calculates a CRC-32, which is commonly used in Ethernet frames. The polynomial used is `0x04C11DB7`.

```c
#include <stdint.h>
#include <stdio.h>

uint32_t calculate_crc32_ethernet(uint8_t data[], size_t len) {
    uint32_t crc = 0xFFFFFFFF;
    for

 (size_t i = 0; i < len; i++) {
        crc ^= data[i];
        for (uint8_t j = 0; j < 8; j++) {
            if (crc & 0x80000000) {
                crc = (crc << 1) ^ 0x04C11DB7;
            } else {
                crc <<= 1;
            }
        }
    }
    return ~crc;
}

int main() {
    uint8_t data[] = {0x45, 0x00, 0x00, 0x3C, 0x1C, 0x46, 0x40, 0x00};
    uint32_t crc = calculate_crc32_ethernet(data, sizeof(data));
    printf("CRC-32-Ethernet: 0x%08X\n", crc);
    return 0;
}
```

## Hand Calculation Example

Let's solve a simple CRC problem by hand to demonstrate how the process works. We'll use a basic example with a small data block and a simple polynomial.

### Problem Statement

- **Data to be transmitted**: `11010011101100`
- **Generator Polynomial**: `1011` (which represents \( x^3 + x + 1 \))

### Step-by-Step CRC Calculation by Hand

1. **Append Zeros**: First, append zeros to the end of the data. The number of zeros is equal to the degree of the polynomial (in this case, 3 zeros because the highest degree of the polynomial is 3).

   **Original Data**: `11010011101100`
   
   **Appended Zeros**: `11010011101100000`

2. **Perform Binary Division**: We perform binary division of the data by the generator polynomial.

   The division is performed using XOR instead of traditional subtraction. We start by taking the number of bits in the polynomial (4 bits) and comparing them with the leading bits of the data.

   **Step-by-Step Division**:

   - **Initial Bits**: `1101` (first 4 bits of the data)
   - **XOR with Polynomial**: `1101` XOR `1011` = `0110`
   
   Now, we bring down the next bit from the data (which is `0` in this case) to continue the division.

   - **Next Data Segment**: `01100`
   - **XOR with Polynomial**: `0110` XOR `0000` = `0110` (we don't XOR with the polynomial here because the leading bit is `0`)
   
   Continue the process:

   - **Next Data Segment**: `01101`
   - **XOR with Polynomial**: `01101` XOR `1011` = `01010`
   
   Continue the process:

   - **Next Data Segment**: `01011`
   - **XOR with Polynomial**: `01011` XOR `1011` = `01100`
   
   Continue the process:

   - **Next Data Segment**: `01100`
   - **XOR with Polynomial**: `01100` XOR `1011` = `01011`

   This process continues until we process all bits in the appended data.

3. **Remainder**: The remainder after the division is the CRC value. Let's say after performing the complete division, the remainder (CRC) is `001`.

   Since the original data had zeros appended at the end, the final data to be transmitted would be:

   **Transmitted Data**: `11010011101100` + `001` = `11010011101100001`

### Verifying the Data at the Receiver

1. **Received Data**: Let's say the receiver gets the transmitted data `11010011101100001`.

2. **Perform the Division Again**: The receiver performs the same binary division with the received data using the same polynomial `1011`.

   If the remainder is `000`, then the data is considered valid. If the remainder is anything other than `000`, an error is detected.

### Summary of the Hand Calculation

- **Initial Data**: `11010011101100`
- **Polynomial**: `1011`
- **Appended Zeros**: `11010011101100000`
- **Division Process**:
  - XOR each segment with the polynomial.
  - Continue until all bits are processed.
- **CRC (Remainder)**: `001`
- **Transmitted Data**: `11010011101100001`

### Explanation

This is a simple, step-by-step calculation of CRC by hand. The key is to perform the binary division using XOR and to treat the polynomial as a binary number. The resulting remainder is the CRC that is appended to the data for transmission.

At the receiver's end, the same division process is performed. If the remainder after this division is zero, the data is assumed to be error-free.

This method is useful for small examples and understanding the fundamentals of CRC. In practice, for larger data, CRC is calculated using hardware or software routines that handle large amounts of data efficiently.

## Conclusion

CRC is a powerful tool for detecting errors in data transmission and storage. It is widely used in various fields, including networking, storage, and communications. Understanding how CRC works and how to implement it can greatly enhance the reliability of your systems.

By following the examples provided, you can implement CRC in your own projects, ensuring data integrity and reliability in your applications. The manual calculations demonstrate the underlying process, allowing you to gain a deeper understanding of how CRC functions.

## References

- [Wikipedia: Cyclic Redundancy Check](https://en.wikipedia.org/wiki/Cyclic_redundancy_check)
- [Introduction to CRC and How to Implement It in C](https://www.nongnu.org/avr-libc/user-manual/group__util__crc.html)
- [STM32 CRC Calculation](https://www.st.com/resource/en/application_note/an4187-crc-32-generation-implementation-on-stm32-microcontrollers-stmicroelectronics.pdf)
- [Explaining and Coding CRC Algorithms](https://barrgroup.com/Embedded-Systems/How-To/CRC-Math-Theory)
