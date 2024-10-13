/*
** Filename: main.cpp
** Created on: September 13, 2024
** Author: Lucas Da Cruz Silva
 */
#include <iostream>
#include <random>

std::string generate_string(std::string& str_typed, const int size) {
    std::random_device rd;
    for (int i = 0; i < size; i++) {
        std::uniform_int_distribution<> dist(0,27);
        const int random = dist(rd);
        (random < 26) ? str_typed += static_cast<char>('a' + random) : str_typed += ' ';
    }
    return str_typed;
}

std::string find_phrase() {

}

int main(){
    const std::string target = "louco";
    const int size = target.size();
    std::string str_typed;
    int attempts = 0;

    while (target != str_typed) {
        str_typed.clear();
        generate_string(str_typed, size);
        attempts++;
    }

    std::cout << "Frase alvo: \"" << target << "\"" << std::endl;
    std::cout << "Número de tentativas: " << attempts << std::endl;
    std::cout << "Frase digitada: " << str_typed << std::endl;

    return 0;
}
