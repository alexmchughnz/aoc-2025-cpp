#pragma once

static constexpr char INPUT_FILE_PATH[] = "src/" DAY_NAME "/input.txt";

static constexpr char EXAMPLE_FILE_PATH[] = "src/" DAY_NAME "/example.txt";

#if EXAMPLE
    auto INPUT_FILE = EXAMPLE_FILE_PATH;
#else
    auto INPUT_FILE = INPUT_FILE_PATH;
#endif