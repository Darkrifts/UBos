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

extern "C"
void kernel_main(void) {
	terminal_initialize();
	/* TODO: ADD STUFF WHEN IO AND MEMORY ACTUALLY WORKS */
}
