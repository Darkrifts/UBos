#ifndef TSTDIN_H
#define TSTDIN_H

#include "tstdout.h"

static const char* scancodes1 = "  1234567890-=\b\tQWERTYUIOP[]\n\0ASDFGHJKL;'`\0\\ZXCVBNM,./\0*\0 \0\0\0\0\0\0\0\0\0\0\0\0\0789-456+1230.\0\0";

static const char* scancodes2 = "\0\0\0\0\0\0\0\0\0\0\0\0\0\t`\0\0\0\0\0\0Q1\0\0\0ZSAW2\0\0CXDE43\0\0 VFTR5\0\0NBHGY6\0\0\0MJU78\0\0,KIO09\0\0./L;P-\0\0\0'\0[=\0\0\0\0\n]\0\\\0\0\0\0\b\0\01\047\0\0\00.2568\0\0\0+3-*9\0\0\0\0\0\0";

static uint8_t inb(uint64_t port)
{
	uint8_t ret;
    	asm volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
   	return ret;
}

static uint8_t getScancode()
{
	char c = 0;
	do {
		if(inb(0x60)!=c) { c = inb(0x60); if(c>0) return c;}
	} while(1);
}

static char getKybInput1()
{
	uint8_t g = getScancode();
	if(g > 0x58) return '\0';
	return scancodes1[g];
}

static char getKybInput2()
{
	uint8_t g = getScancode();
	if(g > 0x83) return '\0';
	return scancodes2[g];
}

static char getChar1(bool echo = false)
{
	char c = 0;
	do {
		c = getKybInput1();
	} while(c != 0);
	if(echo) terminal_putchar(c);
	return c;
}

static char getChar2(bool echo = false)
{
	char c = 0;
	do {
		c = getKybInput2();
	} while(c != 0);
	if(echo) terminal_putchar(c);
	return c;
}

static void getString(int8_t charset, char* data, bool echo = false)
{
	size_t len = strlen(data);
	if(charset == 1)
	{
		for(uint32_t i = 0; i < len; i++)
		{
			data[i] = getChar1(echo);
			if(data[i] == '\n')
			{
				for(uint32_t j = i + 1; j < len; j++)
					data[j] = 0;
				return;
			}
		}
	}
	if(charset == 2)
	{
		for(uint32_t i = 0; i < len; i++)
		{
			data[i] = getChar2(echo);
			if(data[i] == '\n')
			{
				for(uint32_t j = i + 1; j < len; j++)
					data[j] = 0;
				return;
			}
		}
	}
}

static void getString(int8_t charset, unsigned char* data, bool echo = false)
{
	size_t len = strlen(data);
	if(charset == 1)
	{
		for(uint32_t i = 0; i < len; i++)
		{
			data[i] = getChar1(echo);
			if(data[i] == '\n')
			{
				for(uint32_t j = i + 1; j < len; j++)
					data[j] = 0;
				return;
			}
		}
	}
	if(charset == 2)
	{
		for(uint32_t i = 0; i < len; i++)
		{
			data[i] = getChar2(echo);
			if(data[i] == '\n')
			{
				for(uint32_t j = i + 1; j < len; j++)
					data[j] = 0;
				return;
			}
		}
	}
}

#endif
