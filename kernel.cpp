// Build with i686-elf-g++ -c kernel.cpp -o kernel.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti

#include <stddef.h>
#include <stdint.h>
#include "tstdout.h"
#include "tstdin.h"
#include "string.h"
#include "badmem.h"

static void kwait(uint64_t ticks)
{
	for(uint64_t i = 0ul; i < ticks; i++) {asm("nop");}
}

extern "C" /* Use C linkage for kernel_main. */
void kernel_main(void) {
	/* Initialize terminal interface */
	terminal_initialize();

	getString(1, c, true);
}
