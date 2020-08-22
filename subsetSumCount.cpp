#include <bits/stdc++.h>
using namespace std;

int t[102][1002];
int subsetSumCount(vector<int> arr, int sum, int n)
{
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 1;
    for (int j = 1; j < sum + 1; j++)
        t[0][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] > j)
                t[i][j] = t[i - 1][j];
            else if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
        } //for
    }     //for
    return t[n][sum];
} //subsetSumCount
//2 3 5 6 8 10
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

    cout << "Subset Count with given Sum : " << subsetSumCount(arr, sum, n) << endl;
    return 0;
} //main