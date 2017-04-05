#ifndef __GAME_H__
#define __GAME_H__

#include <memory>
#include <vector>
#include "Frame.h"

class CUtils;
class CGame
{
	std::shared_ptr<CUtils> puUtil;
	unsigned short uCurrentFrameNumber;
	unsigned short uRestOfItems;
	unsigned uTotal;
	std::vector < std::shared_ptr<CFrame> > vpFrames;

public:
	CGame();

	std::shared_ptr<CFrame> GetCurrentFrame 		() 								const;
	std::shared_ptr<CFrame> GetFrame 				(unsigned short nFrameNumber) 	const;
	unsigned short 			GetCurrentFrameNumber 	() 								const;
	unsigned short 			GetRestOfItems 			() 								const;
	unsigned 				GetTotal				() 								const;

	void ModifyCurrentTrialNumber	();
	void IncCurrentFrame			();
	void UpdateRestOfItems			();
	void GameOver					();
};

#endif //__GAME_H__