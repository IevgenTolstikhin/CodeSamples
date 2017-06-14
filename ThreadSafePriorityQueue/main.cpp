#include <iostream>
#include <sstream>

#include "Model.h"

int main(int argc, char** argv)
{
	const int32_t max_number_of_clients = 10;
	const int32_t min_number_of_clients = 1;

	std::string userFolder;
/*
#ifdef _WIN32
	userFolder = std::string(getenv("HOMEDRIVE")) + std::string(getenv("HOMEPATH"));
#else
	userFolder = std::string(getenv("HOME"));
#endif
*/

	int32_t num = 0;
	do
	{
		std::cout << "Please input number of clients from 1 to 10: ";
		std::string cl_number("");
		std::getline(std::cin, cl_number);
		std::stringstream ss(cl_number);
		ss >> num;
	} while (num < min_number_of_clients || num > max_number_of_clients);

	Model cs(num, userFolder + std::string("ClientServer.log"));
	cs.start();

	char c;
	do
	{
		std::cout << "Do you want to exit? [y/n]\n";
		c = getchar();
		if (c == 'y')
			cs.stop();
	} while (c != 'y');

	return 0;
}