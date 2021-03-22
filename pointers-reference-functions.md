Basically, when use a function, we can refer pointers to optional arguments and reference to mandatory arguments

```cpp
#include <iostream>
#include <string>

void printName(std::string& firstName, std::string* middleName, std::string& lastName) 
{
    std::cout<< "Hello, " << firstName << " ";
    if (middleName != nullptr)
    {
        std::cout << *middleName << " ";
    }
    
    std::cout << lastName;
}

int main() {
    std::string firstName = "Minh";
    std::string lastName = "Phan";
    std::string middleName = nullptr;
    
    printName(firstName, &middleName, lastName);
}
