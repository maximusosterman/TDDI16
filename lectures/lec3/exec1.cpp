    #include <map>
    #include <string>
    #include <vector>
    #include <iostream>

    std::pair<std::vector<std::vector<std::string>>, std::map<std::string, int>> get()
    {

        std::map <std::string, int> hay_dict {};
        std::vector <std::vector <std::string>> descriptions {};

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
        std::vector<std::string> description {};
        std::string word {};

        for (int i {}; i < num_descriptioms; i++)
        {
            char c {};

            while (std::cin.get(c)) {
                if (c == '.') {
                    descriptions.push_back(description);
                    description.clear();
                    break;
                }
                else if (c == ' ' or c == '\n')
                {
                    description.push_back(word);
                    word = "";
                }
                else
                {
                    word.push_back(c);
                }
            }
        }
        return {descriptions, hay_dict};
    }

    int main()
    {
        std::pair<
        std::vector<std::vector <std::string>>,
        std::map <std::string, int>
        > data {get()};

        auto [descriptions, hay_dict] = data;
        int points {};

        for (auto desc : descriptions)
        {
            points = 0;
            for (auto word : desc)
            {
                auto it = hay_dict.find(word);
                if (it != hay_dict.end()) {
                    points += it->second;
                }
            }
            std::cout << points << std::endl;
        }

        return 0;
    }
