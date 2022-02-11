/********************************************************************************
 * File        : MGPIO_PROGRAM.c
 * Description : GPIO Functions Implementations.
 * Author      : Eng: Omar Mohamed Ali
 * Date        : 9/2/2022
 * Version     : 1.0.0
 *********************************************************************************/
/*********************************************************************************
                           << File Inclusions >>
**********************************************************************************/
#include "MCAL\MGPIO\MGPIO_INTERFACE.h"

static GPIO_REG_t *GPIO_Arr[3]={GPIOA , GPIOB , GPIOC};

ERROR_STATE_t MGPIO_ERROR_STATE_t_InitMode(const MGPIO_PinConfig_t *PstructPinConfig)
{
	u8 shift = 4;
	ERROR_STATE_t LOC_ERROR_STATE_t_ReturnedValue = RET_OK;
	u8 LOC_u8PinMode;
	if(PstructPinConfig != NULL)
	{
		/* Enable Peripheral CLK */
		RCC->APB2ENR |= (1<<((PstructPinConfig->PortId)+2));
		LOC_u8PinMode = PstructPinConfig->PinMode;
		/* Check if the Mode is Pull up or Pull down */
		if(PstructPinConfig->PinMode == GPIO_u8_INPUT_PULL_DOWN) /* Clear Bit at ODR Register*/
		{
			(GPIO_Arr[PstructPinConfig-> PortId] -> BRR) = (1<<(PstructPinConfig -> PinID));
		}
		else if(PstructPinConfig->PinMode == GPIO_u8_INPUT_PULL_UP) /* Set Bit at ODR Register*/
		{
			(GPIO_Arr[PstructPinConfig-> PortId] -> BSRR) = (1<<(PstructPinConfig -> PinID));
			CLEAR_BIT(LOC_u8PinMode, 4);
			//CLEAR_BIT(PstructPinConfig->PinMode ,4);  // [0b1000]  or [subtract(16)]
		}
		else{}

		if((PstructPinConfig->PinID >= GPIO_u32_PIN0) && (PstructPinConfig->PinID <= GPIO_u32_PIN7))
		{
			/* CRL Register */
			/* Clear Bits Region */
			(GPIO_Arr[PstructPinConfig->PortId]->CRL) &= (~((0b1111)<<((PstructPinConfig->PinID)*(shift)))); // Clear Bit using Bit Masking
			/* Set Pin Mode*/
			(GPIO_Arr[PstructPinConfig->PortId]->CRL) |= (LOC_u8PinMode<<((PstructPinConfig->PinID)*(shift)));    // Set Value
		}
		else if((PstructPinConfig->PinID >= GPIO_u32_PIN8) && (PstructPinConfig->PinID <= GPIO_u32_PIN15))
		{
			/* CRH Register */
			/* Clear Bits Region */
			(GPIO_Arr[PstructPinConfig->PortId]->CRH) &= (~((0b1111)<<(((PstructPinConfig->PinID)- 8)*(shift)))); // Clear Bit using Bit Masking
			/* Set Pin Mode*/
			(GPIO_Arr[PstructPinConfig->PortId]->CRH) |= (LOC_u8PinMode<<(((PstructPinConfig->PinID)- 8)*(shift)));    // Set Value
		}
		else
		{
			LOC_ERROR_STATE_t_ReturnedValue = RET_NOK;
		}
	}
	else
	{
		LOC_ERROR_STATE_t_ReturnedValue = RET_NOK;
	}
	return LOC_ERROR_STATE_t_ReturnedValue;
}


ERROR_STATE_t MGPIO_ERROR_STATE_t_SetPinValue(const MGPIO_PinConfig_t *PstructPinConfig , u8 Copy_u8PinValue)
{
	ERROR_STATE_t LOC_ERROR_STATE_t_ReturnedValue = RET_OK;

	if(PstructPinConfig != NULL)
	{
		switch(Copy_u8PinValue)
		{
			case GPIO_u8_LOW:
				GPIO_Arr[PstructPinConfig->PortId]->BRR = (1<<(PstructPinConfig->PinID));
				break;

			case GPIO_u8_HIGH:
				GPIO_Arr[PstructPinConfig->PortId]->BSRR = (1<<(PstructPinConfig->PinID));
				break;

			default:
				LOC_ERROR_STATE_t_ReturnedValue = RET_NOK;
				break;
		}
	}
	else
	{
		LOC_ERROR_STATE_t_ReturnedValue = RET_OK;
	}

	return LOC_ERROR_STATE_t_ReturnedValue;
}



ERROR_STATE_t MGPIO_ERROR_STATE_t_GetPinValue(const MGPIO_PinConfig_t *PstructPinConfig ,u8 *Pu8ReturnedValue)
{
	ERROR_STATE_t LOC_ERROR_STATE_t_ReturnedValue = RET_OK;
	if((PstructPinConfig != NULL) && (Pu8ReturnedValue != NULL))
	{
		*Pu8ReturnedValue = GET_BIT(GPIO_Arr[PstructPinConfig->PortId]->IDR , PstructPinConfig->PinID);
	}
	else
	{
		LOC_ERROR_STATE_t_ReturnedValue = RET_OK;
	}
	return LOC_ERROR_STATE_t_ReturnedValue;
}




ERROR_STATE_t MGPIO_ERROR_STATE_t_TogglePinValue(const MGPIO_PinConfig_t *PstructPinConfig)
{
	ERROR_STATE_t LOC_ERROR_STATE_t_ReturnedValue = RET_OK;
	if(PstructPinConfig != NULL)
	{
		TOGGLE_BIT(GPIO_Arr[PstructPinConfig->PortId]->ODR , PstructPinConfig->PinID);
	}
	else
	{
		LOC_ERROR_STATE_t_ReturnedValue = RET_OK;
	}
	return LOC_ERROR_STATE_t_ReturnedValue;
}

