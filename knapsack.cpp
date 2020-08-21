#include <bits/stdc++.h>
using namespace std;

int t[101][1001];

//1. Recursive
int knapsackRecursive(vector<int> &weight, vector<int> &value, int W, int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (weight[n - 1] <= W)
        return max(value[n - 1] + knapsackRecursive(weight, value, W - weight[n - 1], n - 1),
                   knapsackRecursive(weight, value, W, n - 1));
    else if (weight[n - 1] > W)
        return knapsackRecursive(weight, value, W, n - 1);
} //knapsackRecursive

//2. DP top down
int knapsackTopDown(vector<int> &weight, vector<int> &value, int W, int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (t[n][W])
        return t[n][W];

    if (weight[n - 1] <= W)
        return t[n][W] = max(value[n - 1] + knapsackTopDown(weight, value, W - weight[n - 1], n - 1),
                             knapsackTopDown(weight, value, W, n - 1));
    else if (weight[n - 1] > W)
        return t[n][W] = knapsackTopDown(weight, value, W, n - 1);
} //knapsackTopDown

//3. iterative DP: bottom up approach
int knapsackIterative(vector<int> weight, vector<int> value, int W, int n)
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= W; j++)
            if (i == 0 || j == 0)
                t[i][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (weight[i - 1] <= j)
                t[i][j] = max(value[i - 1] + t[i - 1][j - weight[i - 1]], t[i - 1][j]);

            if (weight[i - 1] > j)
                t[i][j] = t[i - 1][j];
        } //for
    }     //for
    return t[n][W];
} //knapsackIterative

int main()
{
    int n, W, x;
    vector<int> value;
    vector<int> weight;
    cin >> n >> W;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        weight.push_back(x);
    } //for
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        value.push_back(x);
    } //for

    //memset(t, 0, sizeof(t));
    // cout << "Maximum Profit : " << knapsackRecursive(weight, value, W, n) << endl;
    // cout << "Maximum Profit : " << knapsackTopDown(weight, value, W, n) << endl;
    cout << "Maximum Profit : " << knapsackIterative(weight, value, W, n) << endl;

    return 0;
} //main