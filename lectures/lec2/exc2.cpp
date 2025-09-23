#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{


    unsigned int N {};

    while (N <= 0 || N > 13)
    {
        cin >> N;
    }
    cin.ignore();

    vector<unsigned int> spaces_per_line {};
    char ch;

    for (unsigned int i {}; i < N; i++)
    {
        unsigned int spaces {};
        while (std::cin.get(ch))
        {
            if (ch == '\n')
                break;
            if (ch == ' ' || ch == 'B')
                spaces += 1;
        }
        spaces_per_line.push_back(spaces);
    }

    unsigned int result {};
    auto least_spaces = *min_element(spaces_per_line.begin(), spaces_per_line.end());

    for (auto line : spaces_per_line)
    {
        result += line - least_spaces;
    }

    cout << result << endl;
    return 0;
}
