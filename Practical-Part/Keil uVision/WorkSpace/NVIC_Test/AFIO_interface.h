/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 12 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : NVIC_config.h              *****************/
/****************************************************************/
#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_



#define AFIO_PORTA          0
#define AFIO_PORTB          1
#define AFIO_PORTC          2



/**
 * @defgroup AFIO_Remap_Options AFIO Remap Options
 * @{
 */

/**
 * @brief Enumeration of AFIO remap configuration options.
 *
 * This enumeration defines different remap configurations for the AFIO peripheral.
 * Users can select a configuration that suits their needs and customize pin assignments.
 * The SWJ_CFG value and pin status are provided for each configuration.
 *
 * @note Users should select one of these options when configuring the AFIO remap settings.
 * 
 * @note User options include:
 *                      - AFIO_REMAP_NONE: No remap (default).
 *                      - AFIO_REMAP_FULL: Full SWJ (JTAG-DP + SW-DP) but without NJTRST.
 *                      - AFIO_REMAP_PARTIAL: JTAG-DP Disabled and SW-DP Enabled.
 *                      - AFIO_REMAP_CUSTOM: Custom remap (user-defined).
 *
 * @note Pin Availability for Each Configuration:
 *                      - AFIO_REMAP_NONE:
 *                            - PA13/JTMS/SWDIO (Unavailable)
 *                            - PA14/JTCK/SWCLK (Unavailable)
 *                            - PA15/JTDI (Unavailable)
 *                            - PB3/JTDO/TRACE/SWO (Unavailable)
 *                            - PB4/NJTRST (Unavailable)
 *
 *                      - AFIO_REMAP_FULL:
 *                            - PA13/JTMS/SWDIO (Unavailable)
 *                            - PA14/JTCK/SWCLK (Unavailable)
 *                            - PA15/JTDI (Unavailable)
 *                            - PB3/JTDO/TRACE/SWO (Unavailable)
 *                            - PB4/NJTRST (Free)
 *
 *                      - AFIO_REMAP_PARTIAL:
 *                            - PA13/JTMS/SWDIO (Unavailable)
 *                            - PA14/JTCK/SWCLK (shared with JTDI) (Unavailable)
 *                            - PA15/JTDI (shared with JTCK/SWCLK) (Free)
 *                            - PB3/JTDO/TRACE/SWO (Free)
 *                            - PB4/NJTRST (Free)
 * 
 *                      - AFIO_REMAP_CUSTOM:
 *                            - This configuration allows users to customize the remap settings according to their needs. 
 *                              User configuration will determine the pin status.
 */
typedef enum 
{
    AFIO_REMAP_NONE,     /**< No remap (default) */ 
    AFIO_REMAP_FULL,     /**< Full SWJ (JTAG-DP + SW-DP) but without NJTRST */ 
    AFIO_REMAP_PARTIAL,  /**< JTAG-DP Disabled and SW-DP Enabled */ 
    AFIO_REMAP_CUSTOM,   /**< Custom remap (user-defined) */ 
} AFIO_RemapConfig_t;

/** @} */  // End of AFIO_Remap_Options group


/**
 * @defgroup AFIO_Functions AFIO Functions
 * @brief Functions for controlling the AFIO (Alternate Function I/O) peripheral.
 * @{
 */

/**
 * @brief Enable a specific peripheral on a specific bus.
 *
 * This function enables a specific peripheral on a specific bus.
 *
 * @param[in] Copy_PeripheralId The ID of the peripheral to be enabled.
 * @param[in] Copy_BusId        The ID of the bus to which the peripheral belongs (RCC_AHB, RCC_APB1, or RCC_APB2).
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurred.
 */
Std_ReturnType MCAL_AFIO_EnablePeripheral(u32 Copy_PeripheralId, u32 Copy_BusId);

/**
 * @brief Configure EXTI (External Interrupt) line for a GPIO port.
 *
 * This function configures the EXTI (External Interrupt) lines for a specified GPIO port. It maps
 * the EXTI line to the desired GPIO port using the AFIO peripheral.
 *
 * @param[in] Copy_Line The EXTI line number to configure (0 to 15).
 * @param[in] Copy_PortMap The GPIO port mapping for the EXTI line (0 to 15).
 * @return Std_ReturnType Returns E_OK if the EXTI configuration is successful, or E_NOT_OK if an error occurred.
 */
Std_ReturnType MCAL_AFIO_SetEXTIConfiguration(u8 Copy_Line, u8 Copy_PortMap);

/**
 * @brief Configure AF remap and debug I/O settings.
 *
 * This function configures the AF remap and debug I/O settings using the AFIO peripheral.
 *
 * @param[in] Copy_RemapConfig The configuration value for AF remap and debug I/O.
 * @return Std_ReturnType Returns E_OK if the configuration is successful, or E_NOT_OK if an error occurred.
 */
Std_ReturnType MCAL_AFIO_SetRemap(u32 Copy_RemapConfig);

/**
 * @brief Configure debug port settings.
 *
 * This function configures the debug port settings using the AFIO peripheral.
 *
 * @param[in] Copy_DebugConfig The configuration value for debug port settings.
 * @return Std_ReturnType Returns E_OK if the configuration is successful, or E_NOT_OK if an error occurred.
 */
Std_ReturnType MCAL_AFIO_SetDebugPort(u32 Copy_DebugConfig);

/**
 * @brief Configure additional mapping settings (MAPR2).
 *
 * This function configures additional mapping settings using the AFIO peripheral.
 *
 * @param[in] Copy_MAPR2Config The configuration value for additional mapping settings (MAPR2).
 * @return Std_ReturnType Returns E_OK if the configuration is successful, or E_NOT_OK if an error occurred.
 */
Std_ReturnType MCAL_AFIO_SetMAPR2(u32 Copy_MAPR2Config);

/** @} */ // End of AFIO_Functions group






#endif /**< AFIO_INTERFACE_H_ */
