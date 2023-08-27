/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**< MCAL */
#include "RCC_interface.h"

int main(void)
{
	/**< Init RCC */
	Mcal_Rcc_InitSysClock();
	
	/**< Enable GPIO A */
	Mcal_Rcc_EnablePeripheral(RCC_APB2ENR_IOPAEN, RCC_APB2);
	
	for(;;);
}
