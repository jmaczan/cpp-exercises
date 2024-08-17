#include <string>
#include <iostream>
#include <cstdint>

std::string alphabet_position(const std::string &text)
{
    if (text.length() == 0)
    {
        return "";
    }

    std::string result;
    result.reserve(text.size() * 2);

    auto uint8_to_chars = [](uint8_t value, char *buffer)
    {
        if (value > 96 && value < 123)
        {
            value = value - 96;
            if (value < 10)
            {
                buffer[0] = '0' + value;
                return 1;
            }

            if (value < 100)
            {
                buffer[0] = '0' + value / 10;
                buffer[1] = '0' + value % 10;
                return 2;
            }
        }

        if (value > 64 && value < 91)
        {
            value = value - 64;

            if (value < 10)
            {
                buffer[0] = '0' + value;
                return 1;
            }

            if (value < 100)
            {
                buffer[0] = '0' + value / 10;
                buffer[1] = '0' + value % 10;
                return 2;
            }
        }

        return 0;
    };

    char buffer[3];
    for (char c : text)
    {
        uint8_t length = uint8_to_chars(c, buffer);

        if (length > 0)
        {
            result.append(buffer, length);
            result.push_back(' ');
        }
    }

    if (result != "")
    {
        result.pop_back(); // remove the last whitespace
    }

    return result;
}

int main()
{
    std::cout << alphabet_position("The sunset sets at twelve o' clock.");
}