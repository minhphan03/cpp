See CPP Reference: Random for more information.

The standard library has a powerful set of classes that can be used to generate random numbers and data. In order to create a random number in C++, you need two different objects:

### Random Generator
This is an object which knows how to generate a sequence of pseudo-random bits. Pseudo-random sequences appear random, but are generated using mathematical algorithms. A pseudo-random sequence is always initialized with a seed value. When the same seed is used, the sequence will always be the same. We can get different sequences by ensuring that the seed is always different.

When you initialize a generator object, you need to provide a random seed to the constructor. You can provide any number you want, but if you want a secure sequence, you should use the computer's built-in random device to acquire an initial seed value. You have seen how to access the random device in a previous lesson to get random bits of data.
### Random Distribution
This is an object which understands how to take random bits from a random generator and then map them into a specific range of data. A distribution provides for precise control over the range of random numbers.

Finally, you will need a distribution. The generator provides a sequence of random bits but these are not useable as random numbers. These need to be mapped through a distribution object which will in turn produce random numbers. If you want a uniform distribution of integers in some specific range, you can use the std::uniform_int_distribution template class.

#### Some types of distribution

**std::uniform_int_distribution**

- Returns values of integral type spread uniformly across a range.

**std::uniform_real_distribution**

- Returns values of floating point type spread uniformly across the range.

**std::normal_distribution**
- Returns floating point values distributed according to a gaussian (bell) curve with a mean and a standard deviation.

**std::exponential_distribution**

- Returns floating point values distributed according to an exponential curve with a specified rate of decay.

**std::bernoulli_distribution**

- Returns true or false with a given probability.

Putting all of these elements together here is how to generate a sequence of random integers that are uniformly distributed between 0 and 100:
```cpp
#include <iostream>
#include <random>

int main()
{
    std::mt19937 generator{ std::random_device{}() };
    std::uniform_int_distribution<> distribution{ 0, 100 };

    for (int i = 0; i < 10; i++)
    {
        std::cout << distribution(generator) << ", ";
    }

    std::cout << "\n";
}
```
