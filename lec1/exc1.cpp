#include <iostream>
#include <string>

int main()
{
    char c {};
    std::string text {};
    bool open {false};

    while(std::cin.get(c))
    {
        if(c == '"')
        {
            if (!open)
            {
                text += "``";
            }
            else
            {
                text += "''";
            }
            open = !open;
        }
        else
        {
            text += c;
        }
    }
    std::cout << text;


    return 0;
}
