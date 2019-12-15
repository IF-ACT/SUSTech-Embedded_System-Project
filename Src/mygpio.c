#include "mygpio.h"

#include <string.h>
#include "main.h"
#include "usart.h"


void println(const char* str)
{
	HAL_UART_Transmit(&huart1, (unsigned char*)str, strlen(str), 0xffff);
}
