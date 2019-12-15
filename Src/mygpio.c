#include "mygpio.h"

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include "usart.h"

char __msg[50];

void println(const char* str)
{
	unsigned char* msg = (unsigned char*)strcat((char*)str, "\n");
	HAL_UART_Transmit(&huart1,msg, strlen(__msg), 0xffff);
}

void printlnf(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vsprintf(__msg, fmt, args);
	va_end(args);

	println(__msg);
}
