#include <iostream>
#include <string>
using namespace std;

// T(n) = T(n-1) + T(n-2) + O(1) = O(phi ^ n) where phi is the golden ratio, around 1.618 (Similar to house robber)
// Time Complexity: O(phi^n)
// Space Complexity: O(n)
int ways(const string &str, int i)
{
    int n = str.size();

    if (i == n)
        return 1;
    if (str[i] == '0')
        return 0;

    if (i <= n - 2 && (str[i] == '1' || str[i] == '2' && str[i + 1] <= '6'))
        return ways(str, i + 1) + ways(str, i + 2);
    else
        return ways(str, i + 1);
}

int main()
{
    string str = "512810120129";
    cout << ways(str, 0);
}