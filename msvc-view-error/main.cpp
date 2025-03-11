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
        | std::views::take_while([](auto const & token) { return !token.used; })
        | std::views::filter([](auto const & token)
          {
              if (token.value != "++")
              {
                  return true;
              }
              if (token.value == "++")
              {
                  return false;
              }
              return !token.value.starts_with("+");
          });

    auto transform = view
        | std::views::transform([](auto & token)
          {
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
