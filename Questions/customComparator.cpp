#include <bits/stdc++.h>
using namespace std;
bool comparator(char a,char b)
{
    return a>b;
}
int main()
{
    string s;
    cout<<"Enter a String : ";
    cin>>s;
    sort(s.begin(),s.end(),comparator);//reverse 
    cout<<s;
}

