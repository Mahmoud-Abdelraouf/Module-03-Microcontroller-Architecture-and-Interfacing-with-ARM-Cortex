/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 10 Feb 2024                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : FPEC_private.h             *****************/
/****************************************************************/
#ifndef FPEC_PRIVATE_
#define FPEC_PRIVATE_

/**
 * @brief Structure representing the Flash Program/erase Control Register (FPEC_CR).
 *
 * This structure defines the individual bit fields of the Flash Program/erase Control Register (FPEC_CR).
 */
typedef union {
    struct {
        u32 PG     : 1 ;   /**< Flash programming bit */
        u32 PER    : 1 ;   /**< Page erase bit */
        u32 MER    : 1 ;   /**< Mass erase bit */
        u32 RES1   : 1 ;   /**< Reserved bit */
        u32 OPTPG  : 1 ;   /**< Option byte programming bit */
        u32 OPTER  : 1 ;   /**< Option byte erase bit */
        u32 STRT   : 1 ;   /**< Start bit */
        u32 LOCK   : 1 ;   /**< Lock bit */
        u32 RES2   : 1 ;   /**< Reserved bit */
        u32 OPTWRE : 1 ;   /**< Option bytes write enable bit */
        u32 ERRIE  : 1 ;   /**< Error interrupt enable bit */
        u32 RES3   : 1 ;   /**< Reserved bit */
        u32 EOPIE  : 1 ;   /**< End of operation interrupt enable bit */
        u32 RES4   : 19 ;  /**< Reserved bits */
    } BitAccess;
    u32 WordAccess;       /**< Word access to the register */
} FPEC_CR_t;

#define FPEC_CR ((FPEC_CR_t*)0x40022010) /**< Pointer to the FPEC_CR register */

/**
 * @brief Structure representing the Flash Program/Erase Controller (FPEC).
 *
 * This structure defines the layout of the Flash Program/Erase Controller (FPEC) registers.
 */
typedef struct {
    volatile u32 ACR;      /**< Access control register */
    volatile u32 KEYR;     /**< Key register */
    volatile u32 OPTKEYR;  /**< Option key register */
    volatile u32 SR;       /**< Status register */
    volatile u32 CR;       /**< Control register */
    volatile u32 AR;       /**< Address register */
    volatile u32 RESERVED; /**< Reserved */
    volatile u32 OBR;      /**< Option byte register */
    volatile u32 WRPR;     /**< Write protection register */
} FPEC_t;

#define FPEC ((FPEC_t*)0x40022000) /**< Pointer to the FPEC register base address */


#endif /**< FPEC_PRIVATE_ */
