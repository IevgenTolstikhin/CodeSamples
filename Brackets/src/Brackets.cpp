#include <iostream>
#include "BracketClass.h"

int
main( int argc, char** argv )
{
    if ( argc != 2 )
    {
        std::cout << "Invalid amount of arguments" << std::endl;
        return 1;
    }

    std::string input( argv[ 1 ] );

    Brackets brackets(std::move(input));
    auto errors = brackets.checkData();

    switch (errors)
    {
      case Brackets::Errors::OK:
        std::cout << "All brackets are in correct sequence" << std::endl;
        return 0;
      case Brackets::Errors::INVALID_SEQUENCE:
        std::cout << "Invalid sequence of brackets" << std::endl;
        return 2;
      default:
        std::cout << "Incorrect error code" << std::endl;
        return 3;
    }

    return 0;
}
