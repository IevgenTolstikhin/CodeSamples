#include <memory>
#include <iostream>

#include "Lane.h"

#ifdef _WIN32
#include <conio.h>
#else
#include <cstdio>
#include <termios.h>
#include <unistd.h>
#endif

#ifndef _WIN32
/* reads from keypress, echoes */
static int getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
#endif

static unsigned MAX_AMOUNT_OF_PLAYERS = 10;

int main()
{
	do
	{
		unsigned uAmountOfPlayers = 0;
		std::cout << "Input amount of players: ";
		std::cin >> uAmountOfPlayers;

		if (uAmountOfPlayers < MAX_AMOUNT_OF_PLAYERS && uAmountOfPlayers > 0)
		{
			CLane lane (uAmountOfPlayers);
			lane.Play();
			return 0;
		}
		else
		{
			char retry = 'n';
			do
			{
				std::cerr << "Wrong amount of players. Retry? [y/n]: ";

				retry = 
				#ifdef _WIN32
					_getch();
				#else
					getche();
				#endif
				std::cerr << std::endl;

				if (retry == 'n' || retry == 'N')
					return 0;

			} while (retry != 'y' && retry != 'Y');
		}
	} while (true);

	return 0;
}