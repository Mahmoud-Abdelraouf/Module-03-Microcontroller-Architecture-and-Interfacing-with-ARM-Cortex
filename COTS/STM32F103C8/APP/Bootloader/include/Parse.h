/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 10  Feb 2023               *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : Parser.h                   *****************/
/****************************************************************/

#define MAX_LINE_SIZE 100

typedef enum {
    PARSER_STATE_START,
    PARSER_STATE_COLON,
    PARSER_STATE_DATA,
    PARSER_STATE_CHECKSUM1,
    PARSER_STATE_CHECKSUM2
} ParserState_t;


/**
 * @brief Convert ASCII character to its hexadecimal representation.
 *
 * This function takes an ASCII character as input and converts it to its
 * hexadecimal representation. It handles both uppercase and lowercase
 * letters A-F.
 *
 * @param ascii The ASCII character to be converted.
 * @return The hexadecimal representation of the input ASCII character.
 *         Returns 0xFF if the input character is invalid.
 */
u8 ascii_to_hex(u8 ascii);


/**
 * @brief Convert a hexadecimal character to an 8-bit unsigned integer.
 *
 * This function takes a character representing a hexadecimal digit ('0' to '9', 'A' to 'F', or 'a' to 'f')
 * as input and converts it to its corresponding 8-bit unsigned integer value.
 *
 * @param ch The character to be converted.
 * @return The numerical value of the hexadecimal digit represented by the input character.
 *         Returns 0 if the input character is not a valid hexadecimal digit.
 */
u8 hexchar_to_uint8(u8 ch);