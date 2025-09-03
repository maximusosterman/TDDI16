#include <string>
#include <iostream>

void handle_data(std::string& data)
{
    int result {};

    while(data.size() > 1 && data.size() != 0)
    {
        result = 0;
        for (auto& num : data)
        {
            int to_int = num - '0';
            result += to_int;
        }
        data = std::to_string(result);
    }
    if (result != 0)
    {
        std::cout << std::to_string(result) << std::endl;
    }
}

int main()
{
    std::vector<std::string> lines {};
    std::string line {};
    while(std::getline(std::cin, line))
    {
        lines.push_back(line);
    }

    for (auto& line : lines)
    {
        handle_data(line);
    }

    return 0;
}
