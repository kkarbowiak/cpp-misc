#include <iterator>
#include <memory>
#include <ranges>
#include <vector>


class Foo
{
    public:
        Foo() = default;
        virtual ~Foo() = default;
};

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
    std::vector<std::unique_ptr<Foo>> foos;
    foos.push_back(std::make_unique<Foo>());
    foos.push_back(std::make_unique<Foo>());

    loop(foos | std::views::transform([](auto const & up) { return up.get(); }));
}
