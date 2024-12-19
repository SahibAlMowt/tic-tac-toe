#include "game.h"

void game::Tictactoe::printboard()
{
    std::string line = std::string(size * 4 - 1, '-'); 

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

game::Tictactoe::Tictactoe(size_t s, const std::string name1, const std::string name2)
{
    size = s;
    board = std::vector<std::vector<char>>(s, std::vector<char>(s, ' '));

    player1 = {name1, 'O', false};
    player2 = {name2, 'X', false};

    bot = {"bot", 'Y', true};
}

bool game::Tictactoe::move(size_t row, size_t col, char sym)
{
    if(row >= size || col >= size || board[row][col] != ' ')
    {
        return false;
    }

    board[row][col] = sym;
    return true;
}

void game::Tictactoe::play_vs()
{
    bool current = true;
    bool gameplay = true;

    while(gameplay)
    {
        printboard();

        const Gamer *player;

        if(current)
        {
            player = &player1;
        }
        else
        {
            player = &player2;
        }

        std::cout << (*player).name << " play '" << (*player).sym << "'\t";

        size_t row;
        std::cin >> row;
        row -= 1;

        size_t col;
        std::cin >> col;
        col -= 1;

        if (!move(row, col, (*player).sym)) 
        {
            std::cout << "try again.\n";
            continue;
        }

        if(win((*player).sym))
        {
            printboard();
            std::cout << (*player).name << " wins\n";
            gameplay = false;
        }
        else if(draw())
        {
            printboard();
            std::cout << "draw\n";
            gameplay = false;
        }
        else
        {
            if(current)
            {
                current = false;
            }
            else
            {
                current = true;
            }
        }
    }
}

bool game::Tictactoe::win(char sym)
{
    for(size_t i = 0; i < size; i++)
    {
        bool row_win = true;
        bool col_win = true;

        for(size_t j = 0; j < size; j++)
        {
            if(board[i][j] != sym)
            {
                row_win = false;
            }
            if(board[j][i] != sym)
            {
                col_win = false;
            }
        }

        if(row_win || col_win)
        {
            return true;
        }
    }

    bool ldiag = true;
    bool rdiag = true;

    for (size_t i = 0; i < size; i++)
    {
        if (board[i][i] != sym)
        {
            ldiag = false;
        } 
        if (board[i][size - 1 - i] != sym) 
        {
            rdiag = false;
        }
    }

    return ldiag || rdiag;
}

bool game::Tictactoe::draw()
{
    for(size_t i = 0; i < size; i++)
    {
        for(size_t j = 0; j < size; j++)
        {
            if(board[i][j] == ' ')
            {
                return false;
            }
        }
    }

    return true;
}

void game::Tictactoe::play_ai()
{
    bool current = true;
    bool gameplay = true;

    while(gameplay) 
    {
        printboard();

        const Gamer *player;

        if(current) 
        {
            player = &player1;
            std::cout << (*player).name << " play '" << (*player).sym << "'\n";

            size_t row;
            std::cin >> row;
            row -= 1;

            size_t col;
            std::cin >> col;
            col -= 1;

            if (!move(row, col, (*player).sym)) 
            {
                std::cout << "try again.\n";
                continue;
            }
        } 
        else 
        {
            player = &bot;
            bot_move();
        }

        if(win((*player).sym))
        {
            printboard();
            std::cout << (*player).name << " wins\n";
            gameplay = false;
        }
        else if(draw())
        {
            printboard();
            std::cout << "draw\n";
            gameplay = false;
        }
        else
        {
            current = !current;
        }
    }
}

void game::Tictactoe::bot_move()
{
    size_t row;
    size_t col;

    do
    {
        row = std::rand() % size;
        col = std::rand() % size;

    } while(board[row][col] != ' ');
    
    std::cout << "bot plays\n";
    move(row, col, bot.sym);
}