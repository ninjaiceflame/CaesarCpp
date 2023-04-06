// CaesarCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <ostream>


using std::cout;
using std::cin;
using std::endl;

int main()
{
    char* input = NULL;
    do
    {
        system("CLS");
        cout << "Hello, welcome to the Caeser Shift Cipher Program!" << endl;
        cout << "Do you want to Encrypt [E] or Decrypt [D] or exit [X]" << endl;

        cin >> input;

        if (input == "E" || input == "e")
        {
            //Encrypt
            system("CLS");
        }
        else if (input == "D" || input == "d")
        {
            //Decrypt
            system("CLS");
        }
        else
        {
            //Try again
            system("CLS");
            cout << "Invalid input, try again: ";
        }
    } while (input != "X" || input != "x");

    return 0;
}
