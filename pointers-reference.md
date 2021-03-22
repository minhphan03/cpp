## This is a self-taught post to teach myself the difference and applications of references and pointers:

Now, let's begin with the most basic. We have the original, value semantics method:

```cpp
#include <iostream>
#include <string>

void passByValue(int parameter)
{
    parameter *= 2;
}

int main()
{
    int a = 5;
    passByValue(a);

    std::cout << "a = " << a << "\n";
}
```

The output is:
> a = 5

a is equal 5 and unchanged because when we pass the value a into the method, the actual value is not passed by, it is a **alias** of the value that is passed to the function. Therefore, the
change is applied to the alias and not the original value, so a will still be 5 after implementing the function

### This is the reference:

```cpp
#include <iostream>
#include <string>

int main()
{
    double a = 3.14;
    double& b = a;

    b += 5;

    std::cout << "a = " << a << "\n";
}
```

The output this time is:
> a = 8.14

What we can see here is that when we add value to b, b -- as a reference -- refer back to a and hence also add value to a. a is equal to b and both a and b points to a specific variable (not only the same value but also the same memory holder)


```cpp
#include <iostream>
#include <string>

void passByReference(int& parameter)
{
    parameter *= 2;
}

int main()
{
    int a = 5;
    passByReference(a);

    std::cout << "a = " << a << "\n";
}
```
Output is:
> a = 10

We have to put an ampersand (&) at the end of the variable type to indicate that we will pass the reference (the exact variable we mentioned in the exact space in the memory) not the copied value of the variable, to the function, so it will modify the variable directly.

When you call the function and pass a as a parameter, the function creates a reference to a called parameter. Now, whatever changes are made to parameter inside of the function body will also be made to the original value a. When we update the reference, the original value will also change according to the reference variable.

**reference variables cannot be NULL**

### This is the pointer method:
```cpp
#include <iostream>

void passByPointer(double* param)
{
    *param = *param + 5;
}

int main()
{
    double value = 3.14;
    passByPointer(&value);

    std::cout << "value = " << value << "\n";
}
```
Output is:
> value = 8.14

The function parameter is a double* name param. This means that the function is expecting to be passed the address of a double variable. Inside of the function body the value of the variable param points to is updated. 

This is done by de-referencing param to get the value 3.14, adding 5 to get 8.14, and then assigning this result back to the variable obtained by de-referencing param which happens to be value from inside of main.

We have to de-reference the param parameter so we can access the value at that memory space to modify it.

When pass the value to a pointer method, **make sure to pass the reference of the variable (&) into the paratheses**
```cpp
#include <iostream>

int main() 
{

    int value = 5;
    int anotherValue = 10;

    int* ptrToValue = &value //create a pointer variable that points to the memory space of the exact value
    ptrToValue = &anotherValue //change this pointer variable to point to another variable
    (*ptrToValue)++; //de-reference this pointer to access the value inside this pointer and increment

    ptrToValue = nullptr;
}
```

it is wrong to assign a pointer with another pointer. Therefore only assign a pointer with a reference of the variable to point exactly where it is.
