#include "Game.h"
#include "Frame.h"
#include "Utils.h"
#include <iostream>

CGame::CGame() :puUtil(new CUtils),
				uCurrentFrameNumber(0), 
				uRestOfItems(puUtil->GetMaxItems()),
				uTotal(0), 
				vpFrames(puUtil->GetMaxFrames())
{
    for (unsigned short i = 0; i < puUtil->GetMaxFrames(); ++i)
    {
        std::shared_ptr<CFrame> pFrame(new CFrame);
        vpFrames.at(i) = std::move(pFrame);
    }
}

//Getters
std::shared_ptr<CFrame> CGame::GetCurrentFrame		() 								const { return GetFrame(uCurrentFrameNumber); 	}
std::shared_ptr<CFrame> CGame::GetFrame 			(unsigned short nFrameNumber) 	const { return vpFrames.at(nFrameNumber); 		}
unsigned short 			CGame::GetCurrentFrameNumber() 								const { return uCurrentFrameNumber; 			}
unsigned short 			CGame::GetRestOfItems		() 								const { return uRestOfItems; 					}
unsigned 				CGame::GetTotal 			() 								const { return uTotal; 							}

void CGame::ModifyCurrentTrialNumber()
	{
		UpdateRestOfItems();

		if (GetCurrentFrame()->GetCurrentTrialNumber() == static_cast<unsigned short>(TRIAL_NUMBER::SECOND))
		{
			//Log("RestOfItems after 2nd trial: " + std::to_string(uRestOfItems));

            if (GetCurrentFrame()->GetSecondTrialItems() + GetCurrentFrame()->GetFirstTrialItems() == puUtil->GetMaxItems() && 
            	GetCurrentFrame()->GetFirstTrialItems() < puUtil->GetMaxItems())
			{
				GetCurrentFrame()->SetFlags(FLAGS::SPARE);

                puUtil->Log("2nd trial TOTAL BEFORE /: " + std::to_string(uTotal));
				uTotal += puUtil->GetMaxItems();
                puUtil->Log("2nd trial TOTAL AFTER /: " + std::to_string(uTotal));

				if (uCurrentFrameNumber >= 1 && 
					GetFrame(uCurrentFrameNumber - 1)->GetFlags() == FLAGS::STRIKE)
				{
                    puUtil->Log("2nd trial TOTAL BEFORE X/: " + std::to_string(uTotal));
					uTotal += puUtil->GetMaxItems();
                    puUtil->Log("2nd trial TOTAL AFTER X/: " + std::to_string(uTotal));
				}
			}
            else if (GetCurrentFrame()->GetFirstTrialItems() == puUtil->GetMaxItems())
			{
				GetCurrentFrame()->SetFlags(FLAGS::STRIKE);

                puUtil->Log("2nd trial TOTAL BEFORE: " + std::to_string(uTotal));
				uTotal += puUtil->GetMaxItems();
                puUtil->Log("2nd trial TOTAL AFTER: " + std::to_string(uTotal));

				if (uCurrentFrameNumber > 1)
				{
                    std::shared_ptr<CFrame> FrPrevious = GetFrame(uCurrentFrameNumber - 1);
                    std::shared_ptr<CFrame> FrPrevPrevious = GetFrame(uCurrentFrameNumber - 2);

					if (uCurrentFrameNumber >= 2 && 
						FrPrevious->GetFlags() == FLAGS::STRIKE && 
						FrPrevPrevious->GetFlags() == FLAGS::STRIKE)
					{
                        puUtil->Log("2nd trial TOTAL BEFORE XXX: " + std::to_string(uTotal));
						uTotal += puUtil->GetMaxItems() + puUtil->GetMaxItems();
                        puUtil->Log("2nd trial TOTAL AFTER XXX: " + std::to_string(uTotal));
					}
					else if (FrPrevious->GetFlags() == FLAGS::STRIKE)
					{
                        puUtil->Log("2nd trial TOTAL BEFORE XX: " + std::to_string(uTotal));
						uTotal += puUtil->GetMaxItems();
                        puUtil->Log("2nd trial TOTAL AFTER XX: " + std::to_string(uTotal));
					}
				}
			}
			else
			{
				GetCurrentFrame()->SetFlags(FLAGS::NOTHING);

                puUtil->Log("2nd trial TOTAL BEFORE nothing: " + std::to_string(uTotal));
				unsigned uCurrentTotal = GetCurrentFrame()->GetSecondTrialItems() + GetCurrentFrame()->GetFirstTrialItems();
				uTotal += uCurrentTotal;
                puUtil->Log("2nd trial TOTAL AFTER nothing: " + std::to_string(uTotal));

				if (uCurrentFrameNumber >= 1 && GetFrame(uCurrentFrameNumber - 1)->GetFlags() == FLAGS::STRIKE)
				{
                    puUtil->Log("2nd trial TOTAL BEFORE Xnothing: " + std::to_string(uTotal));
					uTotal += uCurrentTotal;
                    puUtil->Log("2nd trial TOTAL AFTER Xnothing: " + std::to_string(uTotal));
				}
			}

			if (GetCurrentFrame()->Get10thFrame())
			{
                if (GetCurrentFrame()->GetFirstTrialItems() == puUtil->GetMaxItems() || 
                	GetCurrentFrame()->GetFirstTrialItems() + GetCurrentFrame()->GetSecondTrialItems() == puUtil->GetMaxItems())
                {
                    GetCurrentFrame()->SetCurrentTrialNumber(static_cast<unsigned short>(TRIAL_NUMBER::THIRD));
                }
                else
                {
					GameOver();
                    return;
                }

				if (uRestOfItems == puUtil->GetMaxItems()) //During 10th frame it was XX situation
				{
                    if (GetCurrentFrame()->GetFlags() == FLAGS::STRIKE)
                    {
                        puUtil->Log("2nd trial TOTAL BEFORE 10th XX: " + std::to_string(uTotal));
                        uTotal += puUtil->GetMaxItems();
                        puUtil->Log("2nd trial TOTAL AFTER 10th XX: " + std::to_string(uTotal));

                        std::shared_ptr<CFrame> FrPrevious = GetFrame(uCurrentFrameNumber - 1);
                        if (FrPrevious->GetFlags() == FLAGS::STRIKE)
					    {
                            puUtil->Log("2nd trial TOTAL BEFORE 10th XXX: " + std::to_string(uTotal));
						    uTotal += puUtil->GetMaxItems();
                            puUtil->Log("2nd trial TOTAL AFTER 10th XXX: " + std::to_string(uTotal));
					    }
                    }
				}
			}
			else
			{
				GetCurrentFrame()->SetCurrentTrialNumber(static_cast<unsigned short>(TRIAL_NUMBER::FIRST));
			}
		}
		else if (GetCurrentFrame()->GetCurrentTrialNumber() == static_cast<unsigned short>(TRIAL_NUMBER::FIRST))
		{
			GetCurrentFrame()->SetCurrentTrialNumber(static_cast<unsigned short>(TRIAL_NUMBER::SECOND));

			if (uCurrentFrameNumber >= 1 && GetFrame(uCurrentFrameNumber - 1)->GetFlags() == FLAGS::SPARE)
			{
                puUtil->Log("1st trial TOTAL BEFORE /: " + std::to_string(uTotal));
				uTotal += GetCurrentFrame()->GetFirstTrialItems();
                puUtil->Log("1st trial TOTAL AFTER /: " + std::to_string(uTotal));
			}
            else if (uCurrentFrameNumber >= 2 && 
            		GetFrame(uCurrentFrameNumber - 2)->GetFlags() == FLAGS::STRIKE && 
            		GetFrame(uCurrentFrameNumber - 1)->GetFlags() == FLAGS::STRIKE)
			{
                puUtil->Log("1st trial TOTAL BEFORE XX: " + std::to_string(uTotal));
				uTotal += GetCurrentFrame()->GetFirstTrialItems();
                puUtil->Log("1st trial TOTAL AFTER XX: " + std::to_string(uTotal));
			}

			//Log("RestOfItems after 1st trial: " + std::to_string(uRestOfItems));
		}
        else
        {
            puUtil->Log("3rd trial TOTAL BEFORE: " + std::to_string(uTotal));
            uTotal += GetCurrentFrame()->GetFirstTrialItems();
            puUtil->Log("3rd trial TOTAL AFTER: " + std::to_string(uTotal));
        }
	}

void CGame::IncCurrentFrame() 
	{ 
		++uCurrentFrameNumber; 
		if (uCurrentFrameNumber == puUtil->GetMaxFrames() - 1)
			GetCurrentFrame()->Set10thFrame(true);
	}

void CGame::UpdateRestOfItems() 
	{ 

		if (GetCurrentFrame()->GetCurrentTrialNumber() == static_cast<unsigned short>(TRIAL_NUMBER::FIRST))
		{
			uRestOfItems = puUtil->GetMaxItems() - GetCurrentFrame()->GetFirstTrialItems();
		}
		else
		{
			if (GetCurrentFrame()->Get10thFrame())
			{
				if (GetCurrentFrame()->GetFirstTrialItems() == puUtil->GetMaxItems())
				{
					if (GetCurrentFrame()->GetSecondTrialItems() == puUtil->GetMaxItems())
					{
						uRestOfItems = puUtil->GetMaxItems(); 
					}
					else
					{
						uRestOfItems = puUtil->GetMaxItems() - GetCurrentFrame()->GetSecondTrialItems();
					}
				}
				else
				{
					uRestOfItems = puUtil->GetMaxItems() - GetCurrentFrame()->GetFirstTrialItems() - GetCurrentFrame()->GetSecondTrialItems();
				}
			}
			else
			{
				uRestOfItems = puUtil->GetMaxItems();
			}
		}
	}

void CGame::GameOver() 
{ 
	std::cout << "Game Over!!!" << std::endl; 
}