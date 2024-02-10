/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 10 Feb 2024                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : FPEC_interface.h           *****************/
/****************************************************************/
#ifndef FPEC_INTERFACE_
#define FPEC_INTERFACE_

/**
 * @brief Erase the application area in the Flash memory.
 *
 * This function erases the application area in the Flash memory.
 * It iterates over the pages from 4 to 63 and erases each page using FPEC_FlashPageErase().
 *
 * @note This function assumes that FPEC_FlashPageErase() is defined elsewhere.
 *
 * @return None.
 */
void FPEC_EraseAppArea(void);

/**
 * @brief Erase a page in the Flash memory.
 *
 * This function erases a page in the Flash memory specified by the given page number.
 * It waits for the Flash controller to become ready, unlocks the Flash if it's locked,
 * initiates the page erase operation, waits for the operation to complete, and clears
 * the End of Operation (EOP) flag after the erase operation.
 *
 * @param PageNumber The page number to be erased.
 * @note This function assumes that the Flash controller (FPEC) peripheral is properly configured and initialized.
 * @return None.
 */	
void FPEC_FlashPageErase(u8 PageNumber);

/**
 * @brief Write data to Flash memory.
 *
 * This function writes data to the Flash memory starting from the specified address.
 * It iterates over the data array, writes each element to the Flash memory as a half word,
 * and waits for the operation to complete before proceeding to the next element.
 *
 * @param Address The starting address in Flash memory where data will be written.
 * @param Data Pointer to the data array containing the data to be written.
 * @param Length The number of elements in the data array.
 * @note This function assumes that the Flash controller (FPEC) peripheral is properly configured and initialized.
 * @return None.
 */
void FPEC_FlashWrite(u32 Address, u16* Data, u8 Length);

#endif /**< FPEC_INTERFACE_ */
