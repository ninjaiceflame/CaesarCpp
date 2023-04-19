#include <iostream>
#include <string>
#include <fstream>  
#include <unordered_map>
#include <cctype>

#define E_POSITION 4
#define A_POSITION 0
#define Z_POSITION 25

using std::cout;
using std::cin;
using std::endl;
using std::fstream;

int main(int argc, char** argv)
{
    fstream input_file;
    char read_character;
    std::unordered_map<char, int> char_frequency;

    if (argc < 2)
    {
        cout << "Usage: Cryptanalysis.exe <filepath>" << endl;
        return 1;
    }

    input_file.open(argv[1], std::fstream::in);

    do
    {
        input_file >> read_character;

        read_character = toupper(read_character);

        if (char_frequency.find((char)read_character) == char_frequency.end())
        {
            char_frequency.emplace((char)read_character, 1);
        }
        else
        {
            char_frequency.at((char)read_character)++;
        }

    } while (input_file.peek() != EOF);

    int temp_max = 0;
    int final_index = 0;

    //97 - 122
    for (int i = 65; i < 91; i++)
    {
        
        try {
            if (char_frequency.at((char)i) > temp_max)
            {
                temp_max = char_frequency.at((char)i);
                final_index = i;
            }

        }
        catch (...)
        {
            continue;
        }
    }

    for (int i = 65; i < 91; i++)
    {

        try {
            cout << (char)i << ": " << char_frequency.at((char)i) << endl;
        }
        catch (...)
        {
            continue;
        }
    }

    cout << "Highest Freq. Ascii: " << final_index << endl;

    final_index = (final_index - 65);

    if (final_index < E_POSITION)
    {
        final_index = (Z_POSITION - E_POSITION) + final_index + 1;
    }
    else
    {
        final_index = final_index - E_POSITION;
    }

    cout << "Key equals: " << final_index << endl;

    return 0;
}