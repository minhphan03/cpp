This is a collection of std::string library functions in c++ that I think are useful:

When pass a string into a function, please add an s after the string to indicate that it is a string not a const char array:
```cpp
   auto hello = "Michael"s;
   function("Michael"s);
```

Find method:
```c++
#include <string>
#include <iostream>
 
void print(std::string::size_type n, std::string const &s)
{
    if (n == std::string::npos) {
        std::cout << "not found\n";
    } else {
        std::cout << "found: " << s.substr(n) << '\n';
    }
}
 
int main()
{
    std::string::size_type n;
    std::string const s = "This is a string";
 
    // search from beginning of string
    n = s.find("is");
    print(n, s);
 
    // search from position 5
    n = s.find("is", 5);
    print(n, s);
 
    // find a single character
    n = s.find('a');
    print(n, s);
 
    // find a single character
    n = s.find('q');
    print(n, s);
}
```
