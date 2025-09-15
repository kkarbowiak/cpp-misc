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
    std::vector<std::unique_ptr<std::string>> foos;
    foos.push_back(std::make_unique<std::string>());
    foos.push_back(std::make_unique<std::string>());

    loop(foos | std::views::transform([](auto const & up) { return up.get(); }));
}
