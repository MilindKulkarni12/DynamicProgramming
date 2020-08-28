#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];
int shortestCommonSupersequence(string x, string y, int n, int m)
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
    return n + m - t[n][m];
} //shortestCommonSupersequence

string getSCS(string x, string y, int n, int m)
{
    string s = "";
    while (n > 0 && m > 0)
    {
        if (x[n - 1] == y[m - 1])
        {
            s = x[n - 1] + s;
            n--;
            m--;
        } //if
        else
        {
            if (t[n - 1][m] > t[n][m - 1])
                s = x[--n] + s;
            else
                s = y[--m] + s;
        } //else
    }     //while

    while (n > 0)
    {
        s = x[n - 1] + s;
        n--;
    } //while

    while (m > 0)
    {
        s = y[m - 1] + s;
        m--;
    } //while

    return s;
} //getSCS

int main()
{
    string x, y;
    int n, m;

    cin >> x >> y;
    n = x.length();
    m = y.length();

    cout << "Shortest Common Subsequence Length : " << shortestCommonSupersequence(x, y, n, m) << endl
         << "Shortest Common Subsequence : " << getSCS(x, y, n, m) << endl;
    return 0;
} //main