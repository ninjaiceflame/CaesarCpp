
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

    //Read each line of the file into a string
    while (getline(input_file, inputStringText))
    {
        //Convert string to c-string
        const char* charText = inputStringText.c_str();

        int length = strlen(charText);
        //Convert string tp uppercase and shift
        for (int i = 0; i < length; i++)
        {   
            //cout << toupper(charText[i]);
            string temp;
            temp += static_cast<char>(toupper( charText[i]) + (key % 26) );

            outputStringText = outputStringText + temp;
           
            /*  Char:   Decimal:
                A	    65
                B	    66
                C	    67
                D	    68
                E	    69
                F	    70
                G	    71
                H	    72
                I	    73
                J	    74
                K	    75
                L	    76
                M	    77
                N	    78
                O	    79
                P	    80
                Q	    81
                R	    82
                S	    83
                T	    84
                U	    85
                V	    86
                W	    87
                X	    88
                Y	    89
                Z	    90
            */          
        }
        
        //Prints encrypted test to console
        cout << endl << outputStringText << endl;

        //Output cipher text to encrypted file
        output_file << outputStringText << endl;
    }

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

    //Read each line of the file into a string
    while (getline(input_file, inputStringText))
    {
        //Convert string to c-string
        const char* charText = inputStringText.c_str();

        int length = strlen(charText);

        //Convert string tp uppercase and shift
        for (int i = 0; i < length; i++)
        {
            //cout << toupper(charText[i]);
            string temp;
            temp += static_cast<char>(toupper(charText[i]) - (key % 26));

            outputStringText = outputStringText + temp;

            /*  Char:   Decimal:
                A	    65
                B	    66
                C	    67
                D	    68
                E	    69
                F	    70
                G	    71
                H	    72
                I	    73
                J	    74
                K	    75
                L	    76
                M	    77
                N	    78
                O	    79
                P	    80
                Q	    81
                R	    82
                S	    83
                T	    84
                U	    85
                V	    86
                W	    87
                X	    88
                Y	    89
                Z	    90
            */
        }

        //Prints decrypted text to console
        cout << endl << outputStringText << endl;

        //Output cipher text to decrypted file
        output_file << outputStringText << endl;
    }

    //Close files
    input_file.close();
    output_file.close();

    return outputStringText;
}
