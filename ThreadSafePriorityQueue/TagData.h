#ifndef TAG_DATA_H
#define TAG_DATA_H

#include <string>

typedef struct tagTDATA
{
	uint32_t priority;
	unsigned long ticks;
	unsigned long client_id;
	std::wstring data;
} TDATA;

bool operator > (const TDATA& lhs, const TDATA& rhs);

#endif // TAG_DATA_H