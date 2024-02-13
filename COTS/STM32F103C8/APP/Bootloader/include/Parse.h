/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 10  Feb 2023               *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : Parse.h                    *****************/
/****************************************************************/
#ifndef Parser_H_
#define Parser_H_
/**
 * @brief Maximum size of a line buffer.
 *
 * This macro defines the maximum size of a line buffer used for storing data
 * read from a file or received from a serial port.
 */
#define MAX_LINE_SIZE 100

/**
 * @brief Enumeration representing the states of a parser.
 */
typedef enum {
    PARSER_STATE_START,        /**< Initial state of the parser. */
    PARSER_STATE_STOP,         /**< Final state of the parser. */
    PARSER_STATE_COLON,        /**< State after encountering a colon. */
    PARSER_STATE_DATA,         /**< State for processing data. */
    PARSER_STATE_CHECKSUM1,    /**< State for calculating checksum (part 1). */
    PARSER_STATE_CHECKSUM2     /**< State for calculating checksum (part 2). */
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
 * @param _char The character to be converted.
 * @return The numerical value of the hexadecimal digit represented by the input character.
 *         Returns 0 if the input character is not a valid hexadecimal digit.
 */
u8 hexchar_to_uint8(u8 _char);

/**
 * @brief Parses a line of Intel HEX format and processes the data.
 *
 * This function parses a line of Intel HEX format and processes the data according to the record type.
 * It calculates the checksum and verifies it before performing the required action based on the record type.
 *
 * @param line Pointer to the character array representing the line of Intel HEX format.
 */
void parse_hex_line(const char *line);

#endif /**< Parser_H_ */
