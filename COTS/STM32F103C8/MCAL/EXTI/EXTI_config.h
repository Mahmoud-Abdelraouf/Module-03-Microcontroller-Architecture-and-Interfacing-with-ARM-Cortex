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
 * - EXTI_RISING_EDGE: Configure for rising edge trigger.
 * - EXTI_FALLING_EDGE: Configure for falling edge trigger.
 * - EXTI_BOTH_EDGES: Configure for both rising and falling edge trigger.
 */
EXTI_Configuration EXTI_Configurations[EXTI_LINES_COUNT] = {

    /**< Configuration for EXTI Line 0 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_RISING_EDGE,
    },

    /* Configuration for EXTI Line 1 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_FALLING_EDGE,
    },

    /* Configuration for EXTI Line 2 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    /* Configuration for EXTI Line 3 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    /* Configuration for EXTI Line 4 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    /* Configuration for EXTI Line 5 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    /* Configuration for EXTI Line 6 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    /* Configuration for EXTI Line 7 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    /* Configuration for EXTI Line 8 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    /* Configuration for EXTI Line 9 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    /* Configuration for EXTI Line 10 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    /* Configuration for EXTI Line 11 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    /* Configuration for EXTI Line 12 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    /* Configuration for EXTI Line 13 */
    {
        .LineEnabled   = EXTI_LINE_ENABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    /* Configuration for EXTI Line 14 */
    {
        .LineEnabled   = EXTI_LINE_ENABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    /* Configuration for EXTI Line 15 */
    {
        .LineEnabled   = EXTI_LINE_ENABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
};

#endif /**< EXTI_CONFIG_H_ */