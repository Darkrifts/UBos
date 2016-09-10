#include <stddef.h>
#include <stdint.h>
#include "tstdout.h"
#include "tstdin.h"
#include "string.h"
#include "cells.h"
#include "stdutils.h"

extern "C"
void kernel_main(void) {
	terminal_initialize();
}
