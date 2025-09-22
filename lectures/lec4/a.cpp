#include <vector>
#include <iostream>

std::vector<unsigned int> get()
{
    int N {};
    unsigned int input {};
    std::vector<unsigned int> result {};

    do
    {
        std::cin >> N;
        if (N == 0)
        {
            return {};
        }
    }
    while (!(N <= 5000 && N >= 2));

    for (int i {}; i < N; i++)
    {
        std::cin >> input;
        result.push_back(input);
    }

    return result;
}

unsigned int calc_cost(std::vector<unsigned int>& nums, unsigned int cost)
{
    if (nums.empty()) return cost;
    if (nums.size() == 1) return  cost + nums[0];

    unsigned int new_cost {};

    if (cost == 0)
    {
        new_cost = nums[0] + nums[1];
        nums.erase(nums.begin(), nums.begin() + 2);
    }
    else
    {
        new_cost = cost + nums[0];
        nums.erase(nums.begin());
    }

    return  new_cost + calc_cost(nums, new_cost);
}

int main()
{
    std::vector<unsigned int> results {};
    std::vector<unsigned int> nums {};

    while (true)
    {
        nums = get();
        if (nums.empty())
            break;
        results.push_back(calc_cost(nums, 0));
    }

    for (auto r : results)
    {
        std::cout << r << std::endl;
    }

    return 0;
}
