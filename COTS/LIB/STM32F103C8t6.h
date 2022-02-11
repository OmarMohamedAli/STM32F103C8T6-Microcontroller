/********************************************************************************
 * File        : STM32F103C8T6.h
 * Description : RCC[Reset Clock Control] Functions Interface.
 * Author      : Eng: Omar Mohamed Ali 
 * Date        : 9/2/2022
 * Version     : 1.0.0
 *********************************************************************************/
/*********************************************************************************
                           << File Guard >>
**********************************************************************************/
#ifndef STM32F103C8_H_
#define STM32F103C8_H_


/*********************************************************************************
                           << File Guard >>
**********************************************************************************/
#include "STD_TYPES.h"

/************************** RCC REGISTER ************************************/
#define RCC_u32_BASE_ADDRESS       0X40021000

typedef struct{
    volatile u32 CR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 APB2RSTR;
    volatile u32 APB1RSTR;
    volatile u32 AHBENR;
    volatile u32 APB2ENR;
    volatile u32 APB1ENR;
    volatile u32 BDCR;
    volatile u32 CSR; 
}RCC_REG_t;

#define RCC               ((RCC_REG_t *)RCC_u32_BASE_ADDRESS)
/****************************************************************************/

/************************** GPIO Registers ************************************/
#define GPIO_u32_GPIOA_BASE_ADDRESS       0X40010800
#define GPIO_u32_GPIOB_BASE_ADDRESS       0X40010C00
#define GPIO_u32_GPIOC_BASE_ADDRESS       0X40011000

typedef struct{
    volatile u32 CRL;
    volatile u32 CRH;
    volatile u32 IDR;
    volatile u32 ODR;
    volatile u32 BSRR;
    volatile u32 BRR;
    volatile u32 LCKR;
}GPIO_REG_t;

#define GPIOA               ((GPIO_REG_t *)GPIO_u32_GPIOA_BASE_ADDRESS)
#define GPIOB               ((GPIO_REG_t *)GPIO_u32_GPIOB_BASE_ADDRESS)
#define GPIOC               ((GPIO_REG_t *)GPIO_u32_GPIOC_BASE_ADDRESS)

/****************************************************************************/


#endif 
