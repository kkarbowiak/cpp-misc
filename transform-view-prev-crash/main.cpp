#include <iterator>
#include <memory>
#include <ranges>
#include <vector>


auto loop(std::ranges::view auto foos) -> void
{
    for (auto it = foos.begin(); it != foos.end(); ++it)
    {
        if (it != foos.begin())
        {
            (void) std::prev(it);
        }
    }
}

int main()
{
    std::vector<int> foos;
    foos.push_back(1);
    foos.push_back(2);

    loop(foos | std::views::transform([](auto i) { return i; }));
}
