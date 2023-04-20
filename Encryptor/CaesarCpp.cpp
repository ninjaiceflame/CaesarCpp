
#include <iostream>
#include <string>
#include <fstream>  //Read and write files
#include <chrono>   //For sleep
#include <thread>   //For sleep

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;

string help_message = "Do you want to Encrypt [E] or Decrypt [D] or exit [X]";

string encryptFile(fstream& input_file, fstream& output_file, int key);
string decryptFile(fstream& input_file, fstream& output_file, int key);

void encryptProcessInput();
void decryptProcessInput();

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
            encryptProcessInput();
        }
        else if (input == 'D' || input == 'd')
        {
            decryptProcessInput();
        }
        else
        {
            //Try again
            system("CLS");
        }
    } while (toupper(input) != 'X');

    return 0;
}

void encryptProcessInput()
{
    string input_file_path;
    string output_file_path;
    string key;

    fstream input_file;
    fstream output_file;
    bool valid_path_entered = false;


    //Get input for file to process and open it
    do
    {
        //Encrypt
        system("CLS");
        cout << "Enter file to encrypt, or 'x' to exit: ";

        //Read file from input and create handle
        cin >> input_file_path;

        //Exit if 'x' is entered
        if ((input_file_path[0] == 'x' || input_file_path[0] == 'X') && input_file_path.length() == 1)
        {
            return;
        }

        //Open the file
        input_file.open(input_file_path, std::fstream::in);
        if (input_file)
        {
            valid_path_entered = true;
        }
        else
        {
            cout << "File not found, Please try again:" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        output_file_path = input_file_path + ".encrypted";

    } while (valid_path_entered == false);

    cout << "Enter Key: ";
    cin >> key;

    //Open output file based on name from input file
    output_file.open(output_file_path, std::fstream::out | std::fstream::trunc);
    if (!output_file)
    {
        cout << "Could not create output file. Aborting." << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        input_file.close();
        return;
    }

    cout << "Output file name: " << output_file_path << endl;
    cout << "Encrypting..." << endl;

    encryptFile(input_file, output_file, atoi(key.c_str()));
}

void decryptProcessInput()
{
    string input_file_path;
    string output_file_path;
    string key;

    fstream input_file;
    fstream output_file;
    bool valid_path_entered = false;

    //Get input for file to process and open it
    do
    {
        //decrypt
        system("CLS");
        cout << "Enter file to decrypt, or 'x' to exit: ";

        //Read file from input and create handle
        cin >> input_file_path;

        if ((input_file_path[0] == 'x' || input_file_path[0] == 'X') && input_file_path.length() == 1)
        {
            return;
        }

        //Open the file
        input_file.open(input_file_path, std::fstream::in);
        if (input_file)
        {
            valid_path_entered = true;
        }

    } while (valid_path_entered == false);

    cout << "Enter Key: ";
    cin >> key;

    //Open output file. Remove ".encrypted" suffix if present.
    output_file_path = input_file_path;
    size_t index = output_file_path.find(".encrypted");
    if (index != string::npos)
    {
        output_file_path.resize(index);
    }
    else
    {
        output_file_path = "decrypted_" + input_file_path;
    }

    //Open the file
    output_file.open(output_file_path, std::fstream::out | std::fstream::trunc);
    if (!output_file)
    {
        cout << "Could not create output file. Aborting." << endl;
        input_file.close();
        return;
    }

    cout << "Output file name: " << output_file_path << endl;
    cout << "Decrypting..." << endl;

    decryptFile(input_file, output_file, atoi(key.c_str()));
}

string encryptFile(fstream& input_file, fstream& output_file, int key)
{
    //Perform encryption and save to output file
    string inputStringText;
    string outputStringText;

    char read_character;

    do
    {
        input_file >> read_character;
        output_file << (char)((((toupper(read_character) - 65) + key) % 26) + 65);
    } while (input_file.peek() != EOF);
    
    //Close files
    input_file.close();
    output_file.close();

    return outputStringText;
}

string decryptFile(fstream& input_file, fstream& output_file, int key)
{
    //Perform decryption and save to output file
    string inputStringText;
    string outputStringText;

    char read_character;

    do
    {
        input_file >> read_character;
        output_file << (char)((((read_character - 65) - key + 26) % 26) + 65);
    } while (input_file.peek() != EOF);

    //Close files
    input_file.close();
    output_file.close();

    return outputStringText;
}
