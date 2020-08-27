#include <bits/stdc++.h>
using namespace std;

int t[101][101];

int lcs(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (x[n - 1] == y[m - 1])
        return 1 + lcs(x, y, n - 1, m - 1);
    else
        return max(lcs(x, y, n, m - 1), lcs(x, y, n - 1, m));
} //lcs

int lcsTopDown(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (t[n][m])
        return t[n][m];

    if (x[n - 1] == y[m - 1])
        return t[n][m] = 1 + lcsTopDown(x, y, n - 1, m - 1);
    else
        return t[n][m] = max(lcsTopDown(x, y, n, m - 1), lcsTopDown(x, y, n - 1, m));
} //lcsTopDown

int lcsBottomUp(string x, string y, int n, int m)
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

    return t[n][m];
} //lcsBottomUp

int main()
{
    string x, y;

    cin >> x >> y;
    cout << "Longest Common Subsequence length : "
         // << lcs(x, y, x.size(), y.size());
         //  << lcsTopDown(x, y, x.size(), y.size());
         << lcsBottomUp(x, y, x.size(), y.size());

    return 0;
} //main