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
 * 
 * SetCallback:
 * - NULL: No callback function will be called when the EXTI line triggers.
 * - [Callback Function Name]: Specify the name of the callback function to be called
 *   when the EXTI line triggers. If NULL is selected, no function will be called.
 */
EXTI_Configuration_t EXTI_Configurations[EXTI_LINES_COUNT] = {

    /**< Configuration for EXTI Line 0 */
    {
        .SetCallback  = NULL,
        .GPIO_PortMap = EXTI_GPIO_NONE,
        .TriggerType  = EXTI_BOTH_EDGES,
        .LineEnabled  = EXTI_LINE_DISABLED
    },

    /* Configuration for EXTI Line 1 */
    {
        .SetCallback  = NULL,
        .GPIO_PortMap = EXTI_GPIO_NONE,
        .TriggerType  = EXTI_FALLING_EDGE,
        .LineEnabled  = EXTI_LINE_DISABLED
    },

    /* Configuration for EXTI Line 2 */
    {
        .SetCallback  = NULL,
        .GPIO_PortMap = EXTI_GPIO_NONE,
        .TriggerType  = EXTI_BOTH_EDGES,
        .LineEnabled  = EXTI_LINE_DISABLED
    },
    
    /* Configuration for EXTI Line 3 */
    {
        .SetCallback  = NULL,
        .GPIO_PortMap = EXTI_GPIO_NONE,
        .TriggerType  = EXTI_BOTH_EDGES,
        .LineEnabled  = EXTI_LINE_DISABLED
    },
    
    /* Configuration for EXTI Line 4 */
    {
        .SetCallback  = NULL,
        .GPIO_PortMap = EXTI_GPIO_NONE,
        .TriggerType  = EXTI_BOTH_EDGES,
        .LineEnabled  = EXTI_LINE_DISABLED
    },
    
    /* Configuration for EXTI Line 5 */
    {
        .SetCallback  = NULL,
        .GPIO_PortMap = EXTI_GPIO_NONE,
        .TriggerType  = EXTI_BOTH_EDGES,
        .LineEnabled  = EXTI_LINE_DISABLED
    },
    
    /* Configuration for EXTI Line 6 */
    {
        .SetCallback  = NULL,
        .GPIO_PortMap = EXTI_GPIO_NONE,
        .TriggerType  = EXTI_BOTH_EDGES,
        .LineEnabled  = EXTI_LINE_DISABLED
    },
    
    /* Configuration for EXTI Line 7 */
    {
        .SetCallback  = NULL,
        .GPIO_PortMap = EXTI_GPIO_NONE,
        .TriggerType  = EXTI_BOTH_EDGES,
        .LineEnabled  = EXTI_LINE_DISABLED
    },
    
    /* Configuration for EXTI Line 8 */
    {
        .SetCallback  = NULL,
        .GPIO_PortMap = EXTI_GPIO_NONE,
        .TriggerType  = EXTI_BOTH_EDGES,
        .LineEnabled  = EXTI_LINE_DISABLED
    },
    
    /* Configuration for EXTI Line 9 */
    {
        .SetCallback  = NULL,
        .GPIO_PortMap = EXTI_GPIO_NONE,
        .TriggerType  = EXTI_BOTH_EDGES,
        .LineEnabled  = EXTI_LINE_DISABLED
    },
    
    /* Configuration for EXTI Line 10 */
    {
        .SetCallback  = NULL,
        .GPIO_PortMap = EXTI_GPIO_NONE,
        .TriggerType  = EXTI_BOTH_EDGES,
        .LineEnabled  = EXTI_LINE_DISABLED
    },
    
    /* Configuration for EXTI Line 11 */
    {
        .SetCallback  = NULL,
        .GPIO_PortMap = EXTI_GPIO_NONE,
        .TriggerType  = EXTI_BOTH_EDGES,
        .LineEnabled  = EXTI_LINE_DISABLED
    },
    
    /* Configuration for EXTI Line 12 */
    {
        .SetCallback  = NULL,
        .GPIO_PortMap = EXTI_GPIO_NONE,
        .TriggerType  = EXTI_BOTH_EDGES,
        .LineEnabled  = EXTI_LINE_DISABLED
    },
    
    /* Configuration for EXTI Line 13 */
    {
        .SetCallback  = NULL,
        .GPIO_PortMap = EXTI_GPIO_NONE,
        .TriggerType  = EXTI_BOTH_EDGES,
        .LineEnabled  = EXTI_LINE_DISABLED
    },
    
    /* Configuration for EXTI Line 14 */
    {
        .SetCallback  = NULL,
        .GPIO_PortMap = EXTI_GPIO_NONE,
        .TriggerType  = EXTI_BOTH_EDGES,
        .LineEnabled  = EXTI_LINE_DISABLED
    },
    
    /* Configuration for EXTI Line 15 */
    {
        .SetCallback  = NULL,
        .GPIO_PortMap = EXTI_GPIO_NONE,
        .TriggerType  = EXTI_BOTH_EDGES,
        .LineEnabled  = EXTI_LINE_DISABLED
    }

};

#endif /**< EXTI_CONFIG_H_ */