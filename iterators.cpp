#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{ 1, 2, 3, 4, 5, 5, 6, 7, 8 };

    std::cout << "values:\n";
    std::vector<int>::iterator it = values.begin();
    std::vector<int>::iterator end = values.end();
    while (it != end)
    {
      //Since iterators are more than pointers, dereference pointers to access values
        std::cout << *it << "\n";
        it++;
    }
}
