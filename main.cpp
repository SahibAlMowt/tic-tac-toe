#include <iostream>
#include <string>
#include <stdexcept>

//я пока пишу main одним файлом не разбивая его по .h  .cpp поэтому пока с хедерами потом когда все будет готово уберем
//сейчас обрабатываются только первые два вопроса, пототм может еще немного поправлю, но пока так 

bool isvalid(std::string answer, int a){
    switch(a){
        case 1:
            if(answer == "yes" || answer == "Yes" || answer == "no" || answer == "No"){
                return true;
            }
            break;
        case 2:
            if(answer == "1" || answer == "2" || answer == "3" ||
             answer == "3x3" || answer == "4x4" || answer == "5x5"){
                return true;
            }
            break;
        default:
            break;
    }
    return false;
}

int main(){
    std::string answer;
    std::string expression;
    do {
        std::cout << "--------------------------------------------------------------------------------\n";
        std::cout << "              hello user, wanna play a round of tic-tac-toe? yes/no             \n";
        std::getline(std::cin, answer);
        
        try {
            if (answer.empty()) {
                throw std::invalid_argument("to play this game you need to answer us, let's try again\n");
            }

            if (!isvalid(answer, 1)) {
                throw std::invalid_argument("you can only answer yes or no, let's try again\n");
            }

            if (answer == "no" || answer == "No") {
                std::cout << "why you run a program with name  ``tic - tac - toe``  if you don't want to play?\n\n";
                std::cout << "            don't you think about the time we spent on this project?            \n";
                std::cout << "                    we are very upset about your decision :<                    \n\n";
                std::cout << "         bye-bye, next time come back only if you want to play ( /'^'/)         \n";
                std::cout << "--------------------------------------------------------------------------------\n";
                break;
            }

            bool validFormat = false;  
            do {
                std::cout << "--------------------------------------------------------------------------------\n";
                std::cout << "                          select the game format:                                \n";
                std::cout << "                           1.3x3   2.4x4   3.5x5                                 \n";
                std::getline(std::cin, answer);
                
                if (!isvalid(answer, 2)) {
                    throw std::invalid_argument("you can only answer yes or no, let's try again\n");  
                } else {
                    validFormat = true;
                }
            } while (!validFormat); 

            std::getline(std::cin, expression);

        } catch (const std::exception& e) {
            std::cerr << "error: " << e.what() << std::endl;
        }

    } while (true);
    return 0;
}
