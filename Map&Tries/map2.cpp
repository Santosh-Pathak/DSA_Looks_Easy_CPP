#include<iostream>
#include<map>
using namespace std;

int main()
{
    string str ="abdefsddfrbbrsbvfd";
    map<char,int>m;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        m[ch]++;
    }

    for (auto i: m)
    {
        cout<<i.first <<" -> "<< i.second<<endl;
    }
}