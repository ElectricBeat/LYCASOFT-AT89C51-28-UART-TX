#include<reg51.h>
#include "8051_delay.h"
#include "LCD_4_BIT_HEADER_FILE.h"

void Uart_Intialization()
{
	TMOD = 0x20;
	SCON = 0x50;
	TH1  = 0xFD;
	TL1  = 0xFD;
	TR1  = 1;
}

void TX(unsigned char x)   
{
	SBUF = x;
	while(!TI);
	TI = 0;
}

void TX_String(const unsigned char *Str)
{
	while(*Str != 0)
	{
		TX(*Str++);
	}
}

void main()
{
	Lcd_Intialization();
	Uart_Intialization();

	Lcd_Command(0x80);
	Lcd_String("LYCA SOFT");
	
	while(1)
	{
		Lcd_Command(0xC0);
		Lcd_String("HELLO WORLD");

		TX_String("HELLO WORLD");
	}
}