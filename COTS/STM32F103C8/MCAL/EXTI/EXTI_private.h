/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 9 Sep 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : EXTI_private.h             *****************/
/****************************************************************/
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/**< EXTI base address */
#define EXTI_BASE_ADDRESS    0x40010400U

/**< EXTI register structure */
typedef struct 
{
    volatile u32 IMR;   /**< Interrupt Mask Register */
    volatile u32 EMR;   /**< Event Mask Register */
    volatile u32 RTSR;  /**< Rising Trigger Selection Register */
    volatile u32 FTSR;  /**< Falling Trigger Selection Register */
    volatile u32 SWIER; /**< Software Interrupt Event Register */
    volatile u32 PR;    /**< Pending Register */
} EXTI_RegDef_t;

/**< Pointer to EXTI register structure */
#define EXTI   ((EXTI_RegDef_t *)EXTI_BASE_ADDRESS)

/**< Total number of EXTI lines available */
#define EXTI_LINES_COUNT        16

/**< EXTI line enabled */
#define EXTI_LINE_ENABLED       1

/**< EXTI line disabled */
#define EXTI_LINE_DISABLED      0

/**
 * @name EXTI Port Mapping
 * @{
 */
#define EXTI_GPIO_NONE      ((INVALID_VALUE)-1) /**< A special value indicating no GPIO port is mapped to the EXTI line. */
#define EXTI_PORTMAP_GPIOA  0 /**< Map EXTI line to GPIO Port A. */
#define EXTI_PORTMAP_GPIOB  1 /**< Map EXTI line to GPIO Port B. */
#define EXTI_PORTMAP_GPIOC  2 /**< Map EXTI line to GPIO Port C. */
/** @} */

/**< EXTI Configuration Structure */
typedef struct 
{
    EXTI_CallbackFunc_t SetCallback; /**< Callback function for EXTI line */
    u8 GPIO_PortMap: 3;         /**< GPIO port to be used (EXTI_GPIO_PORTA, EXTI_GPIO_PORTB, etc.) */
    u8 TriggerType: 2;          /**< Trigger type (EXTI_TRIGGER_RISING, EXTI_TRIGGER_FALLING, EXTI_TRIGGER_BOTH, etc.) */
    u8 LineEnabled: 1;          /**< EXTI line enabled or disabled (1 or 0) */
    u8 : 2;                     /**< 2 bits of padding */
} EXTI_Configuration_t;


/**< EXTI line configuration settings */
extern EXTI_Configuration_t EXTI_Configurations[EXTI_LINES_COUNT];

#endif /**< EXTI_PRIVATE_H_ */
