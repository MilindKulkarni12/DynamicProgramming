#include <bits/stdc++.h>
using namespace std;

void stringSubsequences(string s, string output)
{
    if (s.empty())
    {
        cout << output << endl;
        return;
    } //if
    stringSubsequences(s.substr(1), output);
    stringSubsequences(s.substr(1), output + s[0]);
} //stringSubsequences

int main()
{
    string s;
    cin >> s;
    cout << "All Subsequences of a " << s << " : \n";
    stringSubsequences(s, "");
    return 0;
} //main