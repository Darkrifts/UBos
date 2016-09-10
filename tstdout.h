#ifndef TSTDOUT_H
#define TSTDOUT_H
#include <stddef.h>
#include <stdint.h>
#include "string.h"

enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
	return fg | bg << 4;
}
 
static inline uint16_t vga_entry(unsigned char uc, uint8_t color) {
	return (uint16_t) uc | (uint16_t) color << 8;
}
 
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
 
size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* VideoMemory;
 
void terminal_initialize(void) {
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	VideoMemory = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			VideoMemory[index] = vga_entry(' ', terminal_color);
		}
	}
}
 
void terminal_setcolor(uint8_t color) {
	terminal_color = color;
}
 
void terminal_putentry(char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	VideoMemory[index] = vga_entry(c, color);
}
 
void terminal_putchar(char c) {
	if(c == 0) return;
	if(c == '\n') { 
		terminal_column = 0;
		terminal_row++;
		return;
	}
	if(c == '\b') { 
		if(terminal_column < 1) return;
		terminal_column--;
		terminal_putentry(' ', 15, terminal_column, terminal_row);
		return;
	}
	if(c == '\t') { 
		terminal_column += 5; 
		if(terminal_column >= VGA_WIDTH) {
			terminal_column = 0;
			if(++terminal_row == VGA_HEIGHT) terminal_row = 0;
		}
		return;
	}
	terminal_putentry(c, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT)
			terminal_row = 0;
	}
}

void terminal_write(char* data) {
	size_t len = strlen(data);
	for (size_t i = 0; i < len; i++)
		terminal_putchar(data[i]);
}
 
void terminal_write(const char* data) {
	size_t len = strlen(data);
	for (size_t i = 0; i < len; i++)
		terminal_putchar(data[i]);
}

void printf(uint8_t color, char* str)
{
	terminal_setcolor(color);
	size_t len = strlen(str);
	for(size_t i = 0; i < len; i++) terminal_putchar(str[i]);
}

void printf(uint8_t color, const char* str)
{
	terminal_setcolor(color);
	size_t len = strlen(str);
	for(size_t i = 0; i < len; i++) terminal_putchar(str[i]);
}

static void cls()		
{
	terminal_column=0;
	terminal_row=0;
	char space = ' ';
	for(int i=0; i<=80; i++)
	{
		for(int y=0; y<=125; y++)
		{
	           const size_t index =  (terminal_row * VGA_WIDTH +  terminal_column); 	
	    	   terminal_column++;
 	
		   VideoMemory[index]= (VideoMemory[index] & 0xFF00)|space;
		}
	
	}
	for(int i=0; i<=80; i++)
	{
		for(int y=0; y<=125; y++)
		{
		  const size_t index =  (terminal_row * VGA_WIDTH +  terminal_column);
		  terminal_column--;

		  VideoMemory[index]= (VideoMemory[index] & 0xFF00)|space;
		}
	}
}
#endif
 
