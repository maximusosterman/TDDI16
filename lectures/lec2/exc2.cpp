#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int find_spaces(unsigned int N)
{
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

    return result;
}

int main()
{
    vector<unsigned int> results;
    unsigned int N {};

    while (cin >> N && N != 0)
    {
        cin.ignore();
        results.push_back(find_spaces(N));
    }

    for (auto reuslt : results)
    {
        cout << reuslt << endl;
    }

    return 0;
}
