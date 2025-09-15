#include <iterator>
#include <memory>
#include <ranges>
#include <vector>


auto loop(std::ranges::view auto ints) -> void
{
    for (auto it = ints.begin(); it != ints.end(); ++it)
    {
        if (it != ints.begin())
        {
            (void) std::prev(it);
        }
    }
}

int main()
{
    std::vector<int> ints;
    ints.push_back(1);
    ints.push_back(2);

    loop(ints | std::views::transform([](auto i) { return i; }));
}
