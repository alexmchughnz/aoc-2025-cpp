#include <assert.h>

#include <iostream>
#include <fstream>

#include "../helpers.hpp"

int part_one(std::ifstream input)
{
    int sum_joltage = 0;

    std::string line;
    while (input >> line)
    {
        std::cout << line << std::endl;

        size_t digit_1_index = 0;
        int digit_1 = 0;
        for (size_t i = 0; i < line.length() - 1; i++) // last digit cannot be digit_1
        {
            int digit = line[i] - '0';
            if (digit > digit_1)
            {
                digit_1 = digit;
                digit_1_index = i;
            }
        }

        int digit_2 = 0;
        for (size_t i = digit_1_index + 1; i < line.length(); i++)
        {
            int digit = line[i] - '0';
            if (digit > digit_2)
            {
                digit_2 = digit;
            }
        }

        int joltage = 10 * digit_1 + digit_2;
        std::cout << "Joltage = " << joltage << std::endl;
        sum_joltage += joltage;
    }

    return sum_joltage;
}

int part_two(std::ifstream input)
{
    (void)input;
    return 0;
}

int main()
{
    const int answer_one = part_one(std::ifstream(INPUT_FILE));
    std::cout << "\nPart One: " << answer_one << std::endl;

    const int answer_two = part_two(std::ifstream(INPUT_FILE));
    std::cout << "\nPart Two: " << answer_two << std::endl;

    return 0;
}