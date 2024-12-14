#include "game.h"
#include <iostream>
#include <string>

//если у тебя в хедер файле есть инклуды , то они тут не нужны, т.к ты и так ссылаешься к своему хедер файлу, так что удали когда зайдешь)



int main(){
    std::string expression;
    do {
        std::getline(std::cin, expression);

    }while(expression == "coontinue");

    return 0;
}