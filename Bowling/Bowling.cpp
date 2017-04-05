#include <memory>
#include <iostream>

#include "Lane.h"
#include "Utils.h"

int main()
{
	unsigned uAmountOfPlayers = 0;
	std::cout << "Input amount of players: ";
	std::cin >> uAmountOfPlayers;
	std::cout << std::endl;
	std::shared_ptr<CLane> pLane (new CLane(uAmountOfPlayers));
	pLane->Play();

	return 0;
}