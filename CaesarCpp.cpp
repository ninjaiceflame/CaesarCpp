
#include <iostream>
#include <string>
#include <fstream>  //Read and write files

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;

string help_message = "Do you want to Encrypt [E] or Decrypt [D] or exit [X]";

string encryptFile(fstream file, int key);
string decryptFile(fstream file, int key);

int main()
{
    //File to read and write to:
    fstream plainText;
    fstream cipherText;

    //Char to read for menu selection
    char input;

    system("CLS");
    cout << "Hello, welcome to the Caeser Shift Cipher Program!" << endl;

    do
    {
        cout << help_message << endl;
        cin >> input;

        if (input == 'E' || input == 'e')
        {
            //Encrypt
            system("CLS");
            cout << "Encrypt Selected!" << endl;

            //Read file from input and create handle

            //encryptFile(file_handle, key);

        }
        else if (input == 'D' || input == 'd')
        {
            //Decrypt
            system("CLS");
            cout << "Decrypt Selected!" << endl;

            //Read file from input and create handle

            //decryptFile(file_handle, key);
        }
        else
        {
            //Try again
            system("CLS");
            cout << "Bad input, try again!" << endl;
        }
    } while (input != 'X' || input != 'x');

    return 0;
}

string encryptFile(fstream file, int key)
{
    string str = "Dummy String";
    return str;
}

string decryptFile(fstream file, int key)
{
    string str = "Dummy String";
    return str;
}
