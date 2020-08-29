#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];
int convertString(string x, string y, int n, int m)
{
    int ans[2];

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

    return t[n][m];
} //convertString

int main()
{
    string x, y;
    int n, m;
    int ans;

    cin >> x >> y;
    n = x.length();
    m = y.length();

    ans = convertString(x, y, n, m);
    cout << "Min. Deletions Required : " << n - ans << endl
         << "Min. Insertions Required : " << m - ans << endl;

    return 0;
} //main