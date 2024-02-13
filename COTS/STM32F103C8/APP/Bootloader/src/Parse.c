/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 10 Feb 2024                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : Parse.c                    *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include <stdio.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "FPEC_interface.h"
/*****************************< APP *****************************/
#include "Parse.h"
/*****************************< Function Implementations *****************************/
u8 ascii_to_hex(u8 ascii) {
    if (ascii >= '0' && ascii <= '9') {
        return ascii - '0';
    } else if (ascii >= 'A' && ascii <= 'F') {
        return ascii - 'A' + 10;
    } else if (ascii >= 'a' && ascii <= 'f') {
        return ascii - 'a' + 10;
    } 
    return 0xFF; /**< return 0xFF to indicate error */ 
}

u8 hexchar_to_uint8(u8 _char) {
    if (_char >= '0' && _char <= '9') {
        return _char - '0';
    } else if (_char >= 'A' && _char <= 'F') {
        return _char - 'A' + 10;
    } else if (_char >= 'a' && _char <= 'f') {
        return _char - 'a' + 10;
    }
    return 0; /**< Invalid hex character, return 0 */ 
}

void parse_hex_line(const char *line) {
    static uint32_t lineCount = 0;
    uint8_t data[MAX_LINE_SIZE];     /**< Buffer to store data bytes */
    uint8_t checksum = 0;            /**< Checksum calculated from the line */
    uint8_t checksumToCmp = 0;       /**< Checksum to compare */
    uint8_t byteCount, recordType;   /**< Variables to store byte count and record type */
    uint32_t address;                /**< Address extracted from the line */
    uint16_t lowerAddressPart;       /**< Lower part of the address */
    uint16_t upperAddressPart;       /**< Upper part of the address */
    int temp = 0;                    /**< Temp to save the counter */
    int i = 0;                       /**< Loop counter */
    lineCount++;
    ParserState_t state = PARSER_STATE_START;
    while (line[i] != '\n') {
        switch (state) {
            case PARSER_STATE_START:
                if (line[i] == ':') {
                    i++; /**< Increment i to move to the next character in the line */
                } else if(line[i] != ':') {
                    
                }
                state = PARSER_STATE_COLON;
                break;
            case PARSER_STATE_COLON:
                byteCount = (hexchar_to_uint8(line[i]) << 4) | hexchar_to_uint8(line[i+1]);
                i += 2; /**< Increment i by 2 to move to the next pair of characters */
                lowerAddressPart = (hexchar_to_uint8(line[i]) << 12) | (hexchar_to_uint8(line[i+1]) << 8)
                          | (hexchar_to_uint8(line[i+2]) << 4) | hexchar_to_uint8(line[i+3]);
                i += 4; /**< Increment i by 4 to move to the next address characters */
                recordType = (hexchar_to_uint8(line[i]) << 4) | hexchar_to_uint8(line[i+1]);
                i += 2; /**< Increment i by 2 to move to the next record type characters */

                if(recordType == (uint8_t)04) {
                    lowerAddressPart = (hexchar_to_uint8(line[i]) << 12) | (hexchar_to_uint8(line[i+1]) << 8)
                          | (hexchar_to_uint8(line[i+2]) << 4) | hexchar_to_uint8(line[i+3]);
                }
                
                state = PARSER_STATE_DATA;
                break;
            case PARSER_STATE_DATA:
                for (int j = 0; j < byteCount; j++) {
                    data[j] = (hexchar_to_uint8(line[i]) << 4) | hexchar_to_uint8(line[i+1]);
                    i += 2; /**< Increment i by 2 to move to the next pair of data characters */
                    checksum += data[j];
                }
                checksumToCmp = (hexchar_to_uint8(line[i]) << 4) | hexchar_to_uint8(line[i+1]);
                state = PARSER_STATE_CHECKSUM1;
                break;
            case PARSER_STATE_CHECKSUM1:
                temp = 1;
                for(int j = 0; j < 4; j++) {
                    checksum += (hexchar_to_uint8(line[temp]) << 4) | hexchar_to_uint8(line[temp+1]);
                    temp += 2; /**< Increment i by 2 to move to the next pair of checksum characters */
                }
                checksum = (~(checksum & 0xFF) + 1) & 0xFF;
                state = PARSER_STATE_CHECKSUM2;
                break;
            case PARSER_STATE_CHECKSUM2:
                if (checksumToCmp == checksum) {
                    /**< The business logic */
                    switch (recordType) {
                        case 0: /**< Data Record */
                            address = (upperAddressPart << 4) | lowerAddressPart;
                            MCAL_FPEC_FlashWrite(address, ((uint16_t *)data), (byteCount / 2.0));
                            break;
                        case 4: /**< External Address (High Part) */
                            upperAddressPart = lowerAddressPart;                            
                            break;
                        default:
                            // TODO: Handle the other cases: 01, 02, 03, 05
                            break;
                    }
                } else {
                	// TODO: create a flags to indicate where  the error at and what is the correct value should be
                    //fprintf(stderr, "Error in line: %ld, The checksum should be: %d\n", lineCount, checksumToCmp);
                }
                state = PARSER_STATE_STOP;
                break;
            case PARSER_STATE_STOP:
            	return;
            	break;
            default:
                state = PARSER_STATE_START;
                break;
        }
    }
}
