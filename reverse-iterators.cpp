//constant reverse iterators

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{ 1, 2, 3, 4, 5, 5, 6, 7, 8 };

    for (auto it = values.begin(); it != values.end(); it++)
    {
        *it *= 2;
    }

    std::cout << "values:\n";
    for (auto it = values.crbegin(); it != values.crend(); it++)
    {
        std::cout << *it << "\n";
    }
}
