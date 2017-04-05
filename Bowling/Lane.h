#ifndef __LANE_H__
#define __LANE_H__

#include <vector>
#include <memory>
#include <random>
#include <string>

class CUtils;
class CPlayer;
class CLane
{
	std::vector< std::shared_ptr<CPlayer> > vpPlayer;
	std::shared_ptr<CUtils> puUtil;

	std::random_device rd;
    std::mt19937 gen;
    unsigned uAmountOfItems;
    unsigned m_uAmountOfPlayers;

public:
	CLane(unsigned);
	void Play();
	void ModifyPlayer(unsigned, const std::string&);
	void AddPlayer(const std::string&);
	void WaitForKick(unsigned);
};

#endif //__LANE_H_