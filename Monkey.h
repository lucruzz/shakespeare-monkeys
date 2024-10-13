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

    std::string generateRandomPhrase();

public:
    Monkey();
};

#endif //MONKEY_H