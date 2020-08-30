#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];
bool seqeuncePatternMatching(string x, string y, int n, int m)
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
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
    return t[n][m] == n ? true : false;
} //seqeuncePatternMatching

int main()
{
    string x, y;
    int n, m;

    cin >> x >> y;
    n = x.length();
    m = y.length();

    if (seqeuncePatternMatching(x, y, n, m))
        cout << "X pattern exists in Y? YES\n";
    else
        cout << "X pattern exists in Y? NO\n";
    return 0;
} //main