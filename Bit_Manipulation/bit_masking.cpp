#include<iostream>
using namespace std;

int getithBit(int n ,int i)
{
    int mask = 1 << i;
    int ans = n & mask;
    return ans==0?0:1;
}
void setithBit(int n ,int i)
{   
    int mask = 1 << i; // creat mask
    int ans = n | mask;
    cout<<ans;
    // return ans;
}   
void clearithBit(int n, int i)
{
    int mask = ~(1<<i);
    int ans = n & mask;
    cout<< ans;
}

int main()
{
    // int ans  =  getithBit(10,1);
    // cout<<ans;
    // setithBit(10,2);
    clearithBit(10,1);
}