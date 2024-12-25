#include "game.h"

int main(){
    int n;
    std::string ourmode;
    std::string ourlevel;
    std::string name1;
    std::string name2 = "me";
    int flag = 0;
    std::string answer;
    std::string expression;
    int yourwin = 0;
    int opponentwin = 0;
    int botwin = 0;
    do {
        do{
            try {
                if (flag) {
                    bool playAgain = againHello(); 
                    if (!playAgain) {
                        break;
                    } else {
                        flag = 0;
                        break;
                    }
                }else if (!hello()) {
                    flag = 2;
                    break;
                }
                break;
            } catch (const std::exception& e) {
                if(std::string(e.what()) == "Game ended. Goodbye! We'll be happy to see you next time!"){
                    flag = 1;
                    break;
                }else{
                    std::cerr << "error: " << e.what() << std::endl;
                }
            }
        } while (true);

        if(flag == 2){
            flag = 0;
            break;
        }

        if(flag == 1){
            bye();
            break;
        }

        do{
            try {
                n = format();
                break;
            } catch (const std::exception& e) {
                if(std::string(e.what()) == "Game ended. Goodbye! We'll be happy to see you next time!"){
                    flag = 1;
                    break;
                }else{
                    std::cerr << "error: " << e.what() << std::endl;
                }
            }
        } while (true);

        if(flag == 1){
            bye();
            break;
        }
        std::cout << "--------------------------------------------------------------------------------\n";
        std::cout << "                         Game format selected: " << n << "x" << n << "               \n";

        do{
            try {
                expression = mode();
                break;
            } catch (const std::exception& e) {
                if(std::string(e.what()) == "Game ended. Goodbye! We'll be happy to see you next time!"){
                    flag = 1;
                    break;
                }else{
                    std::cerr << "error: " << e.what() << std::endl;
                }
            }
        } while (true);

        if(flag == 1){
            bye();
            break;
        }

        ourmode = (expression == "1") ? "player vs player" : "player vs AI";
        expression.clear();
        std::cout << "--------------------------------------------------------------------------------\n";
        std::cout << "                    Game mode selected: " << ourmode << "               \n";
        std::cout << "--------------------------------------------------------------------------------\n";
        std::cout << "                    Enter your nickname for this game:\n";
        std::getline(std::cin, name1);
        
        if(ourmode == "player vs player"){
             while (true) {
                try{
                    std::cout << "            Enter nickname of your opponent for this game:\n";
                    std::getline(std::cin, name2);

                    if (name1 == name2) {
                        throw std::invalid_argument("Player names cannot be the same. Please enter a different name for the 2nd player.\n");
                    } else {
                        break; 
                    }
                
                } catch (const std::exception& e) {
                    std::cerr << "error: " << e.what() << std::endl;
                }
            }
            std::cout << "--------------------------------------------------------------------------------\n";
            std::cout << "          Attention to the rules: you enter the row number and line\n                     where you want to put your sign \n";
            std::cout << "While gaming you can leave the game by typing 666 in row or line number(or them both)\n";
            std::cout << "                             Good luck ^-^\n";
            std::cout << "--------------------------------------------------------------------------------\n";
            game::Tictactoe tictactoe(n, name1, name2);
            tictactoe.play_vs();
            expression.clear();
                expression = tictactoe.give_score();
                if(expression == "yourwin"){
                    yourwin++;
                }else if(expression == "opponentwin"){
                    opponentwin++;
                }else if(expression == "botwin"){
                    botwin++;
                }
        }else if(ourmode == "player vs AI"){
            
            do{
                try {
                    ourlevel = level();
                    break;
                } catch (const std::exception& e) {
                    if(std::string(e.what()) == "Game ended. Goodbye! We'll be happy to see you next time!"){
                        flag = 1;
                        break;
                    }else{
                        std::cerr << "error: " << e.what() << std::endl;
                    }
                }
            } while (true);

            if(flag == 1){
                bye();
                break;
            }

            std::cout << "--------------------------------------------------------------------------------\n";
            std::cout << "                        Game level selected: " << ourlevel << "               \n";
            std::cout << "--------------------------------------------------------------------------------\n";
            std::cout << "          Attention to the rules: you enter the row number and line\n                     where you want to put your sign \n";
            std::cout << "While gaming you can leave the game by typing 666 in row or line number(or them both)\n";
            std::cout << "                             Good luck ^-^\n";
            std::cout << "--------------------------------------------------------------------------------\n";
            try{
                game::Tictactoe tictactoe(n, name1, name2);
                if(ourlevel == "easy"){
                    tictactoe.play_ai_easy();
                }
                if(ourlevel == "medium"){
                    tictactoe.play_ai_medium();
                }
                expression.clear();
                expression = tictactoe.give_score();
                if(expression == "yourwin"){
                    yourwin++;
                }else if(expression == "opponentwin"){
                    opponentwin++;
                }else if(expression == "botwin"){
                    botwin++;
                }
            }catch(const std::exception& e){
                if(std::string(e.what()) == "game ended"){
                    flag = 1;
                }else{
                    std::cerr << "error: " << e.what() << std::endl;
                }
            }
            if(flag == 1){
                bye();
                break;
            }
        }
        std::cout << "--------------------------------------------------------------------------------\n";
        std::cout << "                     your current score: "<< yourwin <<" wins\n";
        std::cout << "               your opponent's current score: "<< opponentwin <<" wins\n";
        std::cout << "                     bot's current score: "<< botwin <<" wins\n";
        std::cout << "--------------------------------------------------------------------------------\n";

        do
        {
            try
            {
                if (!question())
                {
                    flag = 1;
                }
                break;
            }
            catch (const std::exception &e)
            {
                if (std::string(e.what()) == "Game ended. Goodbye! We'll be happy to see you next time!")
                {
                    flag = 1;
                    break;
                }
                else
                {
                    std::cerr << "error: " << e.what() << std::endl;
                }
            }
            } while (true);

            if(flag == 1){
                bye();
                break;
            }

            flag = 1;

    } while (true);
    return 0;
}