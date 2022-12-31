#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "abcd";

    // Appending characters/strings to the string
    str.append("efgh");
    str += "ijkl";

    for (string::iterator it = str.begin(); it != str.end(); it++)
    {
        if (*it == 'a' || *it == 'b' || *it == 'c' || *it == 'd')
            continue;
        cout << *it << " ";
    }
    cout << '\n';
    cout << str;
}