/*
** Filename: main.cpp
** Created on: September 13, 2024
** Author: Lucas Da Cruz Silva
 */
#include <iostream>
#include <random>

int main()
{
    std::random_device rd;
    const std::string target = "que loucura";
    const int size = target.size();
    std::string str_typed;
    int attempts = 0;

    while (target != str_typed) {
        str_typed.clear();

        for (int i = 0; i < size; i++) {
            std::uniform_int_distribution<> dist(0,27);
            const int random = dist(rd);

            (random < 26) ? str_typed += static_cast<char>('a' + random) : str_typed += ' ';
            // if ( random < 26 ) {
            //     std::cout << random << " is " << static_cast<char>('a' + random) << std::endl;
            // }else{
            //     std::cout << random << " is \' \'" << std::endl;
            // }
        }
        attempts++;
    }

    std::cout << "Frase alvo: \"" << target << "\"" << std::endl;
    std::cout << "Número de tentativas: " << attempts << std::endl;
    std::cout << "Frase digitada: " << str_typed << std::endl;

    return 0;
}
