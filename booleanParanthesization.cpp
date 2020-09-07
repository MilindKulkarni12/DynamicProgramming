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

int t[101][101][2];
int boolParanthesizeMemo(string s, int i, int j, bool isTrue)
{
    int ans = 0;
    if (i > j)
        return 0;

    if (i == j)
        if (isTrue)
            return t[i][j][0] = (s[i] == 'T');
        else
            return t[i][j][1] = (s[i] == 'F');

    if (isTrue)
    {
        if (t[i][j][0] != -1)
            return t[i][j][0];
    } //if
    else
    {
        if (t[i][j][1] != -1)
            return t[i][j][1];
    } //else
    int lt, lf;
    int rt, rf;

    for (int k = i + 1; k < j; k += 2)
    {
        lt = t[i][k - 1][0];
        if (lt == -1)
            lt = t[i][k - 1][0] = boolParanthesizeMemo(s, i, k - 1, true);
        lf = t[i][k - 1][1];
        if (lf == -1)
            lf = t[i][k - 1][1] = boolParanthesizeMemo(s, i, k - 1, false);
        rt = t[k + 1][j][0];
        if (rt == -1)
            rt = t[k + 1][j][0] = boolParanthesizeMemo(s, k + 1, j, true);
        rf = t[k + 1][j][1];
        if (rf == -1)
            rf = t[k + 1][j][1] = boolParanthesizeMemo(s, k + 1, j, false);

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
    if (isTrue)
        return t[i][j][0] = ans;
    return t[i][j][1] = ans;
} //boolParanthesizeMemo

unordered_map<string, int> umap;
int boolParanthesizeMap(string s, int i, int j, bool isTrue)
{
    int ans = 0;
    string key = to_string(i) + "_" + to_string(j) + "_" + to_string(isTrue);
    if (i > j)
        return 0;
    if (i == j)
        if (isTrue)
            return umap[key] = (s[i] == 'T');
        else
            return umap[key] = (s[i] == 'F');

    if (umap.find(key) != umap.end())
        return umap[key];

    string klt, klf, krt, krf;
    int lt, lf, rt, rf;
    for (int k = i + 1; k < j; k += 2)
    {
        klt = to_string(i) + "_" + to_string(k - 1) + "_" + to_string(true);
        klf = to_string(i) + "_" + to_string(k - 1) + "_" + to_string(false);
        krt = to_string(k + 1) + "_" + to_string(j) + "_" + to_string(true);
        krf = to_string(k + 1) + "_" + to_string(j) + "_" + to_string(false);

        if (umap.find(klt) == umap.end())
            lt = boolParanthesizeMap(s, i, k - 1, true);
        if (umap.find(klf) == umap.end())
            lf = boolParanthesizeMap(s, i, k - 1, false);
        if (umap.find(krt) == umap.end())
            rt = boolParanthesizeMap(s, k + 1, j, true);
        if (umap.find(krf) == umap.end())
            rf = boolParanthesizeMap(s, k + 1, j, false);

        lt = umap[klt];
        lf = umap[klf];
        rt = umap[krt];
        rf = umap[krf];

        if (s[k] == '&')
            if (isTrue)
                ans += (lt * rt);
            else
                ans += (lt * rf) + (lf * rt) + (lf * rf);
        if (s[k] == '|')
            if (isTrue)
                ans += (lt * rt) + (lt * rf) + (lf * rt);
            else
                ans += (lf * rf);
        if (s[k] == '^')
            if (isTrue)
                ans += (lt * rf) + (lf * rt);
            else
                ans += (lt * rt) + (lf * rf);
    } //for
    return umap[key] = ans;
} //boolParanthesizeMap

int main()
{
    string s;
    //"T&F&T&T";
    memset(t, -1, sizeof(t));
    cin >> s;
    cout << "Number of ways : "
         << boolParanthesizeMap(s, 0, s.length() - 1, true);
    // << boolParanthesizeMemo(s, 0, s.length() - 1, true);
    // << boolParanthesize(s, 0, s.length() - 1, true);
    return 0;
} //main