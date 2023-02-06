#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "abcd";

    // Appending characters/strings to the string
    str.append("efgh");
    str += "ijkl";

    // Traversing using iterator
    for (string::iterator it = str.begin(); it != str.end(); it++)
    {
        if (*it == 'a' || *it == 'b' || *it == 'c' || *it == 'd')
            continue;
        cout << *it << " ";
    }
    cout << '\n';

    // Traversing using index
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'a' || str[i] == 'b' || str[i] == 'c' || str[i] == 'd')
            continue;
        cout << str[i] << " ";
    }
    cout << '\n';

    cout << str;
}