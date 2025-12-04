#include <assert.h>

#include <iostream>
#include <fstream>

#include "../helpers.hpp"

long part_one(std::ifstream input)
{
    (void)input;
    return 0;
}

long part_two(std::ifstream input)
{
    (void)input;
    return 0;
}

int main()
{
    const long answer_one = part_one(std::ifstream(INPUT_FILE));
    const long answer_two = part_two(std::ifstream(INPUT_FILE));

    std::cout << "\nPart One: " << answer_one << std::endl;
    std::cout << "\nPart Two: " << answer_two << std::endl;

    return 0;
}