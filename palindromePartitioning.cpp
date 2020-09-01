#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int x, int y)
{
    for (int i = x, j = y; i < j; i++, j--)
        if (s[i] != s[j])
            return false;
    return true;
} //isPalindrome

int palindromePartitioning(string s, int i, int j)
{
    if (i >= j)
        return 0;
    if (isPalindrome(s, i, j))
        return 0;

    int mn = INT_MAX;
    int temp;
    for (int k = i; k < j; k++)
    {
        temp = palindromePartitioning(s, i, k) + palindromePartitioning(s, k + 1, j) + 1;
        mn = min(mn, temp);
    } //for
    return mn;
} //palindromePartitioning

int t[1001][1001];
int palindromePartitioningTopDown(string s, int i, int j)
{
    if (i >= j)
        return 0;
    if (isPalindrome(s, i, j))
        return 0;

    if (t[i][j] != -1)
        return t[i][j];

    int mn = INT_MAX;
    int temp;
    for (int k = i; k < j; k++)
    {
        temp = palindromePartitioningTopDown(s, i, k) + palindromePartitioningTopDown(s, k + 1, j) + 1;
        mn = min(mn, temp);
    } //for
    return t[i][j] = mn;
} //palindromePartitioningTopDown

int main()
{
    string s;
    cin >> s;
    memset(t, -1, sizeof(t));
    cout << "Minimum Partitions for making Palindrome : "
         //  << palindromePartitioning(s, 0, s.length() - 1) << endl;
         << palindromePartitioningTopDown(s, 0, s.length() - 1) << endl;

    return 0;
} //main