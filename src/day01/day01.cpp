#include <assert.h>

#include <iostream>
#include <fstream>

#include "../helpers.hpp"

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
    int num_clicks = 0;
    int number = INITIAL_NUMBER;

    std::string line;
    while (input >> line)
    {
        const char direction = line[0];
        const int rotation = std::stoi(line.substr(1));

        int sign = 0;
        switch (direction)
        {
        case 'L':
            sign = -1;
            break;
        case 'R':
            sign = +1;
            break;
        default:
            assert(false);
        }

        for (int i = 0; i < rotation; i++)
        {
            number += 1 * sign;

            if (number < 0)
            {
                number = MAXIMUM_NUMBER;
            }
            else if (number > MAXIMUM_NUMBER)
            {
                number = 0;
            }

            if (number == 0)
            {
                num_clicks++;
            }
        }
    }

    return num_clicks;
}

int main()
{
    std::cout << "Part One: " << part_one(std::ifstream(INPUT_FILE)) << std::endl;
    std::cout << "Part Two: " << part_two(std::ifstream(INPUT_FILE)) << std::endl;
    return 0;
}