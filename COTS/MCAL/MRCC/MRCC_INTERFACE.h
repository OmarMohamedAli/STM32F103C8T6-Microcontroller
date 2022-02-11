/********************************************************************************
 * File        : MRCC_INTERFACE.h
 * Description : RCC[Reset & Clock Control] Functions Interfaces.
 * Author      : Eng: Omar Mohamed Ali 
 * Date        : 9/2/2022
 * Version     : 1.0.0
 *********************************************************************************/
/*********************************************************************************
                           << File Guard >>
**********************************************************************************/
#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_

/*********************************************************************************
                           << File Inclusions>>
**********************************************************************************/
#define MRCC_u8_AHB_BUS         1
#define MRCC_u8_APB2_BUS        2
#define MRCC_u8_APB1_BUS        3

void MRCC_VoidInitSystemCLK        (void);
u8 MRCC_VoidEnablePeripheralCLK  (u8 Copy_u8BusId, u8 Copy_u8PeripheralId);
u8 MRCC_VoidDisablePeripheralCLK (u8 Copy_u8BusId, u8 Copy_u8PeripheralId);

#endif
