#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

std::unordered_map<char, std::vector<char>> adjacents = {
    {'1', {'1', '2', '4'}},
    {'2', {'2', '1', '3', '5'}},
    {'3', {'3', '2', '6'}},
    {'4', {'4', '1', '5', '7'}},
    {'5', {'5', '2', '4', '6', '8'}},
    {'6', {'6', '3', '5', '9'}},
    {'7', {'7', '4', '8'}},
    {'8', {'8', '5', '7', '9', '0'}},
    {'9', {'9', '6', '8'}},
    {'0', {'0', '8'}}};

std::vector<std::string> get_pins(std::string observed)
{
  std::vector<int> pins(10000);
  for (int a = 0; a < observed.length(); a++)
  {
    std::vector<char> first_character_adjacents = adjacents[observed[a]];
    do
    {
      std::vector<char> second_character_adjacents = adjacents[observed[first_character_adjacents]];
    } while (std::next_permutation(first_character_adjacents.begin(), first_character_adjacents.end()));
    // for (const auto &character : character_adjacents)
    // {
    //   std::cout << character << ' ';
    // }
  }
  return {observed};
}