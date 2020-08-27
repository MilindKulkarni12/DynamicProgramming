#include <bits/stdc++.h>
using namespace std;

int t[102][1002];
int rodCutting(int n, vector<int> length, vector<int> price)
{
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < n + 1; j++)
            if (i == 0 || j == 0)
                t[i][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (length[i - 1] <= j)
                t[i][j] = max(price[i - 1] + t[i][j - length[i - 1]], t[i - 1][j]);
            else if (length[i - 1] > j)
                t[i][j] = t[i - 1][j];

        } //for
    }     //for
    return t[n][n];
} //rodCutting

int main()
{
    int n, x;
    vector<int> price;
    vector<int> length;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        price.push_back(x);
        length.push_back(i + 1);
    } //for

    cout << "Maximum Profit : " << rodCutting(n, length, price) << endl;
    return 0;
} //main