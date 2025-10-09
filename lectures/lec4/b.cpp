#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  unsigned int test_cases{};
  vector<vector<int>> result {};

  while (test_cases < 1 or test_cases > 100)
      cin >> test_cases;

  for (unsigned int i {}; i < test_cases; i++) {

    vector<int> movie_stack{}, pos{};
    unsigned int movies_in_stack{}, reqs{};

    cin >> movies_in_stack >> reqs;

    for (unsigned int i {}; i < movies_in_stack; i++) {
        movie_stack.push_back(i+1);
        pos.push_back(i);
    }

    vector<int> curr_result {};

    for (unsigned int i {}; i < reqs; i++) {
        unsigned int movie_to_move {};

        cin >> movie_to_move;

        auto it  = std::find(movie_stack.begin(), movie_stack.end(), movie_to_move);
        int index_of_movie = it - movie_stack.begin();

        curr_result.push_back(pos[index_of_movie]);

        movie_stack.erase(it);
        movie_stack.insert(movie_stack.begin(), movie_to_move);
    }
    result.push_back(curr_result);
  }

  for (auto r : result) {
      for (auto num : r)
        cout << num << " ";

    cout << endl;
  }


  return 0;
}
