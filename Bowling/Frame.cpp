#include "Frame.h"
#include "Utils.h"

CFrame::CFrame() :	uFirstTrialItems	(0), 
					uSecondTrialItems	(0),
					uCurrentTrialNumber	(static_cast<unsigned short>(TRIAL_NUMBER::FIRST)),
					fFlags				(FLAGS::NOTHING),
					b10thFrame			(false)
{}

//Setters
void CFrame::SetFirstTrialItems		(unsigned short uValue	) { uFirstTrialItems 	= uValue; 	}
void CFrame::SetSecondTrialItems	(unsigned short uValue	) { uSecondTrialItems 	= uValue; 	}
void CFrame::SetCurrentTrialNumber	(unsigned short uValue	) { uCurrentTrialNumber = uValue; 	}
void CFrame::Set10thFrame			(bool bValue			) { b10thFrame 			= bValue; 	}
void CFrame::SetFlags				(const FLAGS& flag 		) { fFlags 				= flag; 	}

//Getters
unsigned short 	CFrame::GetFirstTrialItems		() 	const { return uFirstTrialItems; 	}
unsigned short 	CFrame::GetSecondTrialItems		() 	const { return uSecondTrialItems; 	}
unsigned short 	CFrame::GetCurrentTrialNumber	() 	const { return uCurrentTrialNumber; }
bool 			CFrame::Get10thFrame			() 	const { return b10thFrame; 			}
FLAGS 			CFrame::GetFlags 				() 	const { return fFlags; 				}
std::string 	CFrame::GetFlagsToString		() 	const 
{
	switch(fFlags)
	{
		case FLAGS::NOTHING:
			return "NOTHING";
		case FLAGS::SPARE:
			return "SPARE";
		case FLAGS::STRIKE:
			return "STRIKE";
	}

	return "Undefined";
}