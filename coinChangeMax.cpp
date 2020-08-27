#include <bits/stdc++.h>
using namespace std;

int t[102][1002];
int coinChangeMax(vector<int> coins, int sum, int n)
{
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 1;
    for (int j = 1; j < sum + 1; ++j)
        t[0][j] = 0;

    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < sum + 1; ++j)
        {
            if (coins[i - 1] <= j)
                t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        } //for
    }     //for
    return t[n][sum];
} //coinChangeMax

int main()
{
    int n, sum, x;
    vector<int> coins;

    cin >> n >> sum;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        coins.push_back(x);
    } //for

    cout << "Maximum number of ways : " << coinChangeMax(coins, sum, n) << endl;

    return 0;
} //main