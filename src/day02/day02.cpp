#include <assert.h>

#include <iostream>
#include <fstream>

#include "../helpers.hpp"

int part_one(std::ifstream input)
{
    (void)input;
    return 0;
}

int part_two(std::ifstream input)
{
    (void)input;
    return 0;
}

int main()
{
    const int answer_one = part_one(std::ifstream(INPUT_FILE));
    const int answer_two = part_two(std::ifstream(INPUT_FILE));

    std::cout << "\nPart One: " <<  answer_one << std::endl;
    std::cout << "\nPart Two: " <<  answer_two << std::endl;
    return 0;
}