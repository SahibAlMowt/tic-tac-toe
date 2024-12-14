#include <iostream>
#include <vector>
#include <ctime>
#include <string>

namespace game 
{
    struct Gamer
    {
        std::string name;
        char sym;
    };

    class Tictactoe
    {
    private:
        size_t size;
        Gamer player1;
        Gamer player2;

        void printboard();
    };
}