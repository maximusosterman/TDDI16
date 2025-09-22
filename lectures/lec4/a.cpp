#include <queue>
#include <vector>
#include <iostream>

using MinHeap = std::priority_queue<
    unsigned long long,
    std::vector<unsigned long long>,
    std::greater<unsigned long long>
>;

MinHeap get()
{
    int N {};
    unsigned int input {};
    MinHeap result {};

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
        result.push(input);
    }

    return result;
}

unsigned long long calc_cost(MinHeap& nums)
{
    unsigned long long total {};
    while (nums.size() > 1)
    {
        auto a = nums.top(); nums.pop();
        auto b = nums.top(); nums.pop();
        auto s = a + b;
        total += s;
        nums.push(s);
    }

    return total;
}

int main()
{
    std::vector<unsigned long long> results {};

    while (true)
    {
        MinHeap nums {get()};
        if (nums.empty())
            break;

        results.push_back(calc_cost(nums));
    }

    for (auto r : results)
    {
        std::cout << r << std::endl;
    }

    return 0;
}
