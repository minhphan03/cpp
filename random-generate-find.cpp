#pragma once
#include <ostream>
#include <vector>
#include <random>

template<typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> data)
{
    out << "[\n";
    for (const auto& elem : data)
        out << "\t" << elem << ",\n";
    out << "]";
    return out;
}

template<int Size = 10>
std::vector<int> randomIntegers()
{
    std::mt19937 generator{ std::random_device{}() };
    std::uniform_int_distribution<> dist{ 0, 50 };

    std::vector<int> values;
    for (int i = 0; i < Size; i++)
    {
        values.push_back(dist(generator));
    }

    return values;
}

int main()
{
    std::vector<int> values = randomIntegers<10>(); //specify ten values.
    std::cout << values << "\n";

    auto it = std::find(values.cbegin(), values.cend(), 25);
    if (it != values.cend())
    {
        std::cout << "found 25 at position: " << std::distance(values.cbegin(), it) << "\n";
    }
    else
    {
        std::cout << "could not find 25 in the list\n";
    }   
}
