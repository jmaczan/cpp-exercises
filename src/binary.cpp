#include <cstring>
#include <string>
#include <iostream>

namespace coding
{
    const char *const lookup_table[10] = {
        "10",
        "11",
        "0110",
        "0111",
        "001100",
        "001101",
        "001110",
        "001111",
        "00011000",
        "00011001"};

    const char *const lookup_table_decode[10] = {
        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9"};

    std::string code(const std::string &strng)
    {
        std::string result;
        result.reserve(strng.length() * 8); // 8 is max number of digits from lookup_table for a single character

        for (auto c : strng)
        {
            if (c >= '0' && c <= '9')
            {
                result.append(lookup_table[c - '0']);
            }
            else
            {
                std::cout << "Trying to write invalid character: " << c << std::endl;
            }
        }

        return result;
    }

    std::string decode(const std::string &str)
    {
        std::string result;
        result.reserve(str.length() / 2);

        std::string_view string_view = std::string_view(str);

        for (int i = 0; i < static_cast<int>(str.length());)
        {
            for (int j = 0; j < 10; j++)
            {
                if (string_view.substr(i, strlen(lookup_table[j])) == lookup_table[j])
                {
                    result.append(lookup_table_decode[j]);
                    i += strlen(lookup_table[j]);
                    break;
                }
            }
        }
        return result;
    }
}

int main()
{
    std::cout << coding::code("77338855") << std::endl;   //--> "001111001111011101110001100000011000001101001101"
    std::cout << coding::code("77338") << std::endl;      //--> "0011110011110111011100011000"
    std::cout << coding::code("0011121314") << std::endl; //--> "1010111111011011011111001100"

    std::cout << coding::decode("001111001111011101110001100000011000001101001101") << std::endl; // -> "77338855"
    std::cout << coding::decode("0011110011110111011100011000") << std::endl;                     // -> "77338"
    std::cout << coding::decode("1010111111011011011111001100") << std::endl;                     // -> "0011121314"
}
