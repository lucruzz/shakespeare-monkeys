/*
** Filename: main.cpp
** Created on: September 13, 2024
** Author: Lucas Da Cruz Silva
 */
#include <iostream>
#include <random>
#include <vector>

std::string generate_string(std::string& str_typed, const int size) {
    std::random_device rd;
    for (int i = 0; i < size; i++) {
        std::uniform_int_distribution<> dist(0,27);
        const int random = dist(rd);
        (random < 26) ? str_typed += static_cast<char>('a' + random) : str_typed += ' ';
    }
    return str_typed;
}

std::pair<int, std::string> find_phrase(const std::string& target) {
    const int size = target.size();
    std::string str_typed;
    int attempts = 0;

    while (target != str_typed) {
        str_typed.clear();
        generate_string(str_typed, size);
        attempts++;
    }
    std::pair<int, std::string> result(attempts, str_typed);

    return result;
}

int main(){

    std::string target;
    std::cout << "Write a sentence: ";
    std::getline(std::cin, target);

    auto [fst, snd] = find_phrase(target);
    // this is the same "std::pair<int, std::string> res = find_phrase(target);"

    std::cout << "Target sentence: \"" << target << "\"" << std::endl;
    std::cout << "Number of attempts: " << fst << std::endl;
    std::cout << "Typed sentence: " << snd << std::endl;

    return 0;
}
