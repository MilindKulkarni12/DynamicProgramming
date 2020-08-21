#include <bits/stdc++.h>
using namespace std;

bool t[102][1002];

bool subsetSumRecursive(vector<int> arr, int sum, int n)
{
    if (n == 0 && sum == 0)
        return true;
    else if (n == 0)
        return false;
    else if (sum == 0)
        return true;

    if (arr[n - 1] <= sum)
        return subsetSumRecursive(arr, sum - arr[n - 1], n - 1) || subsetSumRecursive(arr, sum, n - 1);
    else if (arr[n - 1] > sum)
        return subsetSumRecursive(arr, sum, n - 1);
} //subsetSumRecursive

bool subsetSumTopDown(vector<int> arr, int sum, int n)
{
    if (n == 0 && sum == 0)
        return true;
    else if (n == 0)
        return false;
    else if (sum == 0)
        return true;

    if (t[n][sum])
        return t[n][sum];
    if (arr[n - 1] > sum)
        return t[n][sum] = subsetSumTopDown(arr, sum, n - 1);
    else if (arr[n - 1] <= sum)
        return t[n][sum] = subsetSumTopDown(arr, sum - arr[n - 1], n - 1) || subsetSumTopDown(arr, sum, n - 1);
} //subsetSumTopDown

bool subsetSumBottomUp(vector<int> arr, int sum, int n)
{
    for (int i = 0; i < n + 1; i++)
        t[i][0] = true;
    for (int j = 1; j < sum + 1; j++)
        t[0][j] = false;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] > j)
                t[i][j] = t[i - 1][j];
            else if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
        } //for
    }     //for
    return t[n][sum];
} //subsetSumBottomUp

int main()
{
    int n, sum, x;
    vector<int> arr;

    cin >> n >> sum;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    } //for

    cout << "Subset with given sum exists? \n- "
         //  << (subsetSumRecursive(arr, sum, n) ? "yes" : "no") << endl;
         //  << (subsetSumTopDown(arr, sum, n) ? "yes" : "no") << endl;
         << (subsetSumBottomUp(arr, sum, n) ? "yes" : "no") << endl;

    return 0;
} //main