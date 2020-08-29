#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];
int palindromeConversion(string x, string y, int n, int m)
{
    for (int i = 0; i < n + 1; ++i)
        for (int j = 0; j < m + 1; ++j)
            if (i == 0 || j == 0)
                t[i][j] = 0;
    for (int i = 1; i < n + 1; ++i)
        for (int j = 1; j < m + 1; ++j)
            if (x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
    return n - t[n][m];
} //palindromeConversion

int main()
{
    string x, y;
    cin >> x;
    y = x;
    reverse(y.begin(), y.end());
    int n = x.length();

    cout << "Minimum Deletions Required for Palindrome conversion : "
         << palindromeConversion(x, y, n, n) << endl;
    return 0;
} //main