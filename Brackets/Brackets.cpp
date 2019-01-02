#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <functional>

int
main( int argc, char** argv )
{
    if ( argc != 2 )
    {
        std::cout << "Invalid amount of arguments" << std::endl;
        return 1;
    }

    std::string input( argv[ 1 ] );

    enum class RetCode : int
    {
        INVALID_SEQUENCE,
        NOT_A_BRACKET,
        NEED_STACK_PUSH,
        NEED_STACK_POP
    };

    std::unordered_map< char, std::function< RetCode( const std::stack< char >&, const char ) > >
        reactionTable;
    std::unordered_map< char, char > dict  // It can be read from some config file
        {std::make_pair( '}', '{' ), std::make_pair( ']', '[' ), std::make_pair( ')', '(' )};

    std::unordered_set< char > dict_start;

    std::transform( dict.begin( ), dict.end( ), std::inserter( dict_start, dict_start.begin( ) ),
                    []( const std::pair< char, char >& key_value ) { return key_value.second; } );

    // Use only ASCII table
    reactionTable.reserve( 128 );
    for ( char symbol = 0; symbol < 127; ++symbol )
    {
        reactionTable[ symbol ]
            = [&dict_start, &dict]( const std::stack< char >& st, const char symbol ) {
                  if ( dict.find( symbol ) != dict.end( ) )
                  {
                      if ( st.empty( ) )
                      {
                          return RetCode::INVALID_SEQUENCE;
                      }
                      else
                      {
                          if ( dict.at( symbol ) == st.top( ) )
                          {
                              return RetCode::NEED_STACK_POP;
                          }
                          else
                          {
                              return RetCode::INVALID_SEQUENCE;
                          }
                      }
                  }

                  if ( dict_start.find( symbol ) != dict_start.end( ) )
                  {
                      return RetCode::NEED_STACK_PUSH;
                  }

                  return RetCode::NOT_A_BRACKET;
              };
    }

    std::stack< char > st;
    for ( const auto& symbol : input )
    {
        switch ( reactionTable[ symbol ]( st, symbol ) )
        {
        case RetCode::INVALID_SEQUENCE:
            std::cout << "Invalid sequence of brackets" << std::endl;
            return 2;
        case RetCode::NEED_STACK_PUSH:
            st.push( symbol );
            break;
        case RetCode::NEED_STACK_POP:
            st.pop( );
            break;
        case RetCode::NOT_A_BRACKET:
        default:
            break;
        }
    }

    std::cout << "All brackets are in correct sequence" << std::endl;

    return 0;
}
