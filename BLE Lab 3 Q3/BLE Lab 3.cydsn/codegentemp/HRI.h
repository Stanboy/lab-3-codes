/*******************************************************************************
* File Name: HRI.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_HRI_H) /* Pins HRI_H */
#define CY_PINS_HRI_H

#include "cytypes.h"
#include "cyfitter.h"
#include "HRI_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    HRI_Write(uint8 value) ;
void    HRI_SetDriveMode(uint8 mode) ;
uint8   HRI_ReadDataReg(void) ;
uint8   HRI_Read(void) ;
uint8   HRI_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define HRI_DRIVE_MODE_BITS        (3)
#define HRI_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - HRI_DRIVE_MODE_BITS))

#define HRI_DM_ALG_HIZ         (0x00u)
#define HRI_DM_DIG_HIZ         (0x01u)
#define HRI_DM_RES_UP          (0x02u)
#define HRI_DM_RES_DWN         (0x03u)
#define HRI_DM_OD_LO           (0x04u)
#define HRI_DM_OD_HI           (0x05u)
#define HRI_DM_STRONG          (0x06u)
#define HRI_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define HRI_MASK               HRI__MASK
#define HRI_SHIFT              HRI__SHIFT
#define HRI_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HRI_PS                     (* (reg32 *) HRI__PS)
/* Port Configuration */
#define HRI_PC                     (* (reg32 *) HRI__PC)
/* Data Register */
#define HRI_DR                     (* (reg32 *) HRI__DR)
/* Input Buffer Disable Override */
#define HRI_INP_DIS                (* (reg32 *) HRI__PC2)


#if defined(HRI__INTSTAT)  /* Interrupt Registers */

    #define HRI_INTSTAT                (* (reg32 *) HRI__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define HRI_DRIVE_MODE_SHIFT       (0x00u)
#define HRI_DRIVE_MODE_MASK        (0x07u << HRI_DRIVE_MODE_SHIFT)


#endif /* End Pins HRI_H */


/* [] END OF FILE */
