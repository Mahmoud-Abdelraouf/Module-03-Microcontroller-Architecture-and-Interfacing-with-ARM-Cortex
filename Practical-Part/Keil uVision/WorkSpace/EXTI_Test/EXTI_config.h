/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 9 Sep 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : EXTI_config.h              *****************/
/****************************************************************/
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/**
 * @brief EXTI Configuration Array
 *
 * This array is used to configure the EXTI lines. Each element in the array represents
 * the configuration for a specific EXTI line.
 *
 * To configure an EXTI line, set the appropriate options for LineEnabled and TriggerType.
 *
 * Available options for LineEnabled:
 * - EXTI_LINE_ENABLED: Enable the EXTI line.
 * - EXTI_LINE_DISABLED: Disable the EXTI line.
 *
 * Available options for TriggerType:
 * - EXTI_RISING_EDGE: Configure for a rising edge trigger.
 * - EXTI_FALLING_EDGE: Configure for a falling edge trigger.
 * - EXTI_BOTH_EDGES: Configure for both rising and falling edge trigger.
 * 
 * Available options for GPIO_PortMap:
 * - EXTI_GPIO_NONE: No GPIO port is mapped to the EXTI line.
 * - EXTI_PORTMAP_GPIOA: Map EXTI line to GPIO Port A.
 * - EXTI_PORTMAP_GPIOB: Map EXTI line to GPIO Port B.
 * - EXTI_PORTMAP_GPIOC: Map EXTI line to GPIO Port C.
 */
EXTI_Configuration_t EXTI_Configurations[EXTI_LINES_COUNT] = {

    /**< Configuration for EXTI Line 0 */
    {
        .GPIO_PortMap  = EXTI_GPIO_NONE,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },

    /* Configuration for EXTI Line 1 */
    {
        .GPIO_PortMap  = EXTI_GPIO_NONE,
        .TriggerType   = EXTI_FALLING_EDGE,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },

    /* Configuration for EXTI Line 2 */
    {
        .GPIO_PortMap  = EXTI_GPIO_NONE,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 3 */
    {
        .GPIO_PortMap  = EXTI_GPIO_NONE,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 4 */
    {
        .GPIO_PortMap  = EXTI_GPIO_NONE,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 5 */
    {
        .GPIO_PortMap  = EXTI_GPIO_NONE,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 6 */
    {
        .GPIO_PortMap  = EXTI_GPIO_NONE,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 7 */
    {
        .GPIO_PortMap  = EXTI_GPIO_NONE,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 8 */
    {
        .GPIO_PortMap  = EXTI_GPIO_NONE,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 9 */
    {
        .GPIO_PortMap  = EXTI_GPIO_NONE,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 10 */
    {
        .GPIO_PortMap  = EXTI_GPIO_NONE,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 11 */
    {
        .GPIO_PortMap  = EXTI_GPIO_NONE,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 12 */
    {
        .GPIO_PortMap  = EXTI_GPIO_NONE,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 13 */
    {
        .GPIO_PortMap  = EXTI_GPIO_NONE,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 14 */
    {
        .GPIO_PortMap  = EXTI_GPIO_NONE,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 15 */
    {
        .GPIO_PortMap  = EXTI_GPIO_NONE,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
};

#endif /**< EXTI_CONFIG_H_ */