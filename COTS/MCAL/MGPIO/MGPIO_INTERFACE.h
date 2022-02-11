/********************************************************************************
 * File        : MGPIO_INTERFACE.h
 * Description : GPIO Functions Interfaces.
 * Author      : Eng: Omar Mohamed Ali 
 * Date        : 9/2/2022
 * Version     : 1.0.0
 *********************************************************************************/
/*********************************************************************************
                           << File Guard >>
**********************************************************************************/
#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

/*********************************************************************************
                           << File Inclusions >>
**********************************************************************************/
#include "LIB\BIT_MATH.h"
#include "LIB\STD_TYPES.h"
#include "MCAL\MGPIO\MGPIO_CFG.h"
#include "MCAL\MGPIO\MGPIO_PRIVATE.h"
#include "LIB\STM32F103C8t6.h"

/****************************** enum for PortId *******************************/
typedef enum{
	GPIO_u32_GPIOA=0,
	GPIO_u32_GPIOB,
	GPIO_u32_GPIOC
}MPortId_t;
/******************************************************************************/

/******************************* enum for PinId *******************************/
typedef enum{
	GPIO_u32_PIN0 =0,
	GPIO_u32_PIN1 ,
	GPIO_u32_PIN2 ,
	GPIO_u32_PIN3 ,
	GPIO_u32_PIN4 ,
	GPIO_u32_PIN5 ,
	GPIO_u32_PIN6 ,
	GPIO_u32_PIN7 ,

	GPIO_u32_PIN8 ,
	GPIO_u32_PIN9 ,
	GPIO_u32_PIN10,
	GPIO_u32_PIN11,
	GPIO_u32_PIN12,
	GPIO_u32_PIN13,
	GPIO_u32_PIN14,
	GPIO_u32_PIN15
}MPinId_t;
/******************************************************************************/

/***************************  Macros for PinMode ******************************/
/* Input Modes */
#define GPIO_u8_INPUT_ANALOG               0b0000
#define GPIO_u8_INPUT_FLOATING             0b0100
#define GPIO_u8_INPUT_PULL_DOWN            0b1000
#define GPIO_u8_INPUT_PULL_UP              0b11000  // for differential , I will clear last bit in function


/* OUTPUT Modes */
/* OUTPUT MAX Speed = 10MHZ */
#define GPIO_u8_OUTPUT_GP_PP_MAX_10_MHZ   0b0001
#define GPIO_u8_OUTPUT_GP_OD_MAX_10_MHZ   0b0101
#define GPIO_u8_OUTPUT_AF_PP_MAX_10_MHZ   0b1001
#define GPIO_u8_OUTPUT_AF_OD_MAX_10_MHZ   0b1101


/* OUTPUT MAX Speed = 2MHZ */
#define GPIO_u8_OUTPUT_GP_PP_MAX_2_MHZ    0b0010
#define GPIO_u8_OUTPUT_GP_OD_MAX_2_MHZ    0b0110
#define GPIO_u8_OUTPUT_AF_PP_MAX_2_MHZ    0b1010
#define GPIO_u8_OUTPUT_AF_OD_MAX_2_MHZ    0b1110


/* OUTPUT MAX Speed = 50MHZ */
#define GPIO_u8_OUTPUT_GP_PP_MAX_50_MHZ    0b0011
#define GPIO_u8_OUTPUT_GP_OD_MAX_50_MHZ    0b0111
#define GPIO_u8_OUTPUT_AF_PP_MAX_50_MHZ    0b1011
#define GPIO_u8_OUTPUT_AF_OD_MAX_50_MHZ    0b1111
/******************************************************************************/

/************************ Macros for Pin Value ***************************** */
#define GPIO_u8_LOW     0
#define GPIO_u8_HIGH    1
/******************************************************************************/


/*************************  Struct for PinMode ********************************/
typedef struct{
	MPortId_t PortId;
	MPinId_t PinID;
	u8 PinMode;
}MGPIO_PinConfig_t;
/******************************************************************************/

/*************************** Function Prototypes ******************************/
ERROR_STATE_t MGPIO_ERROR_STATE_t_InitMode(const MGPIO_PinConfig_t *PstructPinConfig);

ERROR_STATE_t MGPIO_ERROR_STATE_t_SetPinValue(const MGPIO_PinConfig_t *PstructPinConfig , u8 Copy_u8PinValue);

ERROR_STATE_t MGPIO_ERROR_STATE_t_GetPinValue(const MGPIO_PinConfig_t *PstructPinConfig ,u8 *Pu8ReturnedValue);

ERROR_STATE_t MGPIO_ERROR_STATE_t_TogglePinValue(const MGPIO_PinConfig_t *PstructPinConfig);


#endif
