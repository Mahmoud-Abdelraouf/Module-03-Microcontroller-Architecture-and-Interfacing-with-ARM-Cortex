/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 10  Feb 2023               *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : Parser.c                   *****************/
/****************************************************************/

/*****************************< LIB *****************************/
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
    } else {
        /**< Invalid character */ 
        return 0xFF; /**< return 0xFF to indicate error */ 
    }
}

u8 hexchar_to_uint8(u8 ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    } else if (ch >= 'A' && ch <= 'F') {
        return ch - 'A' + 10;
    } else if (ch >= 'a' && ch <= 'f') {
        return ch - 'a' + 10;
    }
    return 0; /**< Invalid hex character, return 0 */ 
}

void parse_hex_line(const char *line) {
    uint8_t data[MAX_LINE_SIZE];
    uint8_t checksum = 0;
    uint8_t checksumToCmp = 0;
    uint8_t byte_count, record_type;
    uint16_t address;
    int i = 0;
    ParserState_t state = PARSER_STATE_START;

    while (line[i] != '\0') {
        switch (state) {
            case PARSER_STATE_START:
                if (line[i] == ':') {
                    state = PARSER_STATE_COLON;
                    i++; /**< Increment i to move to the next character in the line */
                }
                break;
            case PARSER_STATE_COLON:
                byte_count = (hexchar_to_uint8(line[i]) << 4) | hexchar_to_uint8(line[i+1]);
                i += 2; /**< Increment i by 2 to move to the next pair of characters */
                address = (hexchar_to_uint8(line[i]) << 12) | (hexchar_to_uint8(line[i+1]) << 8)
                          | (hexchar_to_uint8(line[i+2]) << 4) | hexchar_to_uint8(line[i+3]);
                i += 4; /**< Increment i by 4 to move to the next address characters */
                record_type = (hexchar_to_uint8(line[i]) << 4) | hexchar_to_uint8(line[i+1]);
                i += 2; /**< Increment i by 2 to move to the next record type characters */
                state = PARSER_STATE_DATA;
                break;
            case PARSER_STATE_DATA:
                for (int j = 0; j < byte_count; j++) {
                    data[j] = (hexchar_to_uint8(line[i]) << 4) | hexchar_to_uint8(line[i+1]);
                    i += 2; /**< Increment i by 2 to move to the next pair of data characters */
                    checksum += data[j];
                }
                checksumToCmp = (hexchar_to_uint8(line[i]) << 4) | hexchar_to_uint8(line[i+1]);
                state = PARSER_STATE_CHECKSUM1;
                break;
            case PARSER_STATE_CHECKSUM1:
                i = 1;
                for(int j = 0; j < 3; j++) {
                    checksum += (hexchar_to_uint8(line[i]) << 4) | hexchar_to_uint8(line[i+1]);
                    i += 2; /**< Increment i by 2 to move to the next pair of checksum characters */
                }
                state = PARSER_STATE_CHECKSUM2;
                break;
            case PARSER_STATE_CHECKSUM2:
                if (checksumToCmp == checksum) {
                    // Process data here (data[], byte_count, address, record_type)
                    // You can write this to flash or perform any other operation.
                } else {
                    // Checksum error
                }
                state = PARSER_STATE_START;
                break;
            default:
                state = PARSER_STATE_START;
                break;
        }
    }
}