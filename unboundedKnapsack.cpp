#include <bits/stdc++.h>
using namespace std;

int t[102][100002];
int unboundedKnapsack(vector<int> weight, vector<int> value, int W, int n)
{
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < W + 1; j++)
            if (i == 0 || j == 0)
                t[i][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (weight[i - 1] <= j)
                t[i][j] = max(value[i - 1] + t[i][j - weight[i - 1]], t[i - 1][j]);
            else if (weight[i - 1] > j)
                t[i][j] = t[i - 1][j];
        } //for
    }     //for
    return t[n][W];
} //unboundedKnapsack

int main()
{
    int n, W, x;
    vector<int> weight, value;

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

    cout << "Maximum Profit : " << unboundedKnapsack(weight, value, W, n) << endl;

    return 0;
} //main