#include <assert.h>

#include <iostream>
#include <fstream>

#include "../helpers.hpp"

bool is_invalid(const std::string &str)
{
    if (str.length() % 2 != 0)
    {
        return false;
    }

    size_t half_len = str.length() / 2;
    auto s1 = str.substr(0, half_len);
    auto s2 = str.substr(half_len, half_len);

    // std::cout << s1 << "|" << s2 << std::endl;

    return (s1 == s2);
}

bool is_invalid_repeating(const std::string &str)
{
    bool is_repeating = false;

    for (size_t len = 1; len <= str.length() / 2; len++)
    {
        is_repeating = true; // Start by assuming string repeats
        size_t pos = len;    // Start at second substring of length `len`

        while (pos + len <= str.length())
        {
            auto s1 = str.substr(pos - len, len);
            auto s2 = str.substr(pos, len);

            // std::cout << "@[" << pos - len << "]: " << s1 << "|" << s2 << std::endl;
            if (s1 != s2)
            {
                is_repeating = false;
                break;
            }

            pos += len;
        }

        // String can't be repeating if there's <len characters dangling at end.
        if (pos != str.length())
        {
            is_repeating = false;
        }

        // If assumption string repeats was correct, we're done!
        if (is_repeating)
        {
            break;
        }
    }

    return is_repeating;
}

long part_one(std::ifstream input)
{
    long sum = 0;

    std::string line;
    while (std::getline(input, line, ','))
    {
        size_t dash_index = line.find('-');
        long first_id = std::stol(line.substr(0, dash_index));
        long last_id = std::stol(line.substr(dash_index + 1));

        std::cout << "Searching range " << first_id << " to " << last_id << std::endl;
        for (long id = first_id; id <= last_id; id++)
        {
            std::string id_str = std::to_string(id);
            if (is_invalid(id_str))
            {
                std::cout << "Invalid id! " << id << std::endl;
                sum += id;
            }
        }
    }

    return sum;
}

long part_two(std::ifstream input)
{
    long sum = 0;

    std::string line;
    while (std::getline(input, line, ','))
    {
        size_t dash_index = line.find('-');
        long first_id = std::stol(line.substr(0, dash_index));
        long last_id = std::stol(line.substr(dash_index + 1));

        std::cout << "Searching range " << first_id << " to " << last_id << std::endl;
        for (long id = first_id; id <= last_id; id++)
        {
            std::string id_str = std::to_string(id);
            if (is_invalid_repeating(id_str))
            {
                std::cout << "Invalid id! " << id << std::endl;
                sum += id;
            }
        }
    }

    return sum;
}

int main()
{
    const long answer_one = part_one(std::ifstream(INPUT_FILE));
    const long answer_two = part_two(std::ifstream(INPUT_FILE));

    std::cout << "\nPart One: " << answer_one << std::endl;
    std::cout << "\nPart Two: " << answer_two << std::endl;
    return 0;
}