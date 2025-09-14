#include <memory>
#include <ranges>
#include <string>
#include <vector>


class Fmt
{
    protected:
        virtual ~Fmt() = default;
};

class Base : public Fmt
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

auto print_names(std::ranges::view auto ders) -> void
{
    for (auto it = ders.begin(); it != ders.end(); ++it)
    {
        if (it != ders.begin())
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

    print_names(ders | std::views::transform([](auto const & ca) { return static_cast<Fmt const *>(ca.get()); }));
}
