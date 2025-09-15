#include <iostream>
#include <memory>
#include <ranges>
#include <vector>


class Base
{
    public:
        virtual ~Base() = default;
        virtual auto say() const -> void = 0;
};

class Derived : public Base
{
    public:
        auto say() const -> void override
        {
            std::cout << "Hi!\n";
        }
};

auto say_all(std::ranges::view auto bases) -> void
{
    for (auto const & base : bases)
    {
        base->say();
    }
}

int main()
{
    std::vector<std::shared_ptr<Derived>> bases;
    bases.push_back(std::make_shared<Derived>());
    bases.push_back(std::make_shared<Derived>());

    say_all(bases | std::views::transform([](auto const & up) { return static_cast<Base *>(up.get()); }));
}
