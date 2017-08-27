#include <iostream>
#include <sstream>
#include <cstring>

#ifdef _WIN32
#include <conio.h>
#else
#include <cstdio>
#include <termios.h>
#include <unistd.h>
#endif

#include "Model.h"

static const int32_t max_number_of_clients = 10;
static const int32_t min_number_of_clients = 1;

static void usage()
{
	std::cout << "thread_safe_priority_queue [--number_of_clients <number_of_clients>], " << std::endl <<
				 "where <number_of_clients> need to be between " << min_number_of_clients << " and " << max_number_of_clients << std::endl;
}

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

int main(int argc, char** argv)
{
	std::string userFolder;

/*#ifdef _WIN32
	userFolder = getenv("HOMEDRIVE") + getenv("HOMEPATH");
#else
	userFolder = getenv("HOME");
#endif*/
	
	int32_t num = 0;
	std::string arg ("--number_of_clients");
	if (argc == 1)
	{
		do
		{
			std::cout << 	"Please input number of clients from " 	<< 
							min_number_of_clients 					<< 
							" to " 									<< 
							max_number_of_clients 					<<
							": ";

			std::string cl_number("");
			std::getline(std::cin, cl_number);
			std::stringstream ss(cl_number);
			ss >> num;
		} while (num < min_number_of_clients || num > max_number_of_clients);
	}
	else if (argc != 3)
	{
		usage();
		return 1;
	}
	else if (strncmp(argv[1], arg.c_str(), arg.length()) != 0)
	{
		usage();
		return 1;
	}
	else
	{
		std::stringstream ss(argv[2]);
		ss >> num;

		if (num < min_number_of_clients || num > max_number_of_clients)
		{
			usage();
			return 2;
		}
	}

	std::string logFile(userFolder + std::string("ClientServer.log"));

	Model cs(num, logFile);

	char total_finish = 'n';
	do
	{
		cs.start();

		char finish = 'n';
		do
		{
			std::cerr << "Do you want to EXIT? [y/n]: ";

			finish = 
			#ifdef _WIN32
				_getch();
			#else
				getche();
			#endif
			std::cerr << std::endl;

			if (finish == 'y' || finish == 'Y')
				cs.stop();
		} while (finish != 'y' && finish != 'Y');

		do
		{
			std::cerr << "Do you want to CLOSE THE PROGRAM [y/n]: ";

			total_finish =  
			#ifdef _WIN32
				_getch();
			#else
				getche();
			#endif
			std::cerr << std::endl;
		} while (	total_finish != 'y' && 
					total_finish != 'Y' &&
					total_finish != 'n' && 
					total_finish != 'N');

	} while (total_finish != 'y' && total_finish != 'Y');

	return 0;
}
