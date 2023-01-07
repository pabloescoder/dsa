// https://www.youtube.com/watch?v=I-hZkUa9mIs
#include <iostream>
#include <string>
using namespace std;

// Lets say we are implementing a print function of our own
// We won't do anything fancy, just use the inbuilt cout method, but wrap it in a function
// Now to write a function we need to specify the return type as well as the arguments and their data types.
// But we want our Print function to print int, string, char, float, and so on.
// So we will have to overload the function and basically duplicate the inner code for every data type.
// But as programmers we do not want to repeat code.
// This is where we can use Templates.
// Templates are like Generics in Java, but much more powerful
// It helps us to make a function or class to work for many data types using the same code.
// It serves as a set of instructions to the compiler on how to write the code for us.
template <typename T> // T denotes the entered type, by convention we name it T but it can be named anything.
void Print(T data)
{
    cout << data << endl;
}

// A template is not evaluated. The template code is not parsed and compiled by the compiler UNLESS it is called.
// Ie. Unless the template class or function has been called somewhere, the template class/fn does not get evaluated.
// Once it is called, the placeholder type (T) changes to the actual type and the corresponding code with that type is generated.
// For ex. once we call Print<int>(5); the function will be created and compiled with the argument type as int.
// Similarly if we call Print<float>(5.1f); Print<string>("ABC"); Then separate functions with T replaced with float and string resp. will be generated.

// Templates are not just used for types or functions
// We can create entire classes based on templates. Infact the STL is mostly based on templates.
template <typename T, int N>
class Array
{
private:
    T m_Array[N];

public:
    int getSize()
    {
        return N;
    }
};

int main()
{
    // Note: The Cpp compiler is smart and can also detect the datatype of typename by looking at the argument.
    // So Print<int>(2) can be written simply as Print(2);
    // But I have included the type for verbosity.
    Print<int>(2);
    Print<float>(5.5f);
    Print<string>("Dhroov");

    Array<int, 20> a;
    cout << a.getSize() << endl;
    Array<string, 5> b;
    cout << b.getSize() << endl;
    return 0;
}