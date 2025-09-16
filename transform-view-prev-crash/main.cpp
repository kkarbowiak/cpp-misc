#include <memory>
#include <ranges>
#include <vector>


auto loop(std::ranges::view auto ints) -> void
{
    for (auto it = ints.begin(); it != ints.end(); ++it)
    {
        if (it != ints.begin())
        {
            // when working with ranges iterators, make sure to use ranges version of prev, next, etc.
            // (see https://stackoverflow.com/questions/68100775/rangesviewtransform-produces-an-inputiterator-preventing-the-use-of-stdpre)
            (void) std::ranges::prev(it);
        }
    }
}

int main()
{
    std::vector<int> ints;
    ints.push_back(1);
    ints.push_back(2);

    loop(ints | std::views::transform([](auto i) { return i; }));
}
