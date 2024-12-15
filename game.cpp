#include "game.h"

void game::Tictactoe::printboard()
{
    std::string line = std::string(size * 4, '-'); 

    for(size_t i = 0; i != size; i++)
    {
        for(size_t j = 0; j != size; j++)
        {
            std::cout << " " << board[i][j] << " ";
            if(j < size - 1)
            {
                std::cout << "|";
            } 
        }
        std::cout << "\n";

        if(i < size - 1)
        {
            std::cout << line << "\n";
        }
    }
    std::cout << "\n";
}

game::Tictactoe::Tictactoe(size_t s)
{
    size = s;
    board = std::vector<std::vector<char>>(s, std::vector<char>(s, ' '));
}