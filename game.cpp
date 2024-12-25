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

void game::Tictactoe::update_score(const Gamer& player)
{
    if (player.name == player1.name) {
        player1_wins++;
    } else if (player.name == player2.name) {
        player2_wins++;
    } else if (player.name == "bot"){
        bot_wins++;
    }
}

std::string game::Tictactoe::give_score()
{
    if(player1_wins == 1){
        return "yourwin";
    }
    if(player2_wins == 1){
        return "opponentwin";
    }
    if(bot_wins == 1){
        return "botwin";
    }
        
}

void game::Tictactoe::hnowValid(std::string& expression) {
    size_t pos = 0;
    while ((pos = expression.find(' ', pos)) != std::string::npos) {
        expression.erase(pos, 1);
    }
    for (char& ch : expression) {
        ch = std::tolower(static_cast<unsigned char>(ch));
    }
}

bool game::Tictactoe::hisvalid(std::string& answer, int a)
{
    switch (a) {
        case 1:
            return (answer == "x" || answer == "o");
        default:
            return false;
    }
}

game::Tictactoe::Tictactoe(size_t s, const std::string name1, const std::string name2)
{
    size = s;
    board = std::vector<std::vector<char>>(s, std::vector<char>(s, ' '));

    char c;
    std::string input;
    while(true){
        std::cout << "                  Choose what you will play for(X/O):\n";
        std::getline(std::cin, input);
        game::Tictactoe::hnowValid(input);
        if(input == "stop"){
            throw std::runtime_error("game ended");
        }
        if(!game::Tictactoe::hisvalid(input, 1)){
            std::cerr << "       wrong answer, you can only input x or o(letters on keyboard)\n";
            continue;
        }
        c = input[0];
        break;
    }


    if(c == 'o')
    {
        player1 = {name1, 'O', false};
        player2 = {name2, 'X', false};

        bot = {"bot", 'X', true};
    }
    else
    {
        player1 = {name1, 'X', false};
        player2 = {name2, 'O', false};

        bot = {"bot", 'O', true};
    }
    
}

bool game::Tictactoe::move(size_t row, size_t col, char sym)
{
    if(row == 665 || col == 665){
        throw std::runtime_error("game ended");
    }
    if(row >= size || col >= size || board[row][col] != ' ')
    {
        return false;
    }

    board[row][col] = sym;
    return true;
}

void game::Tictactoe::play_vs()
{
    bool current = (player1.sym == 'X');
    bool gameplay = true;

    while(gameplay)
    {
        printboard();

        const Gamer* player = current ? &player1 : &player2;


        std::cout << (*player).name << " play '" << (*player).sym << "'\t";

        size_t row;
        while (true) 
        {
            std::cin >> row;
            if (std::cin.fail()) 
            {
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                std::cerr << "           You need to enter only number of your row and line";            } 
            else 
            {
                break; 
            }
        }
        row -= 1;

        size_t col;
        while (true) 
        {
            std::cin >> col;
            if (std::cin.fail()) 
            {
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                std::cerr << "           You need to enter only number of your row and line";
            } 
            else 
            {
                break; 
            }
        }
        col -= 1;

        if (!move(row, col, (*player).sym)) 
        {
            std::cerr << "this spot is not allowed for your sign, try again\n";
            continue;
        }

        if(win((*player).sym))
        {
            printboard();
            std::cout << (*player).name << " wins! Congratulations!\n";
            game::Tictactoe::update_score(*player);
            gameplay = false;
        }
        else if(draw())
        {
            printboard();
            std::cout << "It's a draw, but you can try again :)\n";
            gameplay = false;
        }
        else
        {
            current = !current;
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

void game::Tictactoe::play_ai_easy()
{
    bool current = (player1.sym == 'X');

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
            while (true) 
            {
                std::cin >> row;
                if (std::cin.fail()) 
                {
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    std::cerr << "           You need to enter only number of your row and line";
                } 
                else 
                {
                    break; 
                }
            }
            row -= 1;

            size_t col;
            while (true) 
            {
                std::cin >> col;
                if (std::cin.fail()) 
                {
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    std::cerr << "           You need to enter only number of your row and line";
                } 
                else 
                {
                    break; 
                }
            }
             col -= 1;

            if (!move(row, col, (*player).sym)) 
            {
                std::cerr << "this spot is not allowed for your sign, try again\n";
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
            std::cout << (*player).name << " wins!\n";
            game::Tictactoe::update_score(*player);
            gameplay = false;
        }
        else if(draw())
        {
            printboard();
            std::cout << "It's a draw, but you can try again :)\n";
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

void game::Tictactoe::play_ai_medium()
{
    bool current = (player1.sym == 'X');

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
            while (true) 
            {
                std::cin >> row;
                if (std::cin.fail()) 
                {
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    std::cerr << "           You need to enter only number of your row and line";
                } 
                else 
                {
                    break; 
                }
            }
            row -= 1;

            size_t col;
            while (true) 
            {
                std::cin >> col;
                if (std::cin.fail()) 
                {
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    std::cerr << "           You need to enter only number of your row and line";
                } 
                else 
                {
                    break; 
                }
            }
            col -= 1;

            if (!move(row, col, (*player).sym)) 
            {
                std::cerr << "this spot is not allowed for your sign, try again\n";
                continue;
            }
        } 
        else 
        {
            player = &bot;
            bot_cmove();
        }

        if(win((*player).sym))
        {
            printboard();
            std::cout << (*player).name << " wins!\n";
            game::Tictactoe::update_score(*player);
            gameplay = false;
        }
        else if(draw())
        {
            printboard();
            std::cout << "It's a draw, but you can try again :)\n";
            gameplay = false;
        }
        else
        {
            current = !current;
        }
    }
}

void game::Tictactoe::bot_cmove()
{
    for(size_t i = 0; i < size; i++)
    {
        for(size_t j = 0; j < size; j++)
        {
            if(board[i][j] == ' ')
            {
                board[i][j] = bot.sym;
                if(win(bot.sym))
                {
                    std::cout << "bot plays\n";
                    move(i, j, bot.sym);
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    for(size_t i = 0; i < size; i++)
    {
        for(size_t j = 0; j < size; j++)
        {
            if(board[i][j] == ' ')
            {
                board[i][j] = player1.sym;
                if(win(player1.sym))
                {
                    board[i][j] = ' ';
                    std::cout << "bot plays\n";
                    move(i, j, bot.sym);
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    bot_move();
}
       