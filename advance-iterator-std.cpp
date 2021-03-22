#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{ 1, 2, 3, 4, 5, 5, 6, 7, 8 };

    std::cout << "values:\n";
    for (auto it = values.cbegin(); it < values.cend(); std::advance(it, 2))
    {
        std::cout << *it << "\n";
    }
}
