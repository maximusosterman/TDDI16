#include <map>
#include <string>
#include <vector>
#include <iostream>

std::pair<std::vector<std::string>, std::map<std::string, int>> get()
{

    std::map <std::string, int> hay_dict {};
    std::vector <std::string> descriptions {};

    int num_hp_words, num_descriptioms {};
    //Get params input
    do {
        std::cin >> num_hp_words >> num_descriptioms;
    } while (!(num_hp_words <= 1000) && !(num_descriptioms <= 100));

    // Get hp_dict input
    std::string hp_word {};
    int hp_dollars {};

    for (int i {}; i < num_hp_words; i++)
    {
        std::cin >> hp_word >> hp_dollars;
        hay_dict[hp_word] = hp_dollars;
    }

    // Get descriptions
    std::string desctiption {};

    for (int i {}; i < num_descriptioms; i++)
    {
        char c {};
        std::string buffer {};

        while (std::cin.get(c)) {
            if (c == '.') {
                break;
            }
            buffer.push_back(c);
        }
        descriptions.push_back(buffer);
    }

    return {descriptions, hay_dict};

}

int main()
{
    std::pair<
     std::vector <std::string>,
     std::map <std::string, int>
     > data {get()};

    auto [descriptions, hay_dict] = data;


    // std::cout << "\nHay Dict: " << std::endl;
    // for (auto x : hay_dict)
    // {
    //     std::cout << x.first << ": " << x.second << std::endl;
    // }


    // for (auto d : descriptions)
    // {
    //     std::cout << "\n" << d;
    // }

    // std::cout << "end" << std::endl;


    return 0;
}
