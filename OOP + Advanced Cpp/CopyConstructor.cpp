// https://www.youtube.com/watch?v=BvR1Pgzzr38

#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char *m_Buffer; // To store the string. Points to the first char of the string
    int m_Size;

public:
    String(const char *str)
    {
        m_Size = strlen(str);
        m_Buffer = new char[m_Size + 1]; // Allocate space for the provided string. +1 to accomodate null char
        strcpy(m_Buffer, str);
    }

    // By defualt Cpp creates a copy constructor for the class String
    // that is invoked whenever a variable type String is assigned to another variable of type String
    // Ex.
    // String a = "Dhroov";
    // String b = a; // Copy constructor invoked
    // The default copy constructor will do a memcpy, so it will copy char *m_Buffer of a to b.
    // This is not good because it is copying the reference. Ie. m_Buffer of both a and b point to the same object in the heap.
    // This can give unexpected results because any change in the object using b like b[2] = "Z" will cause a change in a as well.
    // (Because both point to the same instance of m_Buffer in the heap)
    // So to fix this, we will construct a copy constructor of our own.
    // Copy constructor takes one argument. Ie. The const reference to the object of the same class
    // https://stackoverflow.com/questions/1272680/what-does-a-colon-following-a-c-constructor-name-do (Member initialization list explanation)
    String(const String &other)
        : m_Size(other.m_Size) // Member initialization. Used to set the value of a member variable
    {
        m_Buffer = new char[m_Size + 1]; // +1 for storing null char
        strcpy(m_Buffer, other.m_Buffer);
    }

    ~String()
    {
        // Since we used new[] to allocate space for the string buffer, we must manually delete it as well
        delete[] m_Buffer;
    }

    // Overloading the [] operator so that we can access a character at an index of the String object using []
    // Note can also use 'auto' when you are not sure about the return type
    // Infact using 'auto' is recommended
    // auto operator[](unsigned int index)

    char &operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

    // Declaring the overloaded operator<< function as friend so that it can access private attribute m_Buffer
    friend ostream &operator<<(ostream &stream, const String &str);
};

// Overloading the insertion operator << so that we can use cout << to print an object of class String.
ostream &operator<<(ostream &stream, const String &str)
{
    stream << str.m_Buffer;
    return stream;
}

int main()
{
    // String *s = new String("Dhroov");
    // cout << *s;
    String s1 = "Dhroov";
    String s2 = s1;
    s2[5] = 'o';
    cout << s1 << endl;
    cout << s2 << endl;
    // O/P
    // Dhroov
    // Dhrooo

    // -------------------------------------------------------------------------------------------------------------

    // If you comment out the copy constructor in String, (ie. use the default copy constructor) the O/P will be,
    // Dhrooo
    // Dhrooo

    // and there will also be a memory leak as we will be deleting the same object twice
    // (since both of them point to the same m_Buffer in the heap --- In case of default copy constructor)
}