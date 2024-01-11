#include <bits/stdc++.h>
using namespace std;
bool isPalindromic(string s, int st, int e)
{
    while (st < e)
    {
        if (s[st] != s[e])
        {
            return false;
        }
        st++;
        e--;
    }
    return true;
}
int main()

{
    vector<string> v;
    string s;
    cout << "Enter a String : ";
    cin >> s;
    int n = s.size();
    cout << "Following are the Substrings of given String  : " << s << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (isPalindromic(s, i, j))
            {
                string t = s.substr(i, j - i + 1);
                // ans = t.size()>ans.size()?t:ans;
                cout << t<<" ";
            }
        }
    }
    return 0;
}
