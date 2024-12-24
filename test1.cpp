#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "game.h"

TEST_SUITE("sam's tests")
{
    TEST_CASE("bool win")
    {
        game::Tictactoe examp(3 , "first", "second");

        examp.move(0, 0, 'X');
        examp.move(0, 1, 'X');
        examp.move(0, 2, 'X');

        CHECK(examp.win('X'));
    }
    
}