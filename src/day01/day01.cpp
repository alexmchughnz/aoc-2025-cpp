#include <assert.h>

#include <iostream>
#include <fstream>

#include "../helpers.hpp"

constexpr auto file = INPUT_FILE_PATH;

constexpr int INITIAL_NUMBER = 50;
constexpr int MAXIMUM_NUMBER = 99;

int part_one(std::ifstream input)
{
    int num_zeroes = 0;
    int number = INITIAL_NUMBER;

    std::string line;
    while (input >> line)
    {
        const char direction = line[0];
        const int rotation = std::stoi(line.substr(1));

        switch (direction)
        {
        case 'L':
            number -= rotation;
            break;
        case 'R':
            number += rotation;
            break;
        default:
            assert(false);
        }

        while (number < 0)
        {
            number += MAXIMUM_NUMBER + 1;
        }
        while (number > MAXIMUM_NUMBER)
        {
            number -= MAXIMUM_NUMBER + 1;
        }

        if (number == 0)
        {
            num_zeroes++;
        }
    }

    return num_zeroes;
}

int part_two(std::ifstream input)
{
    (void)input;
    return 0;
}

int main()
{
    std::cout << "Part One: " << part_one(std::ifstream(file)) << std::endl;
    std::cout << "Part Two: " << part_two(std::ifstream(file)) << std::endl;
    return 0;
}