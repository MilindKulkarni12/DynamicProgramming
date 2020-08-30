#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];
int lcSubstring(string x, string y, int n, int m)
{
    for (int i = 0; i < n + 1; ++i)
        for (int j = 0; j < m + 1; ++j)
            if (i == 0 || j == 0)
                t[i][j] = 0;

    int mx = INT_MIN;
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < m + 1; ++j)
        {
            if (x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = 0;

            mx = max(mx, t[i][j]);
        } //for
    }     //for
    return mx;
} //lcSubstring

int main()
{
    string x, y;
    cin >> x >> y;
    cout << "Longest common substring length : " << lcSubstring(x, y, x.size(), y.size()) << endl;
    return 0;
} //main