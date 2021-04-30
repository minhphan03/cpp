#include <iostream>
#include "Utility.h"
#include "MyAlgorithms.h"

int main()
{
    std::mt19937 gen{ std::random_device{}() };
    std::uniform_int_distribution<int> range{ 0, 100 };
    
    auto data = generate_data<20, std::pair<int, int>>([&gen, &range]()
        { return std::make_pair(range(gen), range(gen));
        });
    
    std::cout << "The list of pairs "<< data << "\n";
    
    //implement min_element_when
    auto min = my::min_element_when(std::cbegin(data), std::cend(data), [](const std::pair<int,int> pair1, std::pair<int,int> pair2)
        {return pair1.first + pair1.second > pair2.first + pair2.second; });

    std::cout << "The smallest pair of integer in this list is " << *min;

    //implement minmax_element
    auto integers = generate_integers<20>();
    std::cout << "\nThe list of integers is\n" << integers;

    auto minmax = my::minmax_element(std::cbegin(integers), std::cend(integers));
    std::cout << "\nThe pair of min and max in this list is " << minmax;
    
    //implement count and count_if
    std::cout << "\nThe number of elements in this list is " << my::count(std::cbegin(integers), std::cend(integers));
    std::cout << "\nThe number of even elements in this list is " << my::count_if(std::cbegin(integers), std::cend(integers), []
    (const int i){return i % 2 == 0; }) << "\n";

    //implement is_sorted
    auto v1 = generate_integers<20>();
    auto v2 = std::vector<int>();
    //v1 is sorted, v2 is not
    std::copy(std::cbegin(v1), std::cend(v1), std::back_inserter(v2));
    std::sort(std::begin(v1), std::end(v1));

    std::cout << "\nThe first list v1 is " << v1 << "The second list v2 is " << v2;

    std::cout << "v1 is sorted: " << std::boolalpha<< my::is_sorted(std::cbegin(v1),std::cend(v1));
    std::cout << "\nv2 is sorted: " << std::boolalpha << my::is_sorted(std::cbegin(v2), std::cend(v2));

    //implement adjacent_find: return the iterator in which the value and adjacent value are the same

    std::cout << "\nThe first adjacent pair of elements in v1 is at position " << std::distance(
        std::cbegin(v1), my::adjacent_find(std::cbegin(v1), std::cend(v1)));
}
