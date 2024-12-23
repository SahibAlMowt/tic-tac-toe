#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <limits>
#include <cctype>
#include <chrono> //
#include <thread> //

namespace game 
{
    struct Gamer
    {
        std::string name;
        char sym;
        bool bot;
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

        bool move(size_t row, size_t col, char sym);
        void play_vs();
        bool win(char sym);
        bool draw();

        void play_ai_easy();
        void bot_move();

        Gamer bot;

        void play_ai_hard();
        void bot_cmove();

        void podsvetka(char sym);
    };
}