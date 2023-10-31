#include <iostream>
#include <string>
#include <iomanip>

#include "cracker.h"

using namespace std;

int main()
{
    int passwordCounter = 0;
    char passwordBuffer[9];
    cout << "Welcome to the Bruteforce Password Cracker by Gabrielius Gintalas!" << endl;
    cout << "Please enter up to 8 alphanumeric characters for your password: ";
    cin >> setw(9) >> passwordBuffer;

    string password = passwordBuffer;

    cout << "You entered: " << password << endl;
    cout << "The program will now attempt to crack your password!" << endl;
    PasswordGuesser guesser;
    string guess;
    while ((guess = guesser.getNextGuess()) != password)
    {
        cout << "\rTrying Password: " << guess << "   ";
        cout.flush(); // Instant password update
        passwordCounter++;
    }

    cout << "\rTrying Password: " << guess << "   ";
    cout.flush();

    cout << "\nYour password is: " << guess << " and was found after " << passwordCounter << " attempts!" << endl;
    cout << "Thank you for using my program!" << endl;

    return 0;
}