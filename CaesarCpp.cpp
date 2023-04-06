
#include <iostream>
#include <string>
#include <fstream>  //Read and write files

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;

string encryptFile(fstream file, int key);
string decryptFile(fstream file, int key);

int main()
{
    //File to read and write to:
    fstream plainText;
    fstream cipherText;
    //Char to read for menu selection
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

string encryptFile(fstream file, int key)
{
    
}

string decryptFile(fstream file, int key)
{

}
