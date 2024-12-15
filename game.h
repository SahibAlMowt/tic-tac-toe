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

        std::vector<std::vector<char>> board;  

    public:
        Tictactoe(size_t s, const std::string name1, const std::string name2);
        void printboard();

        Gamer player1;
        Gamer player2;
    };
}