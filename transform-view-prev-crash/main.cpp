#include <iostream>
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

struct Options
{
    std::string name;
};

class OptionsHolder
{
    protected:
        explicit OptionsHolder(Options options)
          : m_options(std::move(options))
        {
        }

        auto get_name() const -> std::string const &
        {
            return m_options.name;
        }

    private:
        Options m_options;
};

class Base : public Fmt, public OptionsHolder
{
    public:
        explicit Base(Options options)
          : OptionsHolder(std::move(options))
        {
        }
        virtual ~Base() = default;

        auto get_name() const -> std::string const & override
        {
            return OptionsHolder::get_name();
        }
};

class Der1 final : public Base
{
    public:
        explicit Der1(Options options)
          : Base(std::move(options))
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
    ders.push_back(std::make_unique<Der1>(Options{"1"}));
    ders.push_back(std::make_unique<Der1>(Options{"2"}));

    print_names(ders | std::views::transform([](auto const & ca) { return static_cast<Fmt const *>(ca.get()); }));
}
