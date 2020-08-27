#include <bits/stdc++.h>
using namespace std;

int t[102][1002];
int coinChangeMin(vector<int> &coins, int sum, int n)
{
    for (int i = 1; i < n + 1; ++i)
        t[i][0] = 0;
    for (int j = 0; j < sum + 1; ++j)
        t[0][j] = INT_MAX - 1; //INT_MAX-1 coz if INT_MAX when we'll +1 int will overflow and round up to -ve number.
    for (int j = 1; j < sum + 1; ++j)
        if (j % coins[0] == 0)
            t[1][j] = j / coins[0];
        else
            t[1][j] = INT_MAX - 1;

    for (int i = 2; i < n + 1; ++i)
        for (int j = 1; j < sum + 1; ++j)
            if (coins[i - 1] <= j)
                t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];

    return t[n][sum];
} //coinChangeMin

int main()
{
    int n, sum, x;
    vector<int> coins;

    cin >> n >> sum;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        coins.push_back(x);
    } //for

    cout << "Minimum number of coins : " << coinChangeMin(coins, sum, n) << endl;
    return 0;
} //main