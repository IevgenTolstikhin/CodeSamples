#ifndef __FRAME_H__
#define __FRAME_H__

#include <string>

typedef enum class _FLAGS_ {NOTHING, SPARE, STRIKE} FLAGS;
class CFrame
{
	unsigned short uFirstTrialItems;
	unsigned short uSecondTrialItems;
	unsigned short uCurrentTrialNumber;
	FLAGS fFlags;
	bool b10thFrame;

public:

	CFrame();

	void SetFirstTrialItems		(unsigned short uValue);
	void SetSecondTrialItems	(unsigned short uValue);
	void SetCurrentTrialNumber	(unsigned short uValue);
	void Set10thFrame			(bool bValue);
	void SetFlags				(const FLAGS& flag);

	unsigned short GetFirstTrialItems	() const;
	unsigned short GetSecondTrialItems	() const;
	unsigned short GetCurrentTrialNumber() const;
	bool Get10thFrame					() const;
	FLAGS GetFlags 						() const;
	std::string GetFlagsToString 		() const;
};

#endif //__FRAME_CPP__