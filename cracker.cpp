#include <iostream>
#include <iomanip>
#include <string>

#include "cracker.h"

using namespace std;

PasswordGuesser::PasswordGuesser()
    : allChar("abcdefghijklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZ0123456789~`!@#$%^&*()-_=+[]{};:<,>.?|/"),
      currentGuess("")
{
}

std::string PasswordGuesser::getNextGuess()
{
    if (currentGuess.empty())
    {
        currentGuess = allChar[0];
        return currentGuess;
    }

    int allCharSize = allChar.size() - 1;
    for (int i = currentGuess.size() - 1; i >= 0; --i)
    {
        size_t pos = allChar.find(currentGuess[i]);

        // Current character is not the last character
        if (pos != std::string::npos && pos < allCharSize)
        {
            currentGuess[i] = allChar[pos + 1];
            return currentGuess;
        }
        // Increase string size if we have reached the end of all characters
        else if (i == 0)
        {
            if (currentGuess.size() >= maxPasswordSize)
            {
                return "";
            }

            // If current character is the last in the charset and is the first character in the guess
            currentGuess = std::string(currentGuess.size() + 1, allChar[0]);
            return currentGuess;
        }
        else
        { // Reset this position and check the one before
            currentGuess[i] = allChar[0];
        }
    }
    return "";
}
