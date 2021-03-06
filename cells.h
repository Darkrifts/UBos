// Holds 8 KiB at maximum capacity

#ifndef CELLS_H
#define CELLS_H

static uint32_t freeMemCells = 32;
static uint32_t totalMemCells = 32;
static int8_t memcells[][256] = {
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	} // ... etc, there's 32 total cells (counting the one above) and they're all identical.
	  // Just paste that as an item in the array 31 more times.
};

// Gives a handle to a memory cell
static int8_t* grabCell()
{
	for(uint32_t i = 0; i < totalMemCells; i++)
	{
		if((memcells[i][0] & 1) == 0)
		{
			freeMemCells--;
			memcells[i][0] = 1;
			return memcells[i];
		}
	}
	while(1){}
}

// Given a handle to a cell, it clears it and determines it as free
// Does not invalidate handle, so corruption can occur, but meh
static void freeCell(int8_t* cell)
{
	if((cell[0] & 1) != 0)
	{
		freeMemCells++;
		for(size_t i = 0; i < 256; i++) cell[i] = 0;
	}
}

#endif
