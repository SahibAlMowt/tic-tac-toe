#include <iostream>
#include <string>
#include <cctype>
#include "game.h"
#include <stdexcept>

bool isvalid(const std::string& answer, int a) {
    switch (a) {
        case 1:
            return (answer == "yes" || answer == "no");
        case 2:
            return (answer == "1" || answer == "2" || answer == "3" ||
                    answer == "3x3" || answer == "4x4" || answer == "5x5");
        case 3:
            return (answer == "stop" || answer == "continue");
        case 4:
            return (answer == "1" || answer == "2");
        case 5:
            return (answer == "1" || answer == "2" || answer == "easy" || answer == "hard");
        default:
            return false;
    }
}

void nowValid(std::string& expression) {
    size_t pos = 0;
    while ((pos = expression.find(' ', pos)) != std::string::npos) {
        expression.erase(pos, 1);
    }
    for (char& ch : expression) {
        ch = std::tolower(static_cast<unsigned char>(ch));
    }
}

bool hello() {
    std::string answer;
    while (true) {
        std::cout << "--------------------------------------------------------------------------------\n";
        std::cout << "              hello user, wanna play a round of tic-tac-toe? yes/no             \n";
        std::getline(std::cin, answer);
        nowValid(answer);

        if (answer.empty()) {
            std::cerr << "To play this game, you need to answer us. Let's try again.\n";
        } else if (!isvalid(answer, 1)) {
            std::cerr << "You can only answer yes or no. Let's try again.\n";
        } else if (answer == "no") {
            std::cout << "why you run a program with name  ``tic - tac - toe``  if you don't want to play?\n\n";
            std::cout << "            don't you think about the time we spent on this project?            \n";
            std::cout << "                    we are very upset about your decision :<                    \n\n";
            std::cout << "         bye-bye, next time come back only if you want to play ( /'^'/)         \n";
            std::cout << "--------------------------------------------------------------------------------\n";
            return false;
        } else {
            break; 
        }
    }
    return true;
}

bool againHello() {
    std::string answer;
    while (true) {
        std::cout << "--------------------------------------------------------------------------------\n";
        std::cout << "   Nice to see you again user, wanna play another round of tic-tac-toe? yes/no  \n";
        std::getline(std::cin, answer);
        nowValid(answer);

        if (answer.empty()) {
            std::cerr << "To play this game, you need to answer us. Let's try again.\n";
        } else if (!isvalid(answer, 1)) {
            std::cerr << "You can only answer yes or no. Let's try again.\n";
        } else if (answer == "no") {
            std::cout << "                 We thought you wanted to play more <(0-0)>\n";
            std::cout << "  But it's totally okay, sometimes people get bored even if they like the game\n";
            std::cout << "         We will be waiting for the next time you want play <3 =3 <3\n";
            std::cout << "--------------------------------------------------------------------------------\n";
            return false;
        } else {
            break; 
        }
    }
    return true;
}

int format() {
    std::string answer;
    while (true) {
        std::cout << "--------------------------------------------------------------------------------\n";
        std::cout << "                          select the game format:                               \n";
        std::cout << "                         1. 3x3   2. 4x4   3. 5x5                                \n";
        std::getline(std::cin, answer);
        nowValid(answer);

        if (answer.empty()) {
            std::cerr << "To play this game, you need to answer us. Let's try again.\n";
        } else if (!isvalid(answer, 2)) {
            std::cerr << "Invalid input, let's try again.\n";
        } else if (answer == "1" || answer == "3x3") {
            return 3; 
        } else if (answer == "2" || answer == "4x4") {
            return 4;
        } else if (answer == "3" || answer == "5x5") {
            return 5; 
        } else {
            std::cerr << "Something went wrong.\n";
        }
    }
}

std::string mode() {
    std::string answer;
    while (true) {
        std::cout << "--------------------------------------------------------------------------------\n";
        std::cout << "                           select the game mode:                               \n";
        std::cout << "                   1. player vs player   2. player vs AI                     \n";
        std::getline(std::cin, answer);
        nowValid(answer);

        if (answer.empty()) {
            std::cerr << "To play this game, you need to answer us. Let's try again.\n";
        } else if (!isvalid(answer, 4)) {
            std::cerr << "Invalid input, you need to enter only `1` or `2` without brackets, let's try again.\n";
        } else if (isvalid(answer, 4)) {
            return answer;
        } else {
            std::cerr << "Something went wrong.\n";
        }
    }
}

std::string level() {
    std::string answer;
    while (true) {
        std::cout << "--------------------------------------------------------------------------------\n";
        std::cout << "                          select the game level:                               \n";
        std::cout << "                            1. easy   2. hard                     \n";
        std::getline(std::cin, answer);
        nowValid(answer);

        if (answer.empty()) {
            std::cerr << "To play this game, you need to answer us. Let's try again.\n";
        } else if (!isvalid(answer, 5)) {
            std::cerr << "Invalid input, let's try again.\n";
        } else if (answer == "1" || answer == "easy") {
            return "easy"; 
        } else if (answer == "2" || answer == "hard") {
            return "hard";
        } else {
            std::cerr << "Something went wrong.\n";
        }
    }
}

bool bye(){
    std::string answer;
    while(true){
        std::cout << "--------------------------------------------------------------------------------\n";
        std::cout << "          Want to play again or it's enough fun for you? stop/continue?\n";
        std::getline(std::cin, answer);
        nowValid(answer);
        if (answer.empty()) {
            std::cerr << "To play this game, you need to answer us. Let's try again.\n";
        } else if(!isvalid(answer, 3)){
            std::cerr << "Invalid input, let's try again.\n";
        }else{
            return answer == "continue";
        }
    }
}

int main(){
    int n;
    std::string ourmode;
    std::string ourlevel;
    std::string name1;
    std::string name2 = "me";
    int flag = 0;
    std::string answer;
    std::string expression;
    do {
        
        try {
            if(flag){
                if(!againHello()){
                    break;
                }
            }else if (!hello()) {
                break;
            }
            n = format();
            std::cout << "--------------------------------------------------------------------------------\n";
            std::cout << "                         Game format selected: " << n << "x" << n << "               \n";

            expression = mode();

            ourmode = (expression == "1") ? "player vs player" : "player vs AI";
            expression.clear();
            std::cout << "--------------------------------------------------------------------------------\n";
            std::cout << "                    Game mode selected: " << ourmode << "               \n";
            std::cout << "--------------------------------------------------------------------------------\n";
            std::cout << "                    Enter your nickname for this game:\n";
            std::getline(std::cin, name1);

            if(ourmode == "player vs player"){
                std::cout << "            Enter nickname of your opponent for this game:\n";
                std::getline(std::cin, name2);
                //std::cout << "                    Choose what you will play for\n";
                game::Tictactoe tictactoe(n, name1, name2);
                tictactoe.play_vs();
            }else if(ourmode == "player vs AI"){
                ourlevel = level();

                std::cout << "--------------------------------------------------------------------------------\n";
                std::cout << "                        Game level selected: " << ourlevel << "               \n";
                game::Tictactoe tictactoe(n, name1, name2);
                tictactoe.play_ai();
            }


            if(!bye()){
                std::cout << "--------------------------------------------------------------------------------\n";
                std::cout << "                       Thank you for trying our game :3\n";
                std::cout << "             Bye-Bye we'll be happy to see you next time (=^.^=)\n";
                std::cout << "--------------------------------------------------------------------------------\n";
                break;
            }
            flag = 1;
        } catch (const std::exception& e) {
            std::cerr << "error: " << e.what() << std::endl;
        }

    } while (true);
    return 0;
}