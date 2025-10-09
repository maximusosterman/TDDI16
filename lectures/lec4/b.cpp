#include <iostream>
#include <forward_list>

using namespace std;

int main() {

  unsigned int test_cases{}, movies_in_stack{}, locate_reqs{};
  forward_list<int> movie_stack {};

  while (test_cases < 1 or test_cases > 100)
      cin >> test_cases;

  cin >> movies_in_stack >> locate_reqs;

  for (unsigned int i {movies_in_stack}; i > 0; i--)
      movie_stack.push_front(i);




  return 0;

}
