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

    auto transform = view
        | std::views::transform([](auto & token)
          {
              token.used = true;
              return token.value;
          })
        | std::views::common;

    auto strs = std::vector(transform.begin(), transform.end());

    for (auto const & str : strs)
    {
        std::cout << str << ", ";
    }

    return 0;
}
