#include "utility.h"

void UT_PrintMsg(char* msg)
{
	HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
}

void UT_printf(const char* format, ...)
{
	va_list args;
	char buffer[32];	
	memset(buffer, 0, 32);

	va_start(args, format);	
	vsprintf(buffer, format, args);
	UT_PrintMsg(buffer);
	va_end(args);
}

void UT_Error_Handler(char* err_msg)
{
    __disable_irq();
    while (1)
	{
    	UT_PrintMsg(err_msg);
	}
}

void UT_Delay_MicroSeconds(uint16_t uSec)
{
	__HAL_TIM_SET_COUNTER(&htim21, 0);
	while(__HAL_TIM_GET_COUNTER(&htim21) < uSec);
}