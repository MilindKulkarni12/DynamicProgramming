#include <bits/stdc++.h>
using namespace std;

int mcm(vector<int> &arr, int i, int j)
{
    if (i >= j)
        return 0;

    int mn = INT_MAX;
    int temp;
    for (int k = i; k < j; k++)
    {
        temp = mcm(arr, i, k) + mcm(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        mn = min(temp, mn);
    } //for
    return mn;
} //mcm

int t[1001][1001];
int mcmTopDown(vector<int> &arr, int i, int j)
{
    if (i >= j)
        return 0;

    if (t[i][j] != -1)
        return t[i][j];

    int mn = INT_MAX;
    int temp;
    for (int k = i; k < j; k++)
    {
        temp = mcm(arr, i, k) + mcm(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        mn = min(temp, mn);
    } //for
    return t[i][j] = mn;
} //mcmTopDown

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(t, -1, sizeof(t));
    cout << "Matrix Chain Multiplication Value : "
         // << mcm(arr, 1, n - 1) << endl;
         << mcmTopDown(arr, 1, n - 1) << endl;
    return 0;
}