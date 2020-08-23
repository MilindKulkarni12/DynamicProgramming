#include <bits/stdc++.h>
using namespace std;

bool t[102][1002];
int minimumSubsetDiff(vector<int> arr, int sum, int n)
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

    for (int i = n, j = (sum / 2); j >= 0; j--)
        if (t[i][j])
            return sum - (2 * j);
    return sum;
} //minimumSubsetDiff

int main()
{
    int n, x, sum = 0;
    vector<int> arr;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sum += x;
        arr.push_back(x);
    } //for

    cout << "Minimum Subset Difference : " << minimumSubsetDiff(arr, sum, n) << endl;
    return 0;
} //main