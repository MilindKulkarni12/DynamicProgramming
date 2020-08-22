#include <bits/stdc++.h>
using namespace std;

bool t[102][1002];
bool equalSumPartitions(vector<int> arr, int sum, int n)
{
    for (int i = 0; i < n + 1; i++)
        t[i][0] = true;
    for (int i = 1; i < sum + 1; i++)
        t[0][i] = false;

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
} //equalSumPartitions

int main()
{
    int n, x;
    int arrSum = 0;
    vector<int> arr;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arrSum += x;
        arr.push_back(x);
    } //for

    if (arrSum % 2 != 0)
        cout << "Equal Sum Partitions can't be made for the given Set (ODD Sum).";
    else if (equalSumPartitions(arr, arrSum / 2, n))
        cout << "Equal Sum Partitions Present!";
    else
        cout << "Equal Sum Partitions can't be made for the given Set.";

    return 0;
} //main