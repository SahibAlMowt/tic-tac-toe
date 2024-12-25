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

TEST_SUITE("Arina's tests")
{
    TEST_CASE("Test hello function") {
    std::istringstream input("yes");
    std::cin.rdbuf(input.rdbuf());

    CHECK(hello() == true); 
    }

    TEST_CASE("Test againHello function") {
        std::istringstream input("no");
        std::cin.rdbuf(input.rdbuf());

        CHECK(againHello() == false);  
    }

    TEST_CASE("Test format function") {
        std::istringstream input("1");
        std::cin.rdbuf(input.rdbuf());

        CHECK(format() == 3);  

        input.str("2");
        std::cin.rdbuf(input.rdbuf());
        
        CHECK(format() == 4);  

        input.str("3");
        std::cin.rdbuf(input.rdbuf());
        
        CHECK(format() == 5);  
    }

    TEST_CASE("Test mode function") {
        std::istringstream input("1");
        std::cin.rdbuf(input.rdbuf());

        CHECK(mode() == "1");  

        input.str("2");
        std::cin.rdbuf(input.rdbuf());

        CHECK(mode() == "2");  
    }

    TEST_CASE("Test level function") {
        std::istringstream input("easy");
        std::cin.rdbuf(input.rdbuf());

        CHECK(level() == "easy");  

        input.str("medium");
        std::cin.rdbuf(input.rdbuf());

        CHECK(level() == "medium");  
    }

    TEST_CASE("validateAnswer") {
        CHECK_THROWS(validateAnswer("maybe", 5)); 
        CHECK_THROWS(validateAnswer("", 4));       
        CHECK_THROWS(validateAnswer("start", 3));   
        CHECK_THROWS_AS(validateAnswer("", 1), std::invalid_argument);
        CHECK_THROWS_AS(validateAnswer("stop", 1), std::runtime_error);
        CHECK_THROWS_AS(validateAnswer("invalid", 2), std::invalid_argument);
        CHECK_NOTHROW(validateAnswer("yes", 1));
        CHECK_NOTHROW(validateAnswer("3x3", 2));
    }


    TEST_CASE("isvalid") {
        CHECK(isvalid("yes", 1) == true);
        CHECK(isvalid("no", 1) == true);
        CHECK(isvalid("maybe", 1) == false);
        CHECK(isvalid("3x3", 2) == true);
        CHECK(isvalid("4x4", 2) == true);
        CHECK(isvalid("5x5", 2) == true);
        CHECK(isvalid("continue", 3) == true);
        CHECK(isvalid("stop", 3) == true);
        CHECK(isvalid("123", 3) == false);
        CHECK(isvalid("1", 4) == true);
        CHECK(isvalid("2", 4) == true);
        CHECK(isvalid("medium", 5) == true);
        CHECK(isvalid("easy", 5) == true);
        CHECK(isvalid("hard", 5) == false);
    }

    TEST_CASE("nowValid") {
        std::string input = "  HeLLo World ";
        nowValid(input);
        CHECK(input == "helloworld");
        
        input = "  TiC   Tac  Toe ";
        nowValid(input);
        CHECK(input == "tictactoe");
    }

    TEST_CASE("nowValidname") {
        std::string input = " Player 1 ";
        nowValidname(input);
        CHECK(input == "Player1");

        input = "Another  Player ";
        nowValidname(input);
        CHECK(input == "AnotherPlayer");
    }
}