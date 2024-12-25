#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <limits>
#include <cctype>
#include <stdexcept>


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

        int player1_wins = 0;
        int player2_wins = 0;
        int bot_wins = 0;

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

        void play_ai_medium();
        void bot_cmove();

    //---------------------------------------------------

        void update_score(const Gamer& player);
        std::string give_score();
        void hnowValid(std::string& expression);
        bool hisvalid(std::string& answer, int a);
    };
}

bool isvalid(const std::string& answer, int a);
void nowValid(std::string& expression);
void validateAnswer(const std::string& answer, int condition);
bool hello();
bool againHello();
int format();
std::string mode();
std::string level();
bool question();
void bye();