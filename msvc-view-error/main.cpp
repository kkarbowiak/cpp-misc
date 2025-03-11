#include <iostream>
#include <ranges>
#include <string>
#include <vector>


struct Token
{
    std::string value;
    bool used = false;
};

int main()
{
    auto tokens = std::vector{Token{"p1"}, Token{"p2"}, Token{"++"}, Token{"p3"}};

    auto view = tokens
        | std::views::drop_while([](auto const & token) { return token.used; })
        | std::views::take_while([](auto const & token) { return !token.used; });

    auto strs = std::vector<std::string>();
    for (auto& elem : view)
    {
        elem.used = true;
        strs.push_back(elem.value);
    }

    for (auto const & str : strs)
    {
        std::cout << str << ", ";
    }

    return 0;
}
