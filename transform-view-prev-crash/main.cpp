#include <memory>
#include <ranges>
#include <string>
#include <vector>


class Fmt
{
    public:
        virtual auto get_name() const -> std::string const & = 0;
    
    protected:
        virtual ~Fmt() = default;
};

class Base : public Fmt
{
    public:
        explicit Base(std::string name)
          : m_name(std::move(name))
        {
        }
        virtual ~Base() = default;

        auto get_name() const -> std::string const & override
        {
            return m_name;
        }

    private:
        std::string m_name;
};

class Der final : public Base
{
    public:
        explicit Der(std::string name)
          : Base(std::move(name))
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
    ders.push_back(std::make_unique<Der>("1"));
    ders.push_back(std::make_unique<Der>("2"));

    print_names(ders | std::views::transform([](auto const & ca) { return static_cast<Fmt const *>(ca.get()); }));
}
