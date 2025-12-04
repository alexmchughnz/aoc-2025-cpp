#include <assert.h>

#include <iostream>
#include <fstream>

#include "../helpers.hpp"

long part_one(std::ifstream input)
{
    long sum_joltage = 0;

    std::string line;
    while (input >> line)
    {
        std::cout << line << std::endl;

        size_t digit_1_index = 0;
        long digit_1 = 0;
        for (size_t i = 0; i < line.length() - 1; i++) // last digit cannot be digit_1
        {
            long digit = line[i] - '0';
            if (digit > digit_1)
            {
                digit_1 = digit;
                digit_1_index = i;
            }
        }

        long digit_2 = 0;
        for (size_t i = digit_1_index + 1; i < line.length(); i++)
        {
            long digit = line[i] - '0';
            if (digit > digit_2)
            {
                digit_2 = digit;
            }
        }

        long joltage = 10 * digit_1 + digit_2;
        std::cout << "Joltage = " << joltage << std::endl;
        sum_joltage += joltage;
    }

    return sum_joltage;
}

long part_two(std::ifstream input)
{
    constexpr size_t NUM_DIGITS = 12;

    long sum_joltage = 0;

    std::string line;
    while (input >> line)
    {
        std::cout << line << std::endl;
        long joltage = 0;

        size_t digit_d_index = 0;
        for (size_t d = 0; d < NUM_DIGITS; d++)
        {
            long digit_d = 0;

            const int digits_remaining = NUM_DIGITS - d;
            for (size_t i = digit_d_index; i <= line.length() - digits_remaining; i++)
            {
                long digit = line[i] - '0';
                if (digit > digit_d)
                {
                    digit_d = digit;
                    digit_d_index = i;
                }
            }

            joltage = 10 * joltage + digit_d;
            digit_d_index += 1;
        }

        std::cout << "Joltage = " << joltage << std::endl;
        sum_joltage += joltage;
    }

    return sum_joltage;
}

int main()
{
    const long answer_one = part_one(std::ifstream(INPUT_FILE));
    const long answer_two = part_two(std::ifstream(INPUT_FILE));

    std::cout << "\nPart One: " << answer_one << std::endl;
    std::cout << "\nPart Two: " << answer_two << std::endl;

    return 0;
}