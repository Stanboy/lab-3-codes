/*******************************************************************************
* File Name: HRI.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "HRI.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        HRI_PC =   (HRI_PC & \
                                (uint32)(~(uint32)(HRI_DRIVE_MODE_IND_MASK << (HRI_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (HRI_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: HRI_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void HRI_Write(uint8 value) 
{
    uint8 drVal = (uint8)(HRI_DR & (uint8)(~HRI_MASK));
    drVal = (drVal | ((uint8)(value << HRI_SHIFT) & HRI_MASK));
    HRI_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: HRI_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  HRI_DM_STRONG     Strong Drive 
*  HRI_DM_OD_HI      Open Drain, Drives High 
*  HRI_DM_OD_LO      Open Drain, Drives Low 
*  HRI_DM_RES_UP     Resistive Pull Up 
*  HRI_DM_RES_DWN    Resistive Pull Down 
*  HRI_DM_RES_UPDWN  Resistive Pull Up/Down 
*  HRI_DM_DIG_HIZ    High Impedance Digital 
*  HRI_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void HRI_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(HRI__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: HRI_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro HRI_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 HRI_Read(void) 
{
    return (uint8)((HRI_PS & HRI_MASK) >> HRI_SHIFT);
}


/*******************************************************************************
* Function Name: HRI_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 HRI_ReadDataReg(void) 
{
    return (uint8)((HRI_DR & HRI_MASK) >> HRI_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(HRI_INTSTAT) 

    /*******************************************************************************
    * Function Name: HRI_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 HRI_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(HRI_INTSTAT & HRI_MASK);
		HRI_INTSTAT = maskedStatus;
        return maskedStatus >> HRI_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
