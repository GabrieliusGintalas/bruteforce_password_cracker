#pragma once
#include <string>

class PasswordGuesser
{
public:
    PasswordGuesser();
    std::string getNextGuess();

private:
    const std::string allChar;
    std::string currentGuess;
    int maxPasswordSize = 8;
};