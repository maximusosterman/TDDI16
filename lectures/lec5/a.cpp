#include <cstddef>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    unordered_set<string> dict {};
    vector<string> words {};
    string word {};

    while (cin >> word) {
            dict.insert(word);
            words.push_back(word);
        }

        sort(words.begin(), words.end());

    for (auto& word : words) {
        for (size_t i = 0; i < word.size(); i++) {
            string left = word.substr(0, i);
            string right = word.substr(i);
            if (dict.count(left) && dict.count(right)) {
                cout << word << "\n";
                break;
            }
        }
    }

    return 0;
}
