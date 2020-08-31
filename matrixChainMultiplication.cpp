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

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Matrix Chain Multiplication Value : " << mcm(arr, 1, n - 1) << endl;
    return 0;
}