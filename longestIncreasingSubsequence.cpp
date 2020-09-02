#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> &nums, int n)
{
    vector<int> arr(n);
    arr[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        arr[i] = 1;
        for (int j = i - 1; j >= 0; --j)
        {
            if (nums[j] > nums[i])
                continue;
            int tempAns = arr[j] + 1;
            arr[i] = max(tempAns, arr[i]);
        } //for
    }     //for
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, arr[i]);

    return ans;
} //lis

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    cout << "Length of Longest Increasing Subsequence : " << lis(nums, n) << endl;
    return 0;
} //main