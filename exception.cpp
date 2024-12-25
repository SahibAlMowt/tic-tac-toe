#include "game.h"

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
            return (answer == "1" || answer == "2" || answer == "easy" || answer == "medium");
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

void validateAnswer(const std::string& answer, int condition) {
    if (answer.empty()) {
        throw std::invalid_argument("To play this game, you need to answer us. Let's try again.");
    }
    if (answer == "stop") {
        throw std::runtime_error("Game ended. Goodbye! We'll be happy to see you next time!");
    }
    if (!isvalid(answer, condition)) {
        throw std::invalid_argument("Invalid input, let's try again.");
    }
}

bool hello() {
    std::string answer;
    
    std::cout << "--------------------------------------------------------------------------------\n";
    std::cout << "              hello user, wanna play a round of tic-tac-toe? yes/no             \n";

    std::getline(std::cin, answer);
    nowValid(answer);

    validateAnswer(answer, 1);
    if (answer == "no") {
        std::cout << "why you run a program with name  ``tic - tac - toe``  if you don't want to play?\n\n";
        std::cout << "            don't you think about the time we spent on this project?            \n";
        std::cout << "                    we are very upset about your decision :<                    \n\n";
        std::cout << "         bye-bye, next time come back only if you want to play ( /'^'/)         \n";
        std::cout << "--------------------------------------------------------------------------------\n";
        return false;
    }
    return true;
}

bool againHello() {
    std::string answer;
    std::cout << "--------------------------------------------------------------------------------\n";
    std::cout << "   Nice to see you again user, wanna play another round of tic-tac-toe? yes/no  \n";
    std::getline(std::cin, answer);
    nowValid(answer);

    validateAnswer(answer, 1);
    if (answer == "no") {
        std::cout << "                 We thought you wanted to play more <(0-0)>\n";
        std::cout << "  But it's totally okay, sometimes people get bored even if they like the game\n";
        std::cout << "         We will be waiting for the next time you want play <3 =3 <3\n";
        std::cout << "--------------------------------------------------------------------------------\n";
        return false;
    } 
    return true;
}

int format() {
    std::string answer;
    std::cout << "--------------------------------------------------------------------------------\n";
    std::cout << "   you can end the game any time later while choosing settings by input `stop`\n";
    std::cout << "--------------------------------------------------------------------------------\n";
    std::cout << "                          select the game format:                               \n";
    std::cout << "                         1. 3x3   2. 4x4   3. 5x5                                \n";
    std::getline(std::cin, answer);
    nowValid(answer);

    validateAnswer(answer, 2);
    if (answer == "1" || answer == "3x3") {
        return 3; 
    } else if (answer == "2" || answer == "4x4") {
        return 4;
    } else if (answer == "3" || answer == "5x5") {
        return 5; 
    }
}

std::string mode() {
    std::string answer;
    
    std::cout << "--------------------------------------------------------------------------------\n";
    std::cout << "                           select the game mode:                               \n";
    std::cout << "            you need to enter only `1` or `2` without brackets\n";
    std::cout << "                   1. player vs player   2. player vs AI                     \n";
    std::getline(std::cin, answer);
    nowValid(answer);

    validateAnswer(answer, 4);
    if (isvalid(answer, 4)) {
        return answer;
    }

}

std::string level() {
    std::string answer;
    
    std::cout << "--------------------------------------------------------------------------------\n";
    std::cout << "                          select the game level:                               \n";
    std::cout << "                           1. easy   2. medium                     \n";
    std::getline(std::cin, answer);
    nowValid(answer);

    validateAnswer(answer, 5);
    if (answer == "1" || answer == "easy") {
        return "easy"; 
    } else if (answer == "2" || answer == "medium") {
        return "medium";
    }
}

bool question(){
    std::string answer;
    std::cout << "--------------------------------------------------------------------------------\n";
    std::cout << "          Want to play again or it's enough fun for you? stop/continue?\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, answer);
    nowValid(answer);
    validateAnswer(answer, 3);
    return answer == "continue";
}

void bye(){
    std::cout << "--------------------------------------------------------------------------------\n";
    std::cout << "                       Thank you for trying our game :3\n";
    std::cout << "             Bye-Bye we'll be happy to see you next time (=^.^=)\n";
    std::cout << "--------------------------------------------------------------------------------\n";
}