/*
** Filename: Monkey.h
** Created on: September 13, 2024
** Author: Lucas Da Cruz Silva
 */

#ifndef MONKEY_H
#define MONKEY_H

#define ALPHABET        "abcdefghijklmnopqrstuvwxyz "
#define ALPHABET_SIZE   27

#include <string>

class Monkey {

private:
    std::string target;
    std::string alphabet;

public:
    Monkey();

    std::string generate_string();
    std::string find_phrase();
};

#endif //MONKEY_H