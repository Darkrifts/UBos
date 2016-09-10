#ifndef STDUTIL_H
#define STDUTIL_H

static void kwait(uint64_t ticks)
{
	for(uint64_t i = 0ul; i < ticks; i++) {asm("nop");}
}

#endif
