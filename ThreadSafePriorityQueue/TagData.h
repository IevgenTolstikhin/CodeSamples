#ifndef TAG_DATA_H
#define TAG_DATA_H

#include <Windows.h>

typedef struct tagTDATA
{
	unsigned char priority;
	DWORD ticks;
	DWORD client_id;
	char data[255];
} TDATA, *PTDATA;

bool operator > (const TDATA& lhs, const TDATA& rhs);

#endif // TAG_DATA_H