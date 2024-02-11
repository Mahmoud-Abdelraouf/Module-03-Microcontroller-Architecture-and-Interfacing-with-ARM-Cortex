/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 10 Feb 2024                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : FPEC_program.h             *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "FPEC_interface.h"
#include "FPEC_private.h"
#include "FPEC_config.h"
/*****************************< Function Implementations *****************************/
void FPEC_EraseAppArea(void) {
	u8 i;
	
	for (i = 4; i < 64; i++) {
		FPEC_FlashPageErase(i);
	}
}

void FPEC_FlashPageErase(u8 PageNumber) {
	/**< Wait Busy Flag */
	while (GET_BIT(FPEC->SR, 0) == 1);

	/**< Check if FPEC is locked or not */
	if ( GET_BIT(FPEC->CR, 7) == 1 ) {
		FPEC -> KEYR = 0x45670123;
		FPEC -> KEYR = 0xCDEF89AB;
	}
	
	/**< Page Erase Operation */
	SET_BIT(FPEC->CR,1);

	/**< Write Page address */
	FPEC->AR = ((u32)(PageNumber * 1024) + 0x08000000);

	/**< Start operation */
	SET_BIT(FPEC->CR,6);

	/**< Wait Busy Flag */
	while (GET_BIT(FPEC->SR, 0) == 1);

	/**< EOP */
	SET_BIT(FPEC->SR, 5);
	CLR_BIT(FPEC->CR, 1);
}

void FPEC_FlashWrite(u32 Address, u16 *Data, u8 Length) {
	u8 i;
	volatile u16 Temp;

	while (GET_BIT(FPEC->SR, 0) == 1);

	/**< Check if FPEC is locked or not */
	if ( /**< FPEC_CR->BitAccess.LOCK == 1 */ GET_BIT(FPEC->CR, 7) == 1 ) {
		FPEC -> KEYR = 0x45670123;
		FPEC -> KEYR = 0xCDEF89AB;
	}
	
	
	for (i = 0; i < Length; i++) {
		/**< Write Flash Programming */
		SET_BIT(FPEC->CR, 0);

		/**< Half word operation */
		Temp = Data[i];
		(*((volatile u16*)Address)) = Data[i];
		Address += 2 ;

		/**< Wait Busy Flag */
		while (GET_BIT(FPEC->SR, 0) == 1);
	
		/**< EOP */
		SET_BIT(FPEC->SR, 5);
		CLR_BIT(FPEC->CR, 0);
	}

}
