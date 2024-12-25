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

    TEST_CASE("bool draw")
    {
        game::Tictactoe examp(3 , "first", "second");

        examp.move(0, 0, 'X');
        examp.move(0, 1, 'O');
        examp.move(0, 2, 'O');
        examp.move(1, 0, 'O');
        examp.move(1, 1, 'X');
        examp.move(1, 2, 'X');
        examp.move(2, 0, 'X');
        examp.move(2, 1, 'O');
        examp.move(2, 2, 'O');

        CHECK(examp.draw());
    }

    TEST_CASE("bool move")
    {
        game::Tictactoe examp(3 , "first", "second");

        CHECK(examp.move(0, 0, 'X'));
    }
    
}