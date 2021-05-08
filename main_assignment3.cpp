#include <iostream>
#include "Utility.h"
#include "MyAlgorithms.h"
#include <chrono>
#include <fstream>

template<typename F>
void runtime_measurement(std::ofstream& file, F func);


int main()
{
    std::ofstream file("report.csv");

    file << "Vector size , std::find_if, my::find if,, std::adjacent_find, my::adjacent_find,, std::binary_search, my::binary_search";
    file << "\n, time, time , count, time, time, count, time, time, count";
    for (int n = 10000; n <= 1000000; n += 10000)
    {
        std::mt19937 gen{ std::random_device{}() };
        std::uniform_int_distribution<int> range{ 0, 2 * n };

        auto data = generate_data<int>(n, [&gen, &range]()
            {return range(gen); });

        auto value = range(gen);
        file << "\n" << std::size(data) << ", ";
        std::cout << "\n" << std::size(data) << ", ";
        
        //std::find_if
        runtime_measurement(file, std::find_if(std::cbegin(data), std::cend(data), 
            [&value](const int i) {return i == value; }));
        
        //my::find_if
        size_t counter1 = 0;

        runtime_measurement(file, my::find_if(std::cbegin(data), std::cend(data),
            [&counter1, &value](const int i) 
            {
                ++counter1;
                return i == value; 
            }));
        //count
        file << counter1 << ",";

        //sort
        std::sort(std::begin(data), std::end(data));

        //std::adjacent_find
        runtime_measurement(file, std::adjacent_find(std::cbegin(data), std::cend(data)));
        
        //my::adjacent_find
        size_t counter2 = 0;
        runtime_measurement(file, my::adjacent_find(std::cbegin(data), std::cend(data), counter2));
        file << counter2 << ",";

        //std::binary_search
        runtime_measurement(file, std::binary_search(std::cbegin(data), std::cend(data), value));

        //my::binary_search

        size_t counter3 = 0;
        runtime_measurement(file, my::binary_search(std::cbegin(data), std::cend(data), value, counter3));
        file << counter3;

    }
    
    file.close();
}

template<typename F>
void runtime_measurement(std::ofstream& file, F func)
{
    double sum = 0.0;
    size_t comparisons = 0;
    for (int i = 1; i <= 3; i++)
    {
        auto tick = std::chrono::steady_clock::now();
        auto n = func;
        auto tock = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::micro> ms = tock - tick;
        sum += ms.count();
    }

    file << sum / 3 << ", ";
}
