/********************************************************************************
 * File        : MRCC_Program.c
 * Description : RCC[Reset & Clock Control] Functions Implementations.
 * Author      : Eng: Omar Mohamed Ali 
 * Date        : 9/2/2022
 * Version     : 1.0.0
 *********************************************************************************/
/*********************************************************************************
                           << File Inclusions >>
**********************************************************************************/
#include "LIB\STD_TYPES.h"
#include "LIB\BIT_MATH.h"
#include "MCAL\MRCC\MRCC_INTERFACE.h"
#include "MCAL\MRCC\MRCC_CFG.h"
#include "MCAL\MRCC\MRCC_PRIVATE.h"
#include "LIB\STM32F103C8t6.h"

void MRCC_VoidInitSystemCLK(void)
{
    /* Select Clock SRC */

#if RCC_u8_SYS_CLK == RCC_U8_HSI
  /* Select HSI as a CLK SRC */
    /* 1-Enable HSI CLK SRC*/   // must Enable CLK Source First , 16 in Calibration
    RCC->CR = 0X00000081;
    /* 2-Select HSI as a CLK SRC*/
    RCC->CFGR = 0;
    /* 3-Disable All Other Clks */
    RCC->CR = 0X00000081;

#elif RCC_u8_SYS_CLK == RCC_U8_HSE
  /* Select HSE as a CLK SRC */
    /* 1-Enable HSE CLK SRC*/   // must Enable CLK Source First.
    RCC->CR = 0X00010080;
    /* 2-Select HSE as a CLK SRC*/
    RCC->CFGR = 0X00000001;
     /* 3-Disable All Other Clks */
    RCC->CR = 0X00010080;

#elif RCC_u8_SYS_CLK == RCC_U8_PLL
  /* 1- Select PLL SRC -> (HSI)  , 2-PLL Multiplication factor -> (x2)*/
     /* 3-Enable PLL CLK SRC*/   // must Enable CLK Source First.
    RCC->CR = 0X01000000;
    /* 4-Select PLL as a CLK SRC*/
    RCC->CFGR = 0X00000002;

#else
    #error " Wrong Choice"

#endif

}



u8 MRCC_u8EnablePeripheralCLK  (u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
    u8 LOC_u8ErrorState = 1;

    switch(Copy_u8BusId)
    {
        case MRCC_u8_AHB_BUS:  SET_BIT(RCC -> AHBENR , Copy_u8PeripheralId); break;
        
        case MRCC_u8_APB1_BUS:  SET_BIT(RCC -> APB1ENR , Copy_u8PeripheralId); break;
        
        case MRCC_u8_APB2_BUS:  SET_BIT(RCC -> APB2ENR , Copy_u8PeripheralId); break;

        default: LOC_u8ErrorState = 0; break;
    }

    return LOC_u8ErrorState;
}



u8 MRCC_VoidDisablePeripheralCLK (u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
    u8 LOC_u8ErrorState = 1;

    switch(Copy_u8BusId)
    {
        case MRCC_u8_AHB_BUS:  CLEAR_BIT(RCC->AHBENR , Copy_u8PeripheralId); break;
        
        case MRCC_u8_APB1_BUS:  CLEAR_BIT(RCC->APB1ENR , Copy_u8PeripheralId); break;
        
        case MRCC_u8_APB2_BUS:  CLEAR_BIT(RCC->APB2ENR , Copy_u8PeripheralId); break;

        default: LOC_u8ErrorState = 0; break;
    }

    return LOC_u8ErrorState;
}
