#include <bits/stdc++.h>
using namespace std;

int boolParanthesize(string s, int i, int j, bool isTrue)
{
    int ans = 0;
    if (i > j)
        return 0;

    if (i == j)
        if (isTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';

    int lt, lf;
    int rt, rf;

    for (int k = i + 1; k < j; k += 2)
    {
        lt = boolParanthesize(s, i, k - 1, true);
        lf = boolParanthesize(s, i, k - 1, false);
        rt = boolParanthesize(s, k + 1, j, true);
        rf = boolParanthesize(s, k + 1, j, false);

        if (s[k] == '&')
            if (isTrue)
                ans += (lt * rt);
            else
                ans += (lf * rt) + (lt * rf) + (lf * rf);
        else if (s[k] == '|')
            if (isTrue)
                ans += (lt * rt) + (lt * rf) + (lf * rt);
            else
                ans += (lf * rf);
        else if (s[k] == '^')
            if (isTrue)
                ans += (lt * rf) + (lf * rt);
            else
                ans += (lt * rt) + (lf * rf);
    } //for
    return ans;
} //boolParanthesize

int main()
{
    string s;
    //"T&F&T&T";
    cin >> s;
    cout << boolParanthesize(s, 0, s.length() - 1, true);
    return 0;
} //main