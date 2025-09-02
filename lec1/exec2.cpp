#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

void handle_data(std::string const& line)
{
    std::istringstream iss(line);
    std::string s {}, t {};
    iss >> s >> t;
    bool result {true};

    auto it = t.begin();

    for (auto c : s)
    {
        it = std::find(it, t.end(), c);
        if (it == t.end())
        {
            result = false;
        }
    }

    if (result)
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
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

    std::cout << std::endl;

    for (auto& line : lines)
    {
        handle_data(line);
    }

    return 0;
}
