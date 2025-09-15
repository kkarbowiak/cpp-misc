#include <iterator>
#include <memory>
#include <ranges>
#include <vector>


class Base
{
    public:
        Base() = default;
        virtual ~Base() = default;
};

class Der final : public Base
{
    public:
        Der()
          : Base()
        {
        }
};

auto loop(std::ranges::view auto bases) -> void
{
    for (auto it = bases.begin(); it != bases.end(); ++it)
    {
        if (it != bases.begin())
        {
            (void) std::prev(it);
        }
    }
}

int main()
{
    std::vector<std::unique_ptr<Base>> ders;
    ders.push_back(std::make_unique<Der>());
    ders.push_back(std::make_unique<Der>());

    loop(foos | std::views::transform([](auto const & up) { return up.get(); }));
}
