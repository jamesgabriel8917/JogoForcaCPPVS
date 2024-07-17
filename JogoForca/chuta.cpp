#include <iostream>
#include "chuta.hpp"
#include "letra_existe.hpp"

void chuta(std::map<char, bool>& chutou, std::array<char, 5>& chutes_errados, int& arraySize, std::string& palavra_secreta)
{
    std::cout << "Seu chute: ";
    char chute;
    std::cin >> chute;

    chutou[chute] = true;

    if(letra_existe(chute, palavra_secreta)) {
        std::cout << "Você acertou! Seu chute está na palavra." << std::endl;
    }
    else{
        std::cout << "Você errou! Seu chute não está na palavra." << std::endl;
        chutes_errados[arraySize] = chute;
        arraySize++;
    }
    std::cout << std::endl;
}