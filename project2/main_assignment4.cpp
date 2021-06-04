#include <iostream>
#include "Utility.h"
#include "MyAlgorithms.h"
#include <chrono>
#include <fstream>

template<typename F>
std::chrono::duration<double, std::micro> measurement(F func);


int main()
{ 
    //generate file and background data
    std::ofstream file("report.csv");
    file << "Vector size , my::selection_sort,,, my::insertion_sort,,, my::merge_sort,,, my::quick_sort,,, my::shell_sort,,, std::sort";
    file << "\n, time, swaps, comparisons, time, swaps, comparisons, time, swaps, comparisons, time, swaps, comparisons, time, swaps, comparisons, time\n ";
    
    //project
    for (int n = 1000; n <= 10000; n += 500)
    {
        std::mt19937 gen{ std::random_device{}() };
        std::uniform_int_distribution<int> range{ 0, 2*n };

        //generate original dataset
        auto data = generate_data<int>(n, [&gen, &range]()
            {return range(gen); });
        
        //implement and record stats for my::selection_sort()
        my::stats stat1;
        std::vector<int> data1;
        std::copy(std::begin(data), std::end(data), std::back_inserter(data1));
        auto runtime1 = measurement([&data1, &stat1]()
            {
                my::selection_sort(std::begin(data1), std::end(data1), stat1);
            }
        );

        //implement and record stats for my::insertion_sort()
        my::stats stat2;
        std::vector<int> data2;
        std::copy(std::begin(data), std::end(data), std::back_inserter(data2));
         auto runtime2 = measurement([&data2, &stat2]()
            {
                my::insertion_sort(std::begin(data2), std::end(data2), stat2);
            }
        );
        
         //implement and record stats for my::merge_sort()
        my::stats stat3;
        std::vector<int> data3;
        std::copy(std::begin(data), std::end(data), std::back_inserter(data3));
        auto runtime3 = measurement([&data3, &stat3]()
            {
                my::merge_sort(std::begin(data3), std::end(data3), stat3);
            }
        );

        //implement and record stats for my::quick_sort()
        my::stats stat4;
        std::vector<int> data4;
        std::copy(std::begin(data), std::end(data), std::back_inserter(data4));
        auto runtime4 = measurement([&data4, &stat4]()
            {
                my::quick_sort(std::begin(data4), std::end(data4), stat4);
            }
        );

        //implement and record stats for my::shell_sort()
        my::stats stat5;
        std::vector<int> data5;
        std::copy(std::begin(data), std::end(data), std::back_inserter(data5));
        auto runtime5 = measurement([&data5, &stat5]()
            {
                my::shell_sort(std::begin(data5), std::end(data5), stat5);
            }
        );

        //implement and record stats for std::sort()
        my::stats stat;
        auto runtime = measurement([&data]()
            {
                std::sort(std::begin(data), std::end(data));
            });
        
        std::cout << n << "\n";

        file << n << ","
            << runtime1.count() << ","
            << stat1.swaps << ","
            << stat1.comparisons << ","
            << runtime2.count() << ","
            << stat2.swaps << ","
            << stat2.comparisons << ","
            << runtime3.count() << ","
            << stat3.swaps << ","
            << stat3.comparisons << ","
            << runtime4.count() << ","
            << stat4.swaps << ","
            << stat4.comparisons << ","
            << runtime5.count() << ","
            << stat5.swaps << ","
            << stat5.comparisons << ","
            << runtime.count() << "\n";

    }
    file.close();

}

template<typename F>
std::chrono::duration<double, std::micro> measurement(F func)
{
    auto tick = std::chrono::steady_clock::now();
    func();
    auto tock = std::chrono::steady_clock::now();
    return tock - tick;
    
}
